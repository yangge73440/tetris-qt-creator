#include "tetrixboard.h"
#include <QLabel>
#include <QPainter>
#include <QKeyEvent>
#include <QSettings>
#include <QTimer>
#include <QRandomGenerator>
#include <cmath>

TetrixBoard::TetrixBoard(QWidget *parent)
    : QFrame(parent)
    , piecesDroppedSinceLastStone(0)
    , clearEffectStage(0)
    , m_consecutiveHits(0)
    , isInShatterAnimation(false)
    , shatterStage(0)
    , shatterType(NoShatter)
    , adventureLevel(1)
    , isEndlessMode(false)
    , currentEnergy(0)
    , maxEnergy(5)
    , monsterHealth(3)
    , maxMonsterHealth(3)
    , targetScore(1000)
    , flashStage(0)
    , monsterInterval(3000)
    , specialBlockInterval(10000)
    , hasSpecialBlock(false)
    , specialBlockX(0)
    , specialBlockY(0)
    , lastScoreMilestone(0)
{
    nextPiece.setRandomShape();
    clearBoard();
    setFocusPolicy(Qt::StrongFocus);
    bgMusic.setAudioOutput(&audioOutput);
    audioOutput.setVolume(0.3);
    bgMusic.setSource(QUrl("qrc:/sounds/tetrix.mp3"));
    bgMusic.setLoops(QMediaPlayer::Infinite);
    removeSound.setSource(QUrl("qrc:/sounds/remove.wav"));
    downSound.setSource(QUrl("qrc:/sounds/down.wav"));
    gameoverSound.setSource(QUrl("qrc:/sounds/gameover.wav"));
    stoneSound.setSource(QUrl("qrc:/sounds/stone.wav"));
    shieldSound.setSource(QUrl("qrc:/sounds/shield.wav"));
    earthquakeSound.setSource(QUrl("qrc:/sounds/earthquake.wav"));
    shatterSound.setSource(QUrl("qrc:/sounds/remove.wav")); // 复用消除音效
    aiPlayer = new AIPlayer(this, difficulty);
    
    shieldTimer = new QTimer(this);
    connect(shieldTimer, &QTimer::timeout, this, [this]() {
        shieldActive = false;
        emit shieldActiveChanged(false);
    });
    
    clearEffectTimer = new QTimer(this);
    connect(clearEffectTimer, &QTimer::timeout, this, [this]() {
        clearEffectStage++;
        if (clearEffectStage > 3) {
            clearEffectStage = 0;
            clearEffectTimer->stop();
            // 真正消除行
            for (int line : clearingLines) {
                for (int y = line; y < BoardHeight - 1; ++y) {
                    for (int x = 0; x < BoardWidth; ++x) {
                        shapeAt(x, y) = shapeAt(x, y + 1);
                    }
                }
                for (int x = 0; x < BoardWidth; ++x) {
                    shapeAt(x, BoardHeight - 1) = NoShape;
                }
            }
            clearingLines.clear();
            update();
        } else {
            update();
        }
    });
    
    m_hitResetTimer = new QTimer(this);
    m_hitResetTimer->setSingleShot(true);
    connect(m_hitResetTimer, &QTimer::timeout, this, [this]() {
        m_consecutiveHits = 0;
    });
    
    shatterTimer = new QTimer(this);
    connect(shatterTimer, &QTimer::timeout, this, &TetrixBoard::updateShatterAnimation);
    
    // 闯关模式计时器
    monsterTimer = new QTimer(this);
    connect(monsterTimer, &QTimer::timeout, this, [this]() {
        if (gameMode == AdventureMode && isStarted && !isPaused) {
            emit monsterAngry();
            // 怪兽发怒：在已下落方块上方随机生成4个石块
            int highestY = -1;
            for (int y = BoardHeight - 1; y >= 0; --y) {
                for (int x = 0; x < BoardWidth; ++x) {
                    if (shapeAt(x, y) != NoShape && shapeAt(x, y) != StoneShape) {
                        highestY = y;
                        goto foundHighestMonster;
                    }
                }
            }
            foundHighestMonster:
            
            // 在最高方块上方至少2行处生成石块，避免与新方块冲突
            int stoneY = (highestY >= 0) ? qMax(highestY - 2, 0) : BoardHeight - 4;
            stoneY = qMin(stoneY, BoardHeight - 1);
            
            QList<int> usedX;
            for (int i = 0; i < 4; ++i) {
                int x;
                do {
                    x = QRandomGenerator::global()->bounded(BoardWidth);
                } while (usedX.contains(x));
                usedX.append(x);
                if (stoneY >= 0 && stoneY < BoardHeight) {
                    shapeAt(x, stoneY) = StoneShape;
                }
            }
            stoneLinesCount += 4;
            emit stoneLinesChanged(stoneLinesCount);
            update();
            
            // 增加下一次掉落的间隔
            monsterInterval += 3000;
            monsterTimer->start(monsterInterval);
        }
    });
    
    // 特殊方块计时器
    specialBlockTimer = new QTimer(this);
    connect(specialBlockTimer, &QTimer::timeout, this, [this]() {
        if (gameMode == AdventureMode && isStarted && !isPaused && !hasSpecialBlock) {
            // 随机生成特殊方块位置
            int x = QRandomGenerator::global()->bounded(BoardWidth);
            int y = QRandomGenerator::global()->bounded(BoardHeight);
            
            // 找一个空位置
            for (int tryCount = 0; tryCount < 50; ++tryCount) {
                x = QRandomGenerator::global()->bounded(BoardWidth);
                y = QRandomGenerator::global()->bounded(BoardHeight / 2, BoardHeight); // 下半部分
                if (shapeAt(x, y) == NoShape) {
                    break;
                }
            }
            
            // 标记特殊方块位置（用额外的方式记录，不占用形状）
            hasSpecialBlock = true;
            specialBlockX = x;
            specialBlockY = y;
            
            // 增加下次出现间隔
            specialBlockInterval += 10000;
            specialBlockTimer->start(specialBlockInterval);
            
            update();
        }
    });
    
    flashTimer = new QTimer(this);
    connect(flashTimer, &QTimer::timeout, this, [this]() {
        flashStage++;
        if (flashStage > 10) {
            flashStage = 0;
            flashTimer->stop();
        }
        update();
    });
}

