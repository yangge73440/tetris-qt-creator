#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H

#include <QFrame>
#include <QObject>
#include<QPointer>
#include"tetrixpiece.h"
#include<QBasicTimer>
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QAudioOutput>
class QLabel;
class TetrixBoard : public QFrame
{
    Q_OBJECT
public:
    TetrixBoard(QWidget*parent=nullptr);
    void setNextPieceLabel(QLabel*label);//把需要显示的图片当作label传进来
public slots:
    void start();
    void pause();
signals:
    void levelChanged(int level);
    void scoreChanged(int score);
    void linesRemovedChanged(int numLines);
private:
    enum{
        DropScore=10,BoardWidth=12,BoardHeight=22,NextLevelNumber=20
    };
    int squareWidth(){return contentsRect().width()/BoardWidth;}//总宽度除以格子数得到每个格子的宽度是多少个像素
    int squareHeight(){return contentsRect().height()/BoardHeight;}//每个格子的高度占了多少个像素

    bool tryMove(const TetrixPiece &newPiece,int newX,int newY);
    TetrixShape & shapeAt(int x,int y){
        return boardBBlocks[y*BoardWidth+x];
    }
    void clearBoard();
    void showNextPiece();
    //绘制小块
    void drawSquare(QPainter  &painter,int x,int y,TetrixShape shape);
    void oneLineDown();
    void pieceDropped(int dropHeight);
    int timeoutTime(){    return 1000/(1+level); }
    void removeFullLines();
    void dropDown();
    void newPiece();
private:
    QPointer<QLabel> nextPieceLabel;
    TetrixPiece nextPiece;//根据此对象的内容，把他显示出来
    TetrixPiece curPiece;//正在下落的方块
    int curX;//当前的x坐标
    int curY;//当前的y坐标
    TetrixShape boardBBlocks[BoardWidth*BoardHeight];
    bool isStarted=false;
    bool isPaused=false;
    int numLinesRemoved=0;//消除行数
    int numPiecesDropped=0;
    int score=0;
    int level=1;
    QBasicTimer timer;
    QMediaPlayer bgMusic;
    QAudioOutput audioOutput;
    QSoundEffect removeSound;
    QSoundEffect downSound;
    QSoundEffect gameoverSound;
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // TETRIXBOARD_H
