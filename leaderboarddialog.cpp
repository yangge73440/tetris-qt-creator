#include "leaderboarddialog.h"
#include "ui_leaderboarddialog.h"
#include <QHeaderView>

LeaderboardDialog::LeaderboardDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LeaderboardDialog)
    , m_scoreManager(new ScoreManager(this))
{
    ui->setupUi(this);
    setWindowTitle("排行榜");
    setMinimumSize(600, 500);
    
    setupTopScoresTable();
    setupHistoryTable();
    
    refreshData();
}

LeaderboardDialog::~LeaderboardDialog()
{
    delete ui;
}

void LeaderboardDialog::setupTopScoresTable()
{
    ui->topScoresTable->setColumnCount(5);
    ui->topScoresTable->setHorizontalHeaderLabels({"排名", "玩家", "分数", "等级", "消除行数"});
    ui->topScoresTable->horizontalHeader()->setStretchLastSection(true);
    ui->topScoresTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->topScoresTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void LeaderboardDialog::setupHistoryTable()
{
    ui->historyTable->setColumnCount(5);
    ui->historyTable->setHorizontalHeaderLabels({"日期", "玩家", "分数", "等级", "消除行数"});
    ui->historyTable->horizontalHeader()->setStretchLastSection(true);
    ui->historyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->historyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void LeaderboardDialog::refreshData()
{
    // Fill top scores
    QVector<ScoreEntry> topScores = m_scoreManager->getTopScores(10);
    ui->topScoresTable->setRowCount(topScores.size());
    
    for (int i = 0; i < topScores.size(); ++i) {
        const ScoreEntry &entry = topScores[i];
        ui->topScoresTable->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->topScoresTable->setItem(i, 1, new QTableWidgetItem(entry.playerName));
        ui->topScoresTable->setItem(i, 2, new QTableWidgetItem(QString::number(entry.score)));
        ui->topScoresTable->setItem(i, 3, new QTableWidgetItem(QString::number(entry.level)));
        ui->topScoresTable->setItem(i, 4, new QTableWidgetItem(QString::number(entry.linesCleared)));
    }
    
    // Fill history
    QVector<ScoreEntry> history = m_scoreManager->getHistory(50);
    ui->historyTable->setRowCount(history.size());
    
    for (int i = 0; i < history.size(); ++i) {
        const ScoreEntry &entry = history[i];
        ui->historyTable->setItem(i, 0, new QTableWidgetItem(entry.dateTime));
        ui->historyTable->setItem(i, 1, new QTableWidgetItem(entry.playerName));
        ui->historyTable->setItem(i, 2, new QTableWidgetItem(QString::number(entry.score)));
        ui->historyTable->setItem(i, 3, new QTableWidgetItem(QString::number(entry.level)));
        ui->historyTable->setItem(i, 4, new QTableWidgetItem(QString::number(entry.linesCleared)));
    }
}
