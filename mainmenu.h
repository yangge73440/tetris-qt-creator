#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "scoremanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_btnSinglePlayer_clicked();
    void on_btnAIBattle_clicked();
    void on_btnDoublePlayer_clicked();
    void on_btnSettings_clicked();
    void on_btnLeaderboard_clicked();
    void on_btnAdventure_clicked();
    void onLevelSelected(int level);

private:
    Ui::MainMenu *ui;
    ScoreManager *m_scoreManager;
};

#endif // MAINMENU_H