void TetrixBoard::setNextPieceLabel(QLabel *label)
{
    nextPieceLabel = label;
}

void TetrixBoard::setGameMode(GameMode mode)
{
    gameMode = mode;
}

void TetrixBoard::setDifficulty(int diff)
{
    difficulty = diff;
    if (aiPlayer) {
        aiPlayer->setDifficulty(difficulty);
    }
}

void TetrixBoard::setVolume(int volume)
{
    audioOutput.setVolume(volume / 100.0);
}

void TetrixBoard::showNextPiece()
{
    if (!nextPieceLabel) return;
    int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    int dy = nextPiece.maxY() - nextPiece.minY() + 1;
    QPixmap pixmap(dx * squareWidth(), dy * squareHeight());
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), QColor(232, 221, 203));
    for (int i = 0; i < 4; ++i) {
        int x = nextPiece.x(i) - nextPiece.minX();
        int y = nextPiece.y(i) - nextPiece.minY();
        drawSquare(painter, x * squareWidth(), y * squareHeight(), nextPiece.shape());
    }
    nextPieceLabel->setPixmap(pixmap);
}

void TetrixBoard::newPiece()
{
    curPiece = nextPiece;
    nextPiece.setRandomShape();
    showNextPiece();
    curX = BoardWidth / 2;
    curY = BoardHeight - 1 + curPiece.minY();
    if (!tryMove(curPiece, curX, curY)) {
        timer.stop();
        aiTimer.stop();
        isStarted = false;
        bgMusic.stop();
        gameoverSound.play();
        emit gameOver(score, level, numLinesRemoved);
    } else {
        if (gameMode == AIBattle) {
            int aiInterval = 1000 / (difficulty + 1);
            aiTimer.start(aiInterval, this);
        }
    }
}

void TetrixBoard::start()
{
    if (isPaused) {
        isPaused = false;
        timer.start(timeoutTime(), this);
        bgMusic.play();
        if (gameMode == AIBattle) {
            int aiInterval = 1000 / (difficulty + 1);
            aiTimer.start(aiInterval, this);
        }
        if (gameMode == AdventureMode) {
            monsterTimer->start(monsterInterval); // 使用当前间隔时间
        }
        update();
        return;
    }
    if (isStarted) return;
    isStarted = true;
    bgMusic.play();
    numLinesRemoved = 0;
    numPiecesDropped = 0;
    score = 0;
    level = 1;
    stoneLinesCount = 0;
    shieldActive = false;
    consecutiveClears = 0;
    earthquakeReady = false;
    m_consecutiveHits = 0;
    clearingLines.clear();
    clearEffectStage = 0;
    isInShatterAnimation = false;
    shatterStage = 0;
    shatterType = NoShatter;
    originalBoard.clear();
    shatterPieces.clear();
    shatterTimer->stop();
    piecesDroppedSinceLastStone = 0; // 重置计数器
    
    // 闯关模式初始化
    if (gameMode == AdventureMode) {
        currentEnergy = 0;
        monsterInterval = 3000;
        specialBlockInterval = 10000;
        hasSpecialBlock = false;
        lastScoreMilestone = 0;
        // 计算关卡参数
        if (isEndlessMode) {
            maxMonsterHealth = 10;
            targetScore = 999999;
        } else {
            maxMonsterHealth = 3 + (adventureLevel - 1);
            targetScore = 1000 + (adventureLevel - 1) * 500;
        }
        monsterHealth = maxMonsterHealth;
        emit energyChanged(currentEnergy, maxEnergy);
        emit monsterHealthChanged(monsterHealth, maxMonsterHealth);
        monsterTimer->start(3000); // 3秒发怒一次
        specialBlockTimer->start(10000); // 10秒后首次出现特殊方块
    }
    
    clearBoard();
    emit linesRemovedChanged(numLinesRemoved);
    emit scoreChanged(score);
    emit levelChanged(level);
    emit stoneLinesChanged(stoneLinesCount);
    emit shieldActiveChanged(shieldActive);
    emit earthquakeReadyChanged(earthquakeReady);
    
    newPiece();
    timer.start(timeoutTime(), this);
}

