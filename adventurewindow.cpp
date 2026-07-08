#include "adventurewindow.h"
#include "mainmenu.h"
#include <QSettings>
#include <QPainter>
#include <QTimer>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFrame>
#include <QPixmap>

AdventureWindow::AdventureWindow(QWidget *parent, int level)
    : QMainWindow(parent)
    , adventureLevel(level)
    , isEndless(level == -1)
    , monsterAnimationFrame(0)
    , monsterIsAngry(false)
    , angryAnimationFrame(0)
{
    setupUI();
    
    // 设置可爱的背景色
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor(255, 240, 245));
    setPalette(pal);
    
    // 设置关卡标签
    if (isEndless) {
        labelLevel->setText("♾️ 无尽模式");
    } else {
        labelLevel->setText(QString("第 %1 关").arg(level));
    }
    
    // 连接信号
    connect(pbStart, &QPushButton::clicked, board, &TetrixBoard::start);
    connect(pbPause, &QPushButton::clicked, board, &TetrixBoard::pause);
    connect(board, &TetrixBoard::scoreChanged, lcdScore, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::levelChanged, lcdLevel, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::linesRemovedChanged, lcdLines, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::gameOver, this, &AdventureWindow::onGameOver);
    connect(board, &TetrixBoard::hitEffect, this, [](int hitCount, const QPoint &pos) {
        Q_UNUSED(hitCount);
        Q_UNUSED(pos);
    });
    connect(board, &TetrixBoard::bubbleEffect, this, [](const QString &text, const QPoint &pos) {
        Q_UNUSED(text);
        Q_UNUSED(pos);
    });
    
    // 闯关模式信号
    connect(board, &TetrixBoard::energyChanged, this, &AdventureWindow::updateEnergy);
    connect(board, &TetrixBoard::monsterHealthChanged, this, &AdventureWindow::updateMonsterHealth);
    connect(board, &TetrixBoard::lineClearedFlash, this, &AdventureWindow::onLineClearedFlash);
    connect(board, &TetrixBoard::monsterAngry, this, &AdventureWindow::onMonsterAngry);
    connect(board, &TetrixBoard::adventureLevelComplete, this, &AdventureWindow::onLevelComplete);
    connect(board, &TetrixBoard::luckyMessage, this, &AdventureWindow::onLuckyMessage);
    connect(board, &TetrixBoard::monsterHit, this, &AdventureWindow::onMonsterHit);
    
    pbStart->setFocusPolicy(Qt::NoFocus);
    pbPause->setFocusPolicy(Qt::NoFocus);
    pbExit->setFocusPolicy(Qt::NoFocus);
    
    // 初始化能量条
    updateEnergy(0, 5);
    updateMonsterHealth(3, 3);
    
    // 怪兽动画计时器
    monsterAnimationTimer = new QTimer(this);
    connect(monsterAnimationTimer, &QTimer::timeout, this, &AdventureWindow::updateMonsterAnimation);
    monsterAnimationTimer->start(100);
    
    QSettings settings("TetrisGame", "Settings");
    int volume = settings.value("volume", 30).toInt();
    board->setVolume(volume);
}

AdventureWindow::~AdventureWindow()
{
}

