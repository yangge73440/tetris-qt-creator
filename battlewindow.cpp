#include "battlewindow.h"
#include "ui_battlewindow.h"
#include "tetrixboard.h"
#include "mainmenu.h"
#include <QSettings>
#include <QDateTime>
#include <QMessageBox>
#include <QPixmap>

BattleWindow::BattleWindow(QWidget *parent, int difficulty, BattleMode mode)
    : QMainWindow(parent)
    , ui(new Ui::BattleWindow)
    , difficulty(difficulty)
    , battleMode(mode)
    , m_scoreManager(new ScoreManager(this))
    , m_hitEffect1(new HitEffect(this))
    , m_hitEffect2(new HitEffect(this))
{
    ui->setupUi(this);
    
    // 设置游戏框背景图片
    QString bgImage = (battleMode == PVPDouble) ? "pvp_bg.jpg" : "aibattle_bg.jpg";
    ui->frameTetrixBoard->setBackgroundPixmap(QPixmap(":/images/" + bgImage));
    ui->frameAITetrixBoard->setBackgroundPixmap(QPixmap(":/images/" + bgImage));

    // 设置 HitEffect
    m_hitEffect1->setParent(this);
    m_hitEffect1->setGeometry(rect());
    m_hitEffect1->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_hitEffect1->raise();
    
    m_hitEffect2->setParent(this);
    m_hitEffect2->setGeometry(rect());
    m_hitEffect2->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_hitEffect2->raise();

    if (battleMode == PVPDouble) {
        // 双人对战模式
        ui->labelAI->setText("玩家2");
        ui->frameTetrixBoard->setNextPieceLabel(ui->labelNextPiece);
        ui->frameTetrixBoard->setGameMode(TetrixBoard::PVPBattle);
        ui->frameTetrixBoard->setPlayerType(TetrixBoard::Player1);
        ui->frameAITetrixBoard->setNextPieceLabel(ui->labelAINextPiece);
        ui->frameAITetrixBoard->setGameMode(TetrixBoard::PVPBattle);
        ui->frameAITetrixBoard->setPlayerType(TetrixBoard::Player2);
        ui->frameTetrixBoard->setOpponentBoard(ui->frameAITetrixBoard);
        ui->frameAITetrixBoard->setOpponentBoard(ui->frameTetrixBoard);
        
        connect(ui->frameTetrixBoard, &TetrixBoard::hitEffect, m_hitEffect1, &HitEffect::showHit);
        connect(ui->frameTetrixBoard, &TetrixBoard::bubbleEffect, m_hitEffect1, &HitEffect::showBubble);
        connect(ui->frameAITetrixBoard, &TetrixBoard::hitEffect, m_hitEffect2, &HitEffect::showHit);
        connect(ui->frameAITetrixBoard, &TetrixBoard::bubbleEffect, m_hitEffect2, &HitEffect::showBubble);
    } else {
        // 人机对战模式
        ui->labelAI->setText("AI");
        ui->frameTetrixBoard->setNextPieceLabel(ui->labelNextPiece);
        ui->frameTetrixBoard->setGameMode(TetrixBoard::SinglePlayer);
        ui->frameAITetrixBoard->setNextPieceLabel(ui->labelAINextPiece);
        ui->frameAITetrixBoard->setGameMode(TetrixBoard::AIBattle);
        
        aiPlayer = new AIPlayer(ui->frameAITetrixBoard, difficulty);
        aiMoveTimer = new QTimer(this);
        connect(aiMoveTimer, &QTimer::timeout, this, &BattleWindow::onAIMoveTimer);
        connect(ui->pbsStart, &QPushButton::clicked, this, [this, difficulty]() {
            int interval = 200 / difficulty;
            aiMoveTimer->start(interval);
        });
        connect(ui->pbPause, &QPushButton::clicked, this, [this, difficulty]() {
            if (aiMoveTimer->isActive()) {
                aiMoveTimer->stop();
            } else {
                int interval = 200 / difficulty;
                aiMoveTimer->start(interval);
            }
        });
        connect(ui->frameTetrixBoard, &TetrixBoard::hitEffect, m_hitEffect1, &HitEffect::showHit);
        connect(ui->frameTetrixBoard, &TetrixBoard::bubbleEffect, m_hitEffect1, &HitEffect::showBubble);
    }

    connect(ui->pbsStart, &QPushButton::clicked, ui->frameTetrixBoard, &TetrixBoard::start);
    connect(ui->pbsStart, &QPushButton::clicked, ui->frameAITetrixBoard, &TetrixBoard::start);
    connect(ui->pbPause, &QPushButton::clicked, ui->frameTetrixBoard, &TetrixBoard::pause);
    connect(ui->pbPause, &QPushButton::clicked, ui->frameAITetrixBoard, &TetrixBoard::pause);
    connect(ui->frameTetrixBoard, &TetrixBoard::scoreChanged, ui->lcgScore, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard, &TetrixBoard::levelChanged, ui->lcdLevel, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard, &TetrixBoard::linesRemovedChanged, ui->lcdRemoved, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameAITetrixBoard, &TetrixBoard::scoreChanged, ui->lcdAIScore, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameAITetrixBoard, &TetrixBoard::levelChanged, ui->lcdAILevel, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameAITetrixBoard, &TetrixBoard::linesRemovedChanged, ui->lcdAIRemoved, qOverload<int>(&QLCDNumber::display));

    // 连接游戏结束
    connect(ui->frameTetrixBoard, &TetrixBoard::gameOver, this, &BattleWindow::onGameOver);
    connect(ui->frameAITetrixBoard, &TetrixBoard::gameOver, this, &BattleWindow::onGameOver);

    // PVP 攻击连接
    if (battleMode == PVPDouble) {
        connect(ui->frameTetrixBoard, &TetrixBoard::sendAttack, this, &BattleWindow::onPlayer1Attack);
        connect(ui->frameAITetrixBoard, &TetrixBoard::sendAttack, this, &BattleWindow::onPlayer2Attack);
    }

    // 视觉效果
    connect(ui->frameTetrixBoard, &TetrixBoard::showWarning, this, &BattleWindow::showWarningForPlayer1);
    connect(ui->frameAITetrixBoard, &TetrixBoard::showWarning, this, &BattleWindow::showWarningForPlayer2);
    connect(ui->frameTetrixBoard, &TetrixBoard::screenShake, this, &BattleWindow::screenShake);
    connect(ui->frameAITetrixBoard, &TetrixBoard::screenShake, this, &BattleWindow::screenShake);

    ui->pbsStart->setFocusPolicy(Qt::NoFocus);
    ui->pbPause->setFocusPolicy(Qt::NoFocus);
    ui->pbExit->setFocusPolicy(Qt::NoFocus);

    warningTimer = new QTimer(this);
    shakeTimer = new QTimer(this);
    connect(shakeTimer, &QTimer::timeout, this, [this]() {
        if (shakeCount < 6) {
            if (shakeCount % 2 == 0) {
                this->move(originalPos.x() + 5, originalPos.y());
            } else {
                this->move(originalPos.x() - 5, originalPos.y());
            }
            shakeCount++;
        } else {
            this->move(originalPos);
            shakeTimer->stop();
            shakeCount = 0;
        }
    });

    QSettings settings("TetrisGame", "Settings");
    int volume = settings.value("volume", 30).toInt();
    ui->frameTetrixBoard->setVolume(volume);
    ui->frameAITetrixBoard->setVolume(volume);
}