void TetrixBoard::pause()
{
    if (!isStarted) return;
    isPaused = !isPaused;
    if (isPaused) {
        timer.stop();
        aiTimer.stop();
        bgMusic.stop();
    } else {
        timer.start(timeoutTime(), this);
        bgMusic.play();
        if (gameMode == AIBattle) {
            int aiInterval = 1000 / (difficulty + 1);
            aiTimer.start(aiInterval, this);
        }
    }
    update();
}

bool TetrixBoard::tryMove(const TetrixPiece &newPiece, int newX, int newY)
{
    for (int i = 0; i < 4; ++i) {
        int x = newX + newPiece.x(i);
        int y = newY - newPiece.y(i);
        if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)
            return false;
        if (shapeAt(x, y) != NoShape)
            return false;
    }
    curPiece = newPiece;
    curX = newX;
    curY = newY;
    update();
    return true;
}

void TetrixBoard::clearBoard()
{
    for (int i = 0; i < BoardWidth * BoardHeight; ++i)
        boardBBlocks[i] = NoShape;
}

void TetrixBoard::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect = contentsRect();
    
    // 绘制背景图片
    if (!m_bgPixmap.isNull()) {
        painter.drawPixmap(rect, m_bgPixmap, m_bgPixmap.rect());
    }
    
    // 如果在碎裂动画中，绘制特殊效果
    if (isInShatterAnimation) {
        int squareW = squareWidth();
        int squareH = squareHeight();
        
        // 根据碎裂阶段和类型绘制
        for (int i = 0; i < shatterPieces.size(); ++i) {
            QPoint piece = shatterPieces[i];
            int origX = piece.x();
            int origY = piece.y();
            TetrixShape shape = originalBoard[origY * BoardWidth + origX];
            
            if (shape == NoShape) continue;
            
            // 计算偏移
            qreal offsetX = 0, offsetY = 0;
            qreal scale = 1.0;
            qreal alpha = 1.0;
            
            if (shatterType == CollapseShatter) {
                // 聚集碎裂：向中心聚集然后爆炸
                if (shatterStage < 10) {
                    // 聚集阶段
                    qreal t = shatterStage / 10.0;
                    int centerX = BoardWidth / 2;
                    int centerY = BoardHeight / 2;
                    offsetX = (centerX - origX) * squareW * t;
                    offsetY = (centerY - origY) * squareH * t;
                } else if (shatterStage < 30) {
                    // 爆炸阶段
                    qreal t = (shatterStage - 10) / 20.0;
                    scale = 1.0 + t * 0.5;
                    alpha = 1.0 - t;
                    // 随机四散
                    qreal angle = (origX * 37 + origY * 23) * M_PI / 180.0;
                    qreal distance = t * 200.0;
                    offsetX = cos(angle) * distance;
                    offsetY = sin(angle) * distance;
                } else {
                    alpha = 0.0;
                }
            } else if (shatterType == FreezeShatter) {
                // 冻结碎裂：先冻结然后碎裂
                if (shatterStage < 10) {
                    // 冻结阶段
                    alpha = 1.0 - shatterStage * 0.05;
                } else if (shatterStage < 30) {
                    // 碎裂阶段
                    qreal t = (shatterStage - 10) / 20.0;
                    scale = 1.0 - t * 0.5;
                    alpha = 1.0 - t;
                    // 向下掉落
                    offsetY = t * 300.0;
                    offsetX = (origX % 2 == 0 ? -1 : 1) * t * 50.0;
                } else {
                    alpha = 0.0;
                }
            }
            
            if (alpha > 0.01) {
                // 保存 painter 状态
                painter.save();
                
                // 计算绘制位置
                int drawX = rect.left() + origX * squareW + offsetX;
                int drawY = rect.bottom() - (origY + 1) * squareH + offsetY;
                
                // 缩放
                if (scale != 1.0) {
                    QPointF center(drawX + squareW / 2.0, drawY + squareH / 2.0);
                    painter.translate(center);
                    painter.scale(scale, scale);
                    painter.translate(-center);
                }
                
                // 设置透明度
                painter.setOpacity(alpha);
                
                // 绘制方块
                drawSquare(painter, drawX, drawY, shape);
                
                painter.restore();
            }
        }
        return;
    }
    
    // 正常游戏画面
    if (isPaused) {
        painter.drawText(rect, Qt::AlignCenter, "暂停中...");
        return;
    }
    int boardTop = rect.bottom() - BoardHeight * squareHeight();
    for (int i = 0; i < BoardHeight; ++i) {
        for (int j = 0; j < BoardWidth; ++j) {
            TetrixShape shape = shapeAt(j, i);
            if (shape != NoShape) {
                bool isClearing = clearingLines.contains(i);
                if (isClearing) {
                    if (clearEffectStage == 0) {
                        drawSquare(painter, rect.left() + j * squareWidth(), rect.bottom() - (i + 1) * squareHeight(), shape);
                    } else if (clearEffectStage == 1) {
                        drawSquare(painter, rect.left() + j * squareWidth(), rect.bottom() - (i + 1) * squareHeight(), NoShape);
                    } else if (clearEffectStage == 2) {
                        drawSquare(painter, rect.left() + j * squareWidth(), rect.bottom() - (i + 1) * squareHeight(), shape);
                    } else {
                        drawSquare(painter, rect.left() + j * squareWidth(), rect.bottom() - (i + 1) * squareHeight(), NoShape);
                    }
                } else {
                    drawSquare(painter, rect.left() + j * squareWidth(), rect.bottom() - (i + 1) * squareHeight(), shape);
                }
            }
        }
    }
    // 绘制幽灵方块
    if (curPiece.shape() != NoShape && !clearingLines.count()) {
        drawGhostPiece(painter, boardTop);
    }
    if (curPiece.shape() != NoShape) {
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            drawSquare(painter, rect.left() + x * squareWidth(), boardTop + (BoardHeight - y - 1) * squareHeight(), curPiece.shape());
        }
    }
    
    // 绘制护盾效果
    if (shieldActive) {
        painter.setPen(QPen(QColor(0, 255, 0, 150), 3));
        painter.drawRect(rect.adjusted(2, 2, -2, -2));
    }
    
    // 绘制闯关模式闪光动画
    if (gameMode == AdventureMode && flashStage > 0 && flashStage <= 10) {
        qreal alpha = 1.0 - (flashStage / 10.0);
        int flashWidth = 20;
        
        // 左侧闪光
        QLinearGradient leftGradient(rect.left(), 0, rect.left() + flashWidth, 0);
        leftGradient.setColorAt(0, QColor(255, 215, 0, static_cast<int>(alpha * 255)));
        leftGradient.setColorAt(1, QColor(255, 215, 0, 0));
        painter.fillRect(rect.left(), rect.top(), flashWidth, rect.height(), leftGradient);
        
        // 右侧闪光
        QLinearGradient rightGradient(rect.right() - flashWidth, 0, rect.right(), 0);
        rightGradient.setColorAt(0, QColor(255, 215, 0, 0));
        rightGradient.setColorAt(1, QColor(255, 215, 0, static_cast<int>(alpha * 255)));
        painter.fillRect(rect.right() - flashWidth, rect.top(), flashWidth, rect.height(), rightGradient);
    }
    
    // 绘制特殊方块
    if (gameMode == AdventureMode && hasSpecialBlock) {
        int x = rect.left() + specialBlockX * squareWidth();
        int y = boardTop + (BoardHeight - specialBlockY - 1) * squareHeight();
        
        // 绘制特殊方块（金色星星）
        painter.save();
        QFont font;
        font.setPixelSize(squareWidth() * 0.8);
        painter.setFont(font);
        painter.setPen(QColor(255, 215, 0));
        painter.drawText(QRect(x, y, squareWidth(), squareHeight()), Qt::AlignCenter, "⭐");
        painter.restore();
    }
}