void AdventureWindow::setupUI()
{
    // 创建中央部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // 创建背景框架
    QFrame *frameBg = new QFrame(this);
    frameBg->setStyleSheet(R"(
        QFrame {
            background-color: rgb(255, 240, 245);
            border: 4px solid rgb(255, 85, 127);
            border-radius: 10px;
        }
    )");
    frameBg->setFrameShape(QFrame::StyledPanel);
    frameBg->setFrameShadow(QFrame::Raised);
    
    QGridLayout *gridLayout = new QGridLayout(frameBg);
    
    // 创建关卡标签
    labelLevel = new QLabel("第 1 关", this);
    labelLevel->setMinimumHeight(40);
    labelLevel->setAlignment(Qt::AlignCenter);
    labelLevel->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelLevel, 0, 0, 1, 4);
    
    // 创建怪兽标签
    labelMonster = new QLabel("👾", this);
    labelMonster->setMinimumHeight(80);
    labelMonster->setAlignment(Qt::AlignCenter);
    labelMonster->setStyleSheet("border: 0; font-size: 48px;");
    gridLayout->addWidget(labelMonster, 1, 0, 1, 4);
    
    // 创建怪兽血量标签
    labelMonsterHealth = new QLabel("❤️❤️❤️", this);
    labelMonsterHealth->setMinimumHeight(30);
    labelMonsterHealth->setAlignment(Qt::AlignCenter);
    labelMonsterHealth->setStyleSheet("border: 0; font-size: 20px;");
    gridLayout->addWidget(labelMonsterHealth, 2, 0, 1, 4);
    
    // 创建能量标签
    labelEnergy = new QLabel("○○○○○", this);
    labelEnergy->setMinimumHeight(30);
    labelEnergy->setAlignment(Qt::AlignCenter);
    labelEnergy->setStyleSheet("border: 0; font-size: 24px;");
    gridLayout->addWidget(labelEnergy, 3, 0, 1, 4);
    
    // 创建幸运话语标签
    labelLuckyMessage = new QLabel("", this);
    labelLuckyMessage->setMinimumHeight(40);
    labelLuckyMessage->setAlignment(Qt::AlignCenter);
    labelLuckyMessage->setStyleSheet("border: 0; font: 700 20pt \"Microsoft YaHei UI\"; color: rgb(255, 215, 0);");
    gridLayout->addWidget(labelLuckyMessage, 4, 0, 1, 4);
    
    // 创建游戏板
    board = new TetrixBoard(this);
    board->setMinimumWidth(300);
    board->setStyleSheet("background-color: rgb(232, 221, 203);");
    board->setFrameShape(QFrame::StyledPanel);
    board->setFrameShadow(QFrame::Raised);
    board->setGameMode(TetrixBoard::AdventureMode);
    board->setAdventureLevel(adventureLevel);
    board->setBackgroundPixmap(QPixmap(":/images/adventure_bg.jpg"));
    gridLayout->addWidget(board, 4, 1, 12, 1);
    
    // 左侧面板
    QLabel *labelNextTitle = new QLabel("下一步", this);
    labelNextTitle->setMinimumWidth(80);
    labelNextTitle->setAlignment(Qt::AlignCenter);
    labelNextTitle->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelNextTitle, 4, 0);
    
    labelNextPiece = new QLabel("下一步", this);
    labelNextPiece->setMinimumSize(80, 100);
    labelNextPiece->setAlignment(Qt::AlignCenter);
    labelNextPiece->setStyleSheet("border: 2px solid rgb(255, 85, 127); border-radius: 10px; background-color: rgb(232, 221, 203);");
    gridLayout->addWidget(labelNextPiece, 5, 0);
    
    QLabel *labelScoreTitle = new QLabel("分数", this);
    labelScoreTitle->setMinimumWidth(80);
    labelScoreTitle->setAlignment(Qt::AlignCenter);
    labelScoreTitle->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelScoreTitle, 6, 0);
    
    lcdScore = new QLCDNumber(this);
    lcdScore->setMinimumSize(80, 50);
    gridLayout->addWidget(lcdScore, 7, 0);
    
    QLabel *labelLevelTitle = new QLabel("速度", this);
    labelLevelTitle->setMinimumWidth(80);
    labelLevelTitle->setAlignment(Qt::AlignCenter);
    labelLevelTitle->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelLevelTitle, 8, 0);
    
    lcdLevel = new QLCDNumber(this);
    lcdLevel->setMinimumSize(80, 50);
    gridLayout->addWidget(lcdLevel, 9, 0);
    
    QLabel *labelLinesTitle = new QLabel("已消除", this);
    labelLinesTitle->setMinimumWidth(80);
    labelLinesTitle->setAlignment(Qt::AlignCenter);
    labelLinesTitle->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelLinesTitle, 10, 0);
    
    lcdLines = new QLCDNumber(this);
    lcdLines->setMinimumSize(80, 50);
    gridLayout->addWidget(lcdLines, 11, 0);
    
    pbStart = new QPushButton("开始", this);
    pbStart->setMinimumHeight(50);
    pbStart->setStyleSheet(R"(
        QPushButton {
            border: 2px solid rgb(255, 85, 127);
            border-radius: 10px;
            background-color: rgb(255, 182, 193);
            font: 700 16pt "Microsoft YaHei UI";
            color: rgb(255, 85, 127);
        }
        QPushButton:hover {
            background-color: rgb(255, 85, 127);
            color: white;
        }
    )");
    gridLayout->addWidget(pbStart, 12, 0);
    
    pbPause = new QPushButton("暂停", this);
    pbPause->setMinimumHeight(50);
    pbPause->setStyleSheet(R"(
        QPushButton {
            border: 2px solid rgb(255, 85, 127);
            border-radius: 10px;
            background-color: rgb(255, 182, 193);
            font: 700 16pt "Microsoft YaHei UI";
            color: rgb(255, 85, 127);
        }
        QPushButton:hover {
            background-color: rgb(255, 85, 127);
            color: white;
        }
    )");
    gridLayout->addWidget(pbPause, 13, 0);
    
    pbExit = new QPushButton("退出", this);
    pbExit->setMinimumHeight(50);
    pbExit->setStyleSheet(R"(
        QPushButton {
            border: 2px solid rgb(255, 85, 127);
            border-radius: 10px;
            background-color: rgb(255, 182, 193);
            font: 700 16pt "Microsoft YaHei UI";
            color: rgb(255, 85, 127);
        }
        QPushButton:hover {
            background-color: rgb(255, 85, 127);
            color: white;
        }
    )");
    gridLayout->addWidget(pbExit, 14, 0);
    
    // 右侧面板
    QLabel *labelInstructionsTitle = new QLabel("操作说明", this);
    labelInstructionsTitle->setMinimumWidth(80);
    labelInstructionsTitle->setAlignment(Qt::AlignCenter);
    labelInstructionsTitle->setStyleSheet("border: 0; font: 700 16pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelInstructionsTitle, 4, 3);
    
    QLabel *labelInstructions = new QLabel("↑：旋转\n↓：下移\n←：左移\n→：右移\n空格：加速下落\nQ：冻结碎裂\nE：聚集碎裂", this);
    labelInstructions->setMinimumSize(80, 200);
    labelInstructions->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
    labelInstructions->setStyleSheet("border: 0; font: 12pt \"Microsoft YaHei UI\"; color: rgb(255, 85, 127);");
    gridLayout->addWidget(labelInstructions, 5, 3);
    
    mainLayout->addWidget(frameBg);
    
    // 设置下一个方块标签
    board->setNextPieceLabel(labelNextPiece);
    
    // 连接按钮
    connect(pbStart, &QPushButton::clicked, this, &AdventureWindow::startGame);
    connect(pbPause, &QPushButton::clicked, this, &AdventureWindow::pauseGame);
    connect(pbExit, &QPushButton::clicked, this, &AdventureWindow::backToMenu);
}

