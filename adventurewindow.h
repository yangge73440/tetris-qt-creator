#ifndef ADVENTUREWINDOW_H
#define ADVENTUREWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include "tetrixboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AdventureWindow; }
QT_END_NAMESPACE

class AdventureWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdventureWindow(QWidget *parent = nullptr, int level = 1);
    ~AdventureWindow();

private slots:
    void startGame();
    void pauseGame();
    void backToMenu();
    void onGameOver(int finalScore, int finalLevel, int linesCleared);
    void updateEnergy(int current, int max);
    void updateMonsterHealth(int current, int max);
    void onLineClearedFlash();
    void onMonsterAngry();
    void onLevelComplete();
    void updateMonsterAnimation();

private slots:
    void onLuckyMessage(const QString &message);
    void onMonsterHit();

private:
    void setupUI();
    
    TetrixBoard *board;
    QLabel *labelNextPiece;
    QLabel *labelLevel;
    QLabel *labelMonster;
    QLabel *labelMonsterHealth;
    QLabel *labelEnergy;
    QLCDNumber *lcdScore;
    QLCDNumber *lcdLevel;
    QLCDNumber *lcdLines;
    QPushButton *pbStart;
    QPushButton *pbPause;
    QPushButton *pbExit;
    QLabel *labelLuckyMessage;
    
    int adventureLevel;
    bool isEndless;
    int monsterAnimationFrame;
    QTimer *monsterAnimationTimer;
    bool monsterIsAngry;
    int angryAnimationFrame;
};

#endif // ADVENTUREWINDOW_H