int TetrixBoard::calculateGhostY()
{
    int ghostY = curY;
    while (ghostY > 0) {
        bool canMove = true;
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = (ghostY - 1) - curPiece.y(i);
            if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight) {
                canMove = false;
                break;
            }
            if (shapeAt(x, y) != NoShape) {
                canMove = false;
                break;
            }
        }
        if (!canMove) break;
        ghostY--;
    }
    return ghostY;
}

void TetrixBoard::drawGhostPiece(QPainter &painter, int boardTop)
{
    int ghostY = calculateGhostY();
    for (int i = 0; i < 4; ++i) {
        int x = curX + curPiece.x(i);
        int y = ghostY - curPiece.y(i);
        if (y >= 0 && y < BoardHeight && x >= 0 && x < BoardWidth) {
            drawSquare(painter, contentsRect().left() + x * squareWidth(), boardTop + (BoardHeight - y - 1) * squareHeight(), curPiece.shape(), true);
        }
    }
}

void TetrixBoard::drawSquare(QPainter &painter, int x, int y, TetrixShape shape, bool isGhost)
{
    static constexpr QRgb colorTable[9] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00,
        0x808080
    };
    
    QColor color;
    if (isGhost) {
        color = QColor(colorTable[shape]);
        color.setAlpha(80); // 半透明
    } else {
        color = colorTable[shape];
    }
    
    painter.fillRect(x + 1, y + 1, squareWidth() - 2, squareHeight() - 2, color);
    painter.setPen(color.lighter());
    painter.drawLine(x, y, x + squareWidth(), y);
    painter.drawLine(x + squareWidth() - 1, y, x + squareWidth() - 1, y + squareHeight());
    painter.setPen(color.darker());
    painter.drawLine(x + squareWidth(), y + squareHeight() - 1, x, y + squareHeight() - 1);
    painter.drawLine(x, y + squareWidth(), x, y);
}

