#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tetrixboard.h"
#include "scoremanager.h"
#include "hiteffect.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, TetrixBoard::GameMode mode = TetrixBoard::SinglePlayer, int difficulty = 1);
    ~MainWindow();

private slots:
    void on_pbPause_clicked();
    void on_pbExit_clicked();
    void backToMenu();
    void onGameOver(int finalScore, int finalLevel, int linesCleared);

private:
    Ui::MainWindow *ui;
    TetrixBoard::GameMode gameMode;
    int difficulty;
    ScoreManager *m_scoreManager;
    HitEffect *m_hitEffect;
};
#endif // MAINWINDOW_H
