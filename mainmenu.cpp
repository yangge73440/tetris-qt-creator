#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "settingsdialog.h"
#include "battlewindow.h"
#include "tetrixboard.h"
#include "leaderboarddialog.h"
#include "levelselectdialog.h"
#include "adventurewindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
    , m_scoreManager(new ScoreManager(this))
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_btnSinglePlayer_clicked()
{
    MainWindow *gameWindow = new MainWindow(this, TetrixBoard::SinglePlayer);
    gameWindow->show();
    this->hide();
}

void MainMenu::on_btnAIBattle_clicked()
{
    bool ok;
    QStringList difficulties = {"简单", "中等", "困难"};
    QString difficulty = QInputDialog::getItem(this, "选择难度", "请选择人机对战难度:", difficulties, 0, false, &ok);
    if (ok && !difficulty.isEmpty()) {
        int diffLevel = difficulties.indexOf(difficulty) + 1;
        BattleWindow *battleWindow = new BattleWindow(this, diffLevel, BattleWindow::AIBattle);
        battleWindow->show();
        this->hide();
    }
}

void MainMenu::on_btnSettings_clicked()
{
    SettingsDialog *settings = new SettingsDialog(this);
    settings->exec();
}

void MainMenu::on_btnDoublePlayer_clicked()
{
    // 直接打开双人对战窗口，不需要难度选择
    BattleWindow *battleWindow = new BattleWindow(this, 1, BattleWindow::PVPDouble);
    battleWindow->show();
    this->hide();
}

void MainMenu::on_btnLeaderboard_clicked()
{
    LeaderboardDialog *dialog = new LeaderboardDialog(this);
    dialog->exec();
}

void MainMenu::on_btnAdventure_clicked()
{
    LevelSelectDialog *dialog = new LevelSelectDialog(this);
    connect(dialog, &LevelSelectDialog::levelSelected, this, &MainMenu::onLevelSelected);
    dialog->exec();
}

void MainMenu::onLevelSelected(int level)
{
    AdventureWindow *adventureWindow = new AdventureWindow(this, level);
    adventureWindow->show();
    this->hide();
}