void TetrixBoard::oneLineDown()
{
    if (!tryMove(curPiece, curX, curY - 1))
        pieceDropped(0);
}

void TetrixBoard::pieceDropped(int dropHeight)
{
    downSound.play();
    aiTimer.stop();
    for (int i = 0; i < 4; ++i) {
        int x = curX + curPiece.x(i);
        int y = curY - curPiece.y(i);
        shapeAt(x, y) = curPiece.shape();
    }
    
    // 检测是否覆盖了特殊方块
    if (gameMode == AdventureMode && hasSpecialBlock) {
        bool covered = false;
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            if (x == specialBlockX && y == specialBlockY) {
                covered = true;
                break;
            }
        }
        if (covered) {
            int random = QRandomGenerator::global()->bounded(2);
            if (random == 0) {
                int areaSize = QRandomGenerator::global()->bounded(3, 6);
                int centerX = QRandomGenerator::global()->bounded(BoardWidth);
                int centerY = QRandomGenerator::global()->bounded(BoardHeight);
                int halfSize = areaSize / 2;
                for (int dy = -halfSize; dy <= halfSize; ++dy) {
                    for (int dx = -halfSize; dx <= halfSize; ++dx) {
                        int x = centerX + dx;
                        int y = centerY + dy;
                        if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
                            if (shapeAt(x, y) != StoneShape) {
                                shapeAt(x, y) = NoShape;
                            }
                        }
                    }
                }
                score += 500;
                emit scoreChanged(score);
            } else {
                QStringList luckyMessages = {"事事如意", "恭喜发财", "方块forever"};
                QString message = luckyMessages[QRandomGenerator::global()->bounded(luckyMessages.size())];
                emit luckyMessage(message);
            }
            hasSpecialBlock = false;
        }
    }
    
    ++numPiecesDropped;
    if (numPiecesDropped % NextLevelNumber == 0) {
        ++level;
        timer.start(timeoutTime(), this);
        emit levelChanged(level);
    }
    score += dropHeight + DropScore;
    emit scoreChanged(score);
    
    // 新功能：石头垃圾行生成逻辑（单人模式和闯关模式不生成）
    if (gameMode != SinglePlayer && gameMode != AdventureMode) {
        piecesDroppedSinceLastStone++;
        if (piecesDroppedSinceLastStone >= 10) {
            // 第11个方块时生成石头垃圾行
            // 找到已下落方块的最高位置（y坐标最大的有方块的行）
            int highestY = -1;
            for (int y = BoardHeight - 1; y >= 0; --y) {
                for (int x = 0; x < BoardWidth; ++x) {
                    if (shapeAt(x, y) != NoShape) {
                        highestY = y;
                        goto foundHighest; // 找到最高的行后直接退出
                    }
                }
            }
            foundHighest:
            
            // 确定石头垃圾行的生成位置
            int stoneLineY;
            if (highestY >= 0) {
                // 有已下落的方块，在其上方（更高的y）生成石头垃圾行
                stoneLineY = highestY + 1;
            } else {
                // 没有已下落的方块，从底部开始生成
                stoneLineY = 0;
            }
            
            // 确保石头垃圾行在有效范围内
            if (stoneLineY >= 0 && stoneLineY < BoardHeight) {
                generateStoneLine(stoneLineY);
                stoneLinesCount++;
                emit stoneLinesChanged(stoneLinesCount);
                
                // 石头行数超过5解锁地震技能
                if (stoneLinesCount >= 5 && !earthquakeReady) {
                    earthquakeReady = true;
                    emit earthquakeReadyChanged(true);
                }
                
                // 播放石头垃圾行音效
                stoneSound.play();
            }
            
            // 重置计数器
            piecesDroppedSinceLastStone = 0;
        }
    }
    
    removeFullLines();
    newPiece();
}

