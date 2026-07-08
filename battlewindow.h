#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "tetrixboard.h"
#include "aiplayer.h"
#include "scoremanager.h"
#include "hiteffect.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class BattleWindow;
}
QT_END_NAMESPACE

class BattleWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum BattleMode { AIBattle, PVPDouble };
    BattleWindow(QWidget *parent = nullptr, int difficulty = 1, BattleMode mode = AIBattle);
    ~BattleWindow();

private slots:
    void on_pbPause_clicked();
    void on_pbExit_clicked();
    void backToMenu();
    void onAIMoveTimer();
    void onPlayer1Attack(int lines);
    void onPlayer2Attack(int lines);
    void showWarningForPlayer1(int lines);
    void showWarningForPlayer2(int lines);
    void screenShake();
    void onGameOver(int finalScore, int finalLevel, int linesCleared);

private:
    Ui::BattleWindow *ui;
    AIPlayer *aiPlayer;
    QTimer *aiMoveTimer;
    int difficulty;
    BattleMode battleMode;
    QTimer *warningTimer;
    QTimer *shakeTimer;
    int shakeCount;
    QPoint originalPos;
    ScoreManager *m_scoreManager;
    HitEffect *m_hitEffect1;
    HitEffect *m_hitEffect2;
};

#endif // BATTLEWINDOW_H
