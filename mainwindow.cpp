#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tetrixboard.h"
#include "mainmenu.h"
#include <QSettings>
#include <QDateTime>
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent, TetrixBoard::GameMode mode, int difficulty)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameMode(mode)
    , difficulty(difficulty)
    , m_scoreManager(new ScoreManager(this))
    , m_hitEffect(new HitEffect(this))
{
    ui->setupUi(this);
    
    ui->frameTetrixBoard->setNextPieceLabel(ui->labelNextPiece);
    ui->frameTetrixBoard->setGameMode(mode);
    ui->frameTetrixBoard->setDifficulty(difficulty);
    connect(ui->pbsStart, &QPushButton::clicked,
            ui->frameTetrixBoard, &TetrixBoard::start);
    connect(ui->pbPause, &QPushButton::clicked,
            ui->frameTetrixBoard, &TetrixBoard::pause);
    connect(ui->frameTetrixBoard, &TetrixBoard::scoreChanged,
            ui->lcgScore, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard, &TetrixBoard::levelChanged,
            ui->lcdLevel, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard, &TetrixBoard::linesRemovedChanged,
            ui->lcdRemoved, qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard, &TetrixBoard::gameOver,
            this, &MainWindow::onGameOver);
    connect(ui->frameTetrixBoard, &TetrixBoard::hitEffect,
            m_hitEffect, &HitEffect::showHit);
    connect(ui->frameTetrixBoard, &TetrixBoard::bubbleEffect,
            m_hitEffect, &HitEffect::showBubble);
    ui->pbsStart->setFocusPolicy(Qt::NoFocus);
    ui->pbPause->setFocusPolicy(Qt::NoFocus);
    ui->pbExit->setFocusPolicy(Qt::NoFocus);

    // 设置 HitEffect 为子窗口
    m_hitEffect->setParent(this);
    m_hitEffect->setGeometry(rect());
    m_hitEffect->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_hitEffect->raise(); // 确保在最上层

    QSettings settings("TetrisGame", "Settings");
    int volume = settings.value("volume", 30).toInt();
    ui->frameTetrixBoard->setVolume(volume);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbPause_clicked()
{
    if (ui->pbPause->text() == QString("暂停"))
        ui->pbPause->setText(QString("继续"));
    else
        ui->pbPause->setText(QString("暂停"));
}

void MainWindow::on_pbExit_clicked()
{
    backToMenu();
}

void MainWindow::backToMenu()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}

void MainWindow::onGameOver(int finalScore, int finalLevel, int linesCleared)
{
    ScoreEntry entry;
    entry.playerName = "Player";
    entry.score = finalScore;
    entry.level = finalLevel;
    entry.linesCleared = linesCleared;
    entry.dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    m_scoreManager->saveScore(entry);
    
    QMessageBox::information(this, "游戏结束", 
        QString("分数: %1\n等级: %2\n消除行数: %3").arg(finalScore).arg(finalLevel).arg(linesCleared));
}