void TetrixBoard::removeFullLines()
{
    QList<int> linesToRemove;
    for (int i = BoardHeight - 1; i >= 0; --i) {
        bool lineIsFull = true;
        bool hasStone = false;
        for (int j = 0; j < BoardWidth; ++j) {
            if (shapeAt(j, i) == NoShape) {
                lineIsFull = false;
                break;
            }
            if (shapeAt(j, i) == StoneShape) {
                hasStone = true;
            }
        }
        // 石头行不能普通消除
        if (lineIsFull && !hasStone) {
            linesToRemove.append(i);
        }
    }
    
    if (linesToRemove.count() > 0) {
        numLinesRemoved += linesToRemove.count();
        score += 10 * linesToRemove.count();
        consecutiveClears++;
        m_consecutiveHits++;
        
        clearingLines = linesToRemove;
        clearEffectStage = 0;
        clearEffectTimer->start(100); // 100ms 一阶段，共 400ms
        removeSound.play();
        
        // 触发 Hit 特效
        QPoint hitPos(rect().center().x(), rect().center().y());
        emit hitEffect(m_consecutiveHits, hitPos);
        m_hitResetTimer->start(2000); // 2秒内没有消除则重置连击
        
        // 如果是连击，显示泡沫特效
        if (m_consecutiveHits > 1) {
            QString bubbleText;
            switch(m_consecutiveHits) {
                case 2: bubbleText = "Double!"; break;
                case 3: bubbleText = "Triple!"; break;
                case 4: bubbleText = "Tetris!"; break;
                default: bubbleText = QString("%1x Combo!").arg(m_consecutiveHits); break;
            }
            emit bubbleEffect(bubbleText, QPoint(rect().center().x(), rect().top() + 50));
        }
        
        // 闯关模式：能量充能和闪光动画
        if (gameMode == AdventureMode) {
            // 每消除一行充1格能量
            currentEnergy = qMin(currentEnergy + linesToRemove.count(), maxEnergy);
            emit energyChanged(currentEnergy, maxEnergy);
            
            // 触发闪光动画
            flashStage = 0;
            flashTimer->start(50);
            emit lineClearedFlash();
            
            // 检查是否达到1000分里程碑
            int currentMilestone = score / 1000;
            if (currentMilestone > lastScoreMilestone) {
                lastScoreMilestone = currentMilestone;
                // 直接充满能量并攻击怪兽
                currentEnergy = maxEnergy;
                emit energyChanged(currentEnergy, maxEnergy);
                
                monsterHealth--;
                currentEnergy = 0;
                emit energyChanged(currentEnergy, maxEnergy);
                emit monsterHealthChanged(monsterHealth, maxMonsterHealth);
                emit monsterHit();
                
                // 检查是否过关
                if (monsterHealth <= 0) {
                    if (!isEndlessMode && score >= targetScore) {
                        // 胜利过关
                        isStarted = false;
                        timer.stop();
                        monsterTimer->stop();
                        emit adventureLevelComplete();
                        return;
                    }
                }
            }
            
            // 能量满了打怪兽
            if (currentEnergy >= maxEnergy) {
                monsterHealth--;
                currentEnergy = 0;
                emit energyChanged(currentEnergy, maxEnergy);
                emit monsterHealthChanged(monsterHealth, maxMonsterHealth);
                emit monsterHit();
                
                // 检查是否过关
                if (monsterHealth <= 0) {
                    if (!isEndlessMode && score >= targetScore) {
                        // 胜利过关
                        isStarted = false;
                        timer.stop();
                        monsterTimer->stop();
                        emit adventureLevelComplete();
                        return;
                    }
                }
            }
        }
        
        // 计算攻击强度
        int attackLines = 0;
        if (linesToRemove.count() == 1) {
            attackLines = 1;
        } else if (linesToRemove.count() == 4) {
            attackLines = 3; // Tetris
        } else {
            attackLines = linesToRemove.count();
        }
        
        // 连续消除额外加一行
        if (consecutiveClears >= 2) {
            attackLines += 1;
        }
        
        // 发送攻击
        if (gameMode == PVPBattle && opponentBoard && attackLines > 0) {
            emit sendAttack(attackLines);
        }
        
        // 连续3次消除触发护盾
        if (consecutiveClears >= 3 && !shieldActive) {
            triggerShield();
        }
        
        emit linesRemovedChanged(numLinesRemoved);
        emit scoreChanged(score);
    } else {
        consecutiveClears = 0;
    }
}

void TetrixBoard::dropDown()
{
    int newY = curY;
    int dropHeight = 0;
    while (newY > 0) {
        if (!tryMove(curPiece, curX, newY - 1))
            break;
        --newY;
        ++dropHeight;
    }
    pieceDropped(dropHeight);
}

void TetrixBoard::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) {
        if (isStarted && !isPaused && !clearingLines.count()) {
            oneLineDown();
        }
    } else if (event->timerId() == aiTimer.timerId()) {
        if (isStarted && !isPaused && gameMode == AIBattle && !clearingLines.count()) {
            aiMove();
        }
    } else {
        QFrame::timerEvent(event);
    }
}