BattleWindow::~BattleWindow()
{
    delete ui;
    if (battleMode == AIBattle) {
        delete aiPlayer;
        delete aiMoveTimer;
    }
}

void BattleWindow::onPlayer1Attack(int lines)
{
    ui->frameAITetrixBoard->addGarbageLines(lines);
}

void BattleWindow::onPlayer2Attack(int lines)
{
    ui->frameTetrixBoard->addGarbageLines(lines);
}

void BattleWindow::showWarningForPlayer1(int lines)
{
    ui->labelWarning1->setText(QString("⚠️ 攻击来临: %1行").arg(lines));
    ui->labelWarning1->setStyleSheet("color: red; font-size: 18px; font-weight: bold;");
    QTimer::singleShot(1000, this, [this]() {
        ui->labelWarning1->clear();
    });
}

void BattleWindow::showWarningForPlayer2(int lines)
{
    ui->labelWarning2->setText(QString("⚠️ 攻击来临: %1行").arg(lines));
    ui->labelWarning2->setStyleSheet("color: red; font-size: 18px; font-weight: bold;");
    QTimer::singleShot(1000, this, [this]() {
        ui->labelWarning2->clear();
    });
}

void BattleWindow::screenShake()
{
    if (!shakeTimer->isActive()) {
        originalPos = this->pos();
        shakeCount = 0;
        shakeTimer->start(50);
    }
}

void BattleWindow::onGameOver(int finalScore, int finalLevel, int linesCleared)
{
    ScoreEntry entry;
    entry.playerName = battleMode == PVPDouble ? "玩家" : "Player";
    entry.score = finalScore;
    entry.level = finalLevel;
    entry.linesCleared = linesCleared;
    entry.dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    m_scoreManager->saveScore(entry);
    
    QMessageBox::information(this, "游戏结束", 
        QString("分数: %1\n等级: %2\n消除行数: %3").arg(finalScore).arg(finalLevel).arg(linesCleared));
}

void BattleWindow::on_pbPause_clicked()
{
    if (ui->pbPause->text() == QString("暂停"))
        ui->pbPause->setText(QString("继续"));
    else
        ui->pbPause->setText(QString("暂停"));
}

void BattleWindow::on_pbExit_clicked()
{
    backToMenu();
}

void BattleWindow::backToMenu()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}

void BattleWindow::onAIMoveTimer()
{
    if (!ui->frameAITetrixBoard->getIsStarted() || ui->frameAITetrixBoard->getIsPaused() || 
        ui->frameAITetrixBoard->getCurrentPiece().shape() == TetrixShape::NoShape) return;

    int targetX, targetY, rotations;
    aiPlayer->makeMove(ui->frameAITetrixBoard->getCurrentPiece(), targetX, targetY, rotations);
    ui->frameAITetrixBoard->makeAIMove(targetX, targetY, rotations);
}
