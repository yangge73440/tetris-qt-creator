#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tetrixboard.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);//无边框，无法移动
    setAttribute(Qt::WA_TranslucentBackground,true);
    ui->frameTetrixBoard->setNextPieceLabel(ui->labelNextPiece);
    connect(ui->pbsStart,& QPushButton::clicked,
        ui->frameTetrixBoard,&TetrixBoard::start);
    connect(ui->pbPause,& QPushButton::clicked,
            ui->frameTetrixBoard,&TetrixBoard::pause);
    connect(ui->frameTetrixBoard,&TetrixBoard::scoreChanged,
            ui->lcgScore,qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard,&TetrixBoard::levelChanged,
            ui->lcdLevel,qOverload<int>(&QLCDNumber::display));
    connect(ui->frameTetrixBoard,&TetrixBoard::linesRemovedChanged,
            ui->lcdRemoved,qOverload<int>(&QLCDNumber::display));
    ui->pbsStart->setFocusPolicy(Qt::NoFocus);
    ui->pbPause->setFocusPolicy(Qt::NoFocus);
    ui->pbExit->setFocusPolicy(Qt::NoFocus);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pbPause_clicked(){
    if(ui->pbPause->text()==QString("暂 停"))
        ui->pbPause->setText(QString("暂 停"));
    else
        ui->pbPause->setText(QString("暂 停"));
}