void TetrixBoard::keyPressEvent(QKeyEvent *event)
{
    // 单人模式和闯关模式碎裂快捷键（Q/E）
    if ((gameMode == SinglePlayer || gameMode == AdventureMode) && (event->key() == Qt::Key_Q || event->key() == Qt::Key_E)) {
        // 直接处理这两个键，不受其他条件限制
        if (event->key() == Qt::Key_Q) {
            startFreezeShatter();
        } else {
            startCollapseShatter();
        }
        return;
    }
    
    // 其他情况：正常游戏检查
    if (!isStarted || isPaused || curPiece.shape() == NoShape || clearingLines.count() || isInShatterAnimation) {
        QFrame::keyPressEvent(event);
        return;
    }
    
    // 双人模式按键控制
    if (gameMode == PVPBattle) {
        if (playerType == Player1) {
            switch (event->key()) {
            case Qt::Key_A:
                tryMove(curPiece, curX - 1, curY);
                break;
            case Qt::Key_D:
                tryMove(curPiece, curX + 1, curY);
                break;
            case Qt::Key_S:
                tryMove(curPiece.rotatedRight(), curX, curY);
                break;
            case Qt::Key_W:
                tryMove(curPiece.rotatedLeft(), curX, curY);
                break;
            case Qt::Key_Q:
                oneLineDown();
                break;
            case Qt::Key_E:
                dropDown();
                break;
            case Qt::Key_R:
                useHardShell();
                break;
            case Qt::Key_F:
                useEarthquake();
                break;
            default:
                QFrame::keyPressEvent(event);
            }
        } else { // Player2
            switch (event->key()) {
            case Qt::Key_Left:
                tryMove(curPiece, curX - 1, curY);
                break;
            case Qt::Key_Right:
                tryMove(curPiece, curX + 1, curY);
                break;
            case Qt::Key_Down:
                tryMove(curPiece.rotatedRight(), curX, curY);
                break;
            case Qt::Key_Up:
                tryMove(curPiece.rotatedLeft(), curX, curY);
                break;
            case Qt::Key_Comma: // ,
                oneLineDown();
                break;
            case Qt::Key_Period: // .
                dropDown();
                break;
            case Qt::Key_Slash: // /
                useHardShell();
                break;
            case Qt::Key_Shift:
                useEarthquake();
                break;
            default:
                QFrame::keyPressEvent(event);
            }
        }
        return;
    }
    
    // 单人模式
    switch (event->key()) {
    case Qt::Key_Left:
        tryMove(curPiece, curX - 1, curY);
        break;
    case Qt::Key_Right:
        tryMove(curPiece, curX + 1, curY);
        break;
    case Qt::Key_Down:
        tryMove(curPiece.rotatedRight(), curX, curY);
        break;
    case Qt::Key_Up:
        tryMove(curPiece.rotatedLeft(), curX, curY);
        break;
    case Qt::Key_D:
        oneLineDown();
        break;
    case Qt::Key_Space:
        dropDown();
        break;
    default:
        QFrame::keyPressEvent(event);
    }
}

void TetrixBoard::aiMove()
{
    if (!isStarted || isPaused || curPiece.shape() == NoShape) return;

    int targetX, targetY, rotations;
    aiPlayer->makeMove(curPiece, targetX, targetY, rotations);

    TetrixPiece rotatedPiece = curPiece;
    for (int i = 0; i < rotations; ++i) {
        rotatedPiece = rotatedPiece.rotatedRight();
    }

    if (targetX < curX) {
        tryMove(rotatedPiece, curX - 1, curY);
    } else if (targetX > curX) {
        tryMove(rotatedPiece, curX + 1, curY);
    } else {
        oneLineDown();
    }
}

void TetrixBoard::makeAIMove(int targetX, int targetY, int rotations)
{
    Q_UNUSED(targetY);
    if (!isStarted || isPaused || curPiece.shape() == NoShape) return;

    for (int i = 0; i < rotations; ++i) {
        TetrixPiece rotated = curPiece.rotatedRight();
        tryMove(rotated, curX, curY);
    }

    if (curX < targetX) {
        tryMove(curPiece, curX + 1, curY);
    } else if (curX > targetX) {
        tryMove(curPiece, curX - 1, curY);
    }

    oneLineDown();
}

// 新功能实现
void TetrixBoard::generateStoneLine(int y)
{
    // 随机留1-2个空位
    int emptyCount = QRandomGenerator::global()->bounded(1, 3);
    QList<int> emptyPositions;
    while (emptyPositions.size() < emptyCount) {
        int pos = QRandomGenerator::global()->bounded(BoardWidth);
        if (!emptyPositions.contains(pos)) {
            emptyPositions.append(pos);
        }
    }
    
    for (int x = 0; x < BoardWidth; ++x) {
        if (emptyPositions.contains(x)) {
            shapeAt(x, y) = NoShape;
        } else {
            shapeAt(x, y) = StoneShape;
        }
    }
}