void AdventureWindow::startGame()
{
    board->start();
    board->setFocus();
}

void AdventureWindow::pauseGame()
{
    board->pause();
    if (pbPause->text() == "暂停") {
        pbPause->setText("继续");
    } else {
        pbPause->setText("暂停");
        board->setFocus();
    }
}

void AdventureWindow::backToMenu()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}

void AdventureWindow::onGameOver(int finalScore, int finalLevel, int linesCleared)
{
    QMessageBox::information(this, "游戏结束", 
        QString("分数: %1\n等级: %2\n消除行数: %3").arg(finalScore).arg(finalLevel).arg(linesCleared));
    backToMenu();
}

void AdventureWindow::updateEnergy(int current, int max)
{
    QString energyText;
    for (int i = 0; i < max; ++i) {
        if (i < current) {
            energyText += "⚡";
        } else {
            energyText += "○";
        }
    }
    labelEnergy->setText(energyText);
    labelEnergy->setStyleSheet("border: 0; font-size: 24px; color: #FFD700;");
}

void AdventureWindow::updateMonsterHealth(int current, int max)
{
    QString healthText;
    for (int i = 0; i < max; ++i) {
        if (i < current) {
            healthText += "❤️";
        } else {
            healthText += "🖤";
        }
    }
    labelMonsterHealth->setText(healthText);
    labelMonsterHealth->setStyleSheet("border: 0; font-size: 20px;");
}

void AdventureWindow::onLineClearedFlash()
{
    QPalette originalPal = labelEnergy->palette();
    QPalette flashPal = originalPal;
    flashPal.setColor(QPalette::WindowText, QColor(255, 215, 0));
    labelEnergy->setPalette(flashPal);
    QTimer::singleShot(200, [this, originalPal]() {
        labelEnergy->setPalette(originalPal);
    });
}

void AdventureWindow::onMonsterAngry()
{
    monsterIsAngry = true;
    angryAnimationFrame = 0;
}

void AdventureWindow::onLevelComplete()
{
    if (isEndless) {
        QMessageBox::information(this, "太棒了！", "你在无尽模式中表现出色！继续加油！");
    } else {
        QMessageBox::information(this, "🎉 恭喜过关！", 
            QString("你成功通过了第 %1 关！").arg(adventureLevel));
    }
    backToMenu();
}

void AdventureWindow::onLuckyMessage(const QString &message)
{
    labelLuckyMessage->setText(message);
    QTimer::singleShot(3000, [this]() {
        labelLuckyMessage->setText("");
    });
}

void AdventureWindow::onMonsterHit()
{
    QString originalText = labelMonster->text();
    labelMonster->setText("💥");
    labelMonster->setStyleSheet("border: 0; font-size: 48px; color: red;");
    
    QTimer::singleShot(200, [this, originalText]() {
        labelMonster->setText("😵");
    });
    
    QTimer::singleShot(400, [this, originalText]() {
        labelMonster->setText(originalText);
        labelMonster->setStyleSheet("border: 0; font-size: 48px;");
    });
    
    labelMonsterHealth->setStyleSheet("border: 0; font-size: 20px; color: red;");
    QTimer::singleShot(500, [this]() {
        labelMonsterHealth->setStyleSheet("border: 0; font-size: 20px;");
    });
}

void AdventureWindow::updateMonsterAnimation()
{
    monsterAnimationFrame = (monsterAnimationFrame + 1) % 20;
    if (monsterIsAngry) {
        angryAnimationFrame++;
        if (angryAnimationFrame > 30) {
            monsterIsAngry = false;
            angryAnimationFrame = 0;
        }
        labelMonster->setText("😈");
    } else {
        if (monsterAnimationFrame % 10 < 5) {
            labelMonster->setText("👾");
        } else {
            labelMonster->setText("👹");
        }
    }
}