void TetrixBoard::addGarbageLines(int numLines)
{
    if (shieldActive) {
        // 护盾吸收攻击
        return;
    }
    
    stoneSound.play();
    emit screenShake();
    emit showWarning(numLines);
    
    for (int i = 0; i < numLines; ++i) {
        // 将所有方块下移
        for (int y = 0; y < BoardHeight - 1; ++y) {
            for (int x = 0; x < BoardWidth; ++x) {
                shapeAt(x, y) = shapeAt(x, y + 1);
            }
        }
        // 生成新的石头行在最底部
        generateStoneLine(BoardHeight - 1);
    }
    
    stoneLinesCount += numLines;
    emit stoneLinesChanged(stoneLinesCount);
    
    // 石头行数超过5解锁地震技能
    if (stoneLinesCount >= 5 && !earthquakeReady) {
        earthquakeReady = true;
        emit earthquakeReadyChanged(true);
    }
    
    update();
}

void TetrixBoard::useHardShell()
{
    if (shieldActive) return;
    shieldSound.play();
    triggerShield();
}

void TetrixBoard::triggerShield()
{
    shieldActive = true;
    emit shieldActiveChanged(true);
    shieldTimer->start(5000); // 5秒护盾
}

void TetrixBoard::useEarthquake()
{
    if (!earthquakeReady) return;
    earthquakeSound.play();
    emit screenShake();
    
    // 将所有石头行向下震落2层
    for (int i = 0; i < BoardHeight - 2; ++i) {
        for (int j = 0; j < BoardWidth; ++j) {
            if (shapeAt(j, i) == StoneShape) {
                shapeAt(j, i + 2) = StoneShape;
                shapeAt(j, i) = NoShape;
            }
        }
    }
    
    stoneLinesCount = qMax(0, stoneLinesCount - 2);
    earthquakeReady = false;
    emit earthquakeReadyChanged(false);
    emit stoneLinesChanged(stoneLinesCount);
    update();
}

// 聚集碎裂动画 - 点击 E 键
void TetrixBoard::startCollapseShatter()
{
    if (isInShatterAnimation || !isStarted || (gameMode != SinglePlayer && gameMode != AdventureMode)) return;
    if (clearingLines.count() > 0) return; // 防止与消除动画冲突
    
    // 暂停游戏
    timer.stop();
    aiTimer.stop();
    
    // 备份棋盘
    originalBoard.clear();
    shatterPieces.clear();
    for (int i = 0; i < BoardWidth * BoardHeight; ++i) {
        originalBoard.append(boardBBlocks[i]);
        int x = i % BoardWidth;
        int y = i / BoardWidth;
        if (boardBBlocks[i] != NoShape) {
            shatterPieces.append(QPoint(x, y));
        }
    }
    
    // 添加当前方块
    if (curPiece.shape() != NoShape) {
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
                shatterPieces.append(QPoint(x, y));
            }
        }
    }
    
    shatterType = CollapseShatter;
    shatterStage = 0;
    isInShatterAnimation = true;
    shatterSound.play();
    shatterTimer->start(30); // 30ms 每帧
    update();
}

// 冻结碎裂动画 - 点击 Q 键
void TetrixBoard::startFreezeShatter()
{
    if (isInShatterAnimation || !isStarted || (gameMode != SinglePlayer && gameMode != AdventureMode)) return;
    if (clearingLines.count() > 0) return; // 防止与消除动画冲突
    
    // 暂停游戏
    timer.stop();
    aiTimer.stop();
    
    // 备份棋盘
    originalBoard.clear();
    shatterPieces.clear();
    for (int i = 0; i < BoardWidth * BoardHeight; ++i) {
        originalBoard.append(boardBBlocks[i]);
        int x = i % BoardWidth;
        int y = i / BoardWidth;
        if (boardBBlocks[i] != NoShape) {
            shatterPieces.append(QPoint(x, y));
        }
    }
    
    // 添加当前方块
    if (curPiece.shape() != NoShape) {
        for (int i = 0; i < 4; ++i) {
            int x = curX + curPiece.x(i);
            int y = curY - curPiece.y(i);
            if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
                shatterPieces.append(QPoint(x, y));
            }
        }
    }
    
    shatterType = FreezeShatter;
    shatterStage = 0;
    isInShatterAnimation = true;
    shatterSound.play();
    shatterTimer->start(30); // 30ms 每帧
    update();
}

// 更新碎裂动画
void TetrixBoard::updateShatterAnimation()
{
    shatterStage++;
    
    if (shatterStage >= 30) {
        // 动画结束，清理
        shatterTimer->stop();
        isInShatterAnimation = false;
        shatterType = NoShatter;
        
        // 清空整个棋盘（包括石块）
        clearBoard();
        stoneLinesCount = 0;
        emit stoneLinesChanged(stoneLinesCount);
        
        consecutiveClears = 0;
        m_consecutiveHits = 0;
        clearingLines.clear();
        
        // 生成新方块
        newPiece();
        timer.start(timeoutTime(), this);
        
        update();
    } else {
        update();
    }
}
