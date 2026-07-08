/********************************************************************************
** Form generated from reading UI file 'battlewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEWINDOW_H
#define UI_BATTLEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <tetrixboard.h>

QT_BEGIN_NAMESPACE

class Ui_BattleWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *framePlayerBg;
    QGridLayout *gridLayoutPlayer;
    QLabel *labelPlayer;
    QLabel *labelWarning1;
    QPushButton *pbPause;
    QPushButton *pbExit;
    TetrixBoard *frameTetrixBoard;
    QPushButton *pbsStart;
    QLCDNumber *lcdRemoved;
    QLabel *label_4;
    QLCDNumber *lcdLevel;
    QLabel *label_3;
    QLabel *labelNextPiece;
    QLCDNumber *lcgScore;
    QLabel *label_2;
    QFrame *frameAIBg;
    QGridLayout *gridLayoutAI;
    QLabel *labelAI;
    QLabel *labelWarning2;
    TetrixBoard *frameAITetrixBoard;
    QLCDNumber *lcdAIRemoved;
    QLabel *labelAI_4;
    QLCDNumber *lcdAILevel;
    QLabel *labelAI_3;
    QLabel *labelAINextPiece;
    QLCDNumber *lcdAIScore;
    QLabel *labelAI_2;

    void setupUi(QMainWindow *BattleWindow)
    {
        if (BattleWindow->objectName().isEmpty())
            BattleWindow->setObjectName("BattleWindow");
        BattleWindow->resize(1000, 530);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tetrixlcon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        BattleWindow->setWindowIcon(icon);
        BattleWindow->setStyleSheet(QString::fromUtf8("*{\n"
"    border-style:double;\n"
"	border-color: rgb(255, 85, 127);\n"
"    border-width:4px;\n"
"	color: rgb(255, 85, 127);\n"
"    border-radius:10px;\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"    pading:4px;\n"
"}\n"
"QFrame#frameBg{\n"
"	background-color: rgb(232, 221, 203);\n"
"}\n"
"QLabel{\n"
"border-width:0px;\n"
"}\n"
"QLabel#labelNextPiece, QLabel#labelAINextPiece{\n"
"border-width:2px;\n"
"}\n"
"QFrame#frameTetrixBoard, QFrame#frameAITetrixBoard{\n"
"	background-image: url(:/ai_battle_background.jpg);\n"
"    pading:0px;\n"
"}\n"
"QpushButton{\n"
"burder-width:1px;\n"
"}\n"
"QPushButton:hover{\n"
"border-width:1px;\n"
"font:  18pt \"Microsoft YaHei UI\";\n"
"}\n"
"QPushButton:Pressed{\n"
"padding-left:6px;\n"
"padding-top:6px;\n"
"font:  16pt \"Microsoft YaHei UI\";\n"
"}"));
        centralwidget = new QWidget(BattleWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        framePlayerBg = new QFrame(centralwidget);
        framePlayerBg->setObjectName("framePlayerBg");
        framePlayerBg->setStyleSheet(QString::fromUtf8(""));
        framePlayerBg->setFrameShape(QFrame::StyledPanel);
        framePlayerBg->setFrameShadow(QFrame::Raised);
        gridLayoutPlayer = new QGridLayout(framePlayerBg);
        gridLayoutPlayer->setObjectName("gridLayoutPlayer");
        labelPlayer = new QLabel(framePlayerBg);
        labelPlayer->setObjectName("labelPlayer");
        labelPlayer->setMinimumSize(QSize(60, 0));
        labelPlayer->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(labelPlayer, 0, 0, 1, 1);

        labelWarning1 = new QLabel(framePlayerBg);
        labelWarning1->setObjectName("labelWarning1");
        labelWarning1->setMinimumSize(QSize(0, 30));
        labelWarning1->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(labelWarning1, 1, 0, 1, 4);

        pbPause = new QPushButton(framePlayerBg);
        pbPause->setObjectName("pbPause");
        pbPause->setMinimumSize(QSize(0, 60));

        gridLayoutPlayer->addWidget(pbPause, 18, 0, 1, 1);

        pbExit = new QPushButton(framePlayerBg);
        pbExit->setObjectName("pbExit");
        pbExit->setMinimumSize(QSize(0, 60));

        gridLayoutPlayer->addWidget(pbExit, 19, 0, 1, 1);

        frameTetrixBoard = new TetrixBoard(framePlayerBg);
        frameTetrixBoard->setObjectName("frameTetrixBoard");
        frameTetrixBoard->setMinimumSize(QSize(300, 0));
        frameTetrixBoard->setStyleSheet(QString::fromUtf8(""));
        frameTetrixBoard->setFrameShape(QFrame::StyledPanel);
        frameTetrixBoard->setFrameShadow(QFrame::Raised);

        gridLayoutPlayer->addWidget(frameTetrixBoard, 0, 1, 20, 1);

        pbsStart = new QPushButton(framePlayerBg);
        pbsStart->setObjectName("pbsStart");
        pbsStart->setMinimumSize(QSize(0, 60));
        pbsStart->setStyleSheet(QString::fromUtf8(""));

        gridLayoutPlayer->addWidget(pbsStart, 17, 0, 1, 1);

        lcdRemoved = new QLCDNumber(framePlayerBg);
        lcdRemoved->setObjectName("lcdRemoved");
        lcdRemoved->setMinimumSize(QSize(60, 0));

        gridLayoutPlayer->addWidget(lcdRemoved, 19, 3, 1, 1);

        label_4 = new QLabel(framePlayerBg);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(label_4, 18, 3, 1, 1);

        lcdLevel = new QLCDNumber(framePlayerBg);
        lcdLevel->setObjectName("lcdLevel");
        lcdLevel->setMinimumSize(QSize(60, 0));

        gridLayoutPlayer->addWidget(lcdLevel, 17, 3, 1, 1);

        label_3 = new QLabel(framePlayerBg);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(label_3, 11, 3, 1, 1);

        labelNextPiece = new QLabel(framePlayerBg);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setMinimumSize(QSize(60, 100));
        labelNextPiece->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(labelNextPiece, 3, 0, 1, 1);

        lcgScore = new QLCDNumber(framePlayerBg);
        lcgScore->setObjectName("lcgScore");
        lcgScore->setMinimumSize(QSize(60, 60));

        gridLayoutPlayer->addWidget(lcgScore, 10, 3, 1, 1);

        label_2 = new QLabel(framePlayerBg);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayoutPlayer->addWidget(label_2, 4, 3, 1, 1);


        horizontalLayout->addWidget(framePlayerBg);

        frameAIBg = new QFrame(centralwidget);
        frameAIBg->setObjectName("frameAIBg");
        frameAIBg->setStyleSheet(QString::fromUtf8(""));
        frameAIBg->setFrameShape(QFrame::StyledPanel);
        frameAIBg->setFrameShadow(QFrame::Raised);
        gridLayoutAI = new QGridLayout(frameAIBg);
        gridLayoutAI->setObjectName("gridLayoutAI");
        labelAI = new QLabel(frameAIBg);
        labelAI->setObjectName("labelAI");
        labelAI->setMinimumSize(QSize(60, 0));
        labelAI->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelAI, 0, 0, 1, 1);

        labelWarning2 = new QLabel(frameAIBg);
        labelWarning2->setObjectName("labelWarning2");
        labelWarning2->setMinimumSize(QSize(0, 30));
        labelWarning2->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelWarning2, 1, 0, 1, 4);

        frameAITetrixBoard = new TetrixBoard(frameAIBg);
        frameAITetrixBoard->setObjectName("frameAITetrixBoard");
        frameAITetrixBoard->setMinimumSize(QSize(300, 0));
        frameAITetrixBoard->setStyleSheet(QString::fromUtf8(""));
        frameAITetrixBoard->setFrameShape(QFrame::StyledPanel);
        frameAITetrixBoard->setFrameShadow(QFrame::Raised);

        gridLayoutAI->addWidget(frameAITetrixBoard, 0, 1, 20, 1);

        lcdAIRemoved = new QLCDNumber(frameAIBg);
        lcdAIRemoved->setObjectName("lcdAIRemoved");
        lcdAIRemoved->setMinimumSize(QSize(60, 0));

        gridLayoutAI->addWidget(lcdAIRemoved, 19, 3, 1, 1);

        labelAI_4 = new QLabel(frameAIBg);
        labelAI_4->setObjectName("labelAI_4");
        labelAI_4->setMinimumSize(QSize(60, 0));
        labelAI_4->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelAI_4, 18, 3, 1, 1);

        lcdAILevel = new QLCDNumber(frameAIBg);
        lcdAILevel->setObjectName("lcdAILevel");
        lcdAILevel->setMinimumSize(QSize(60, 0));

        gridLayoutAI->addWidget(lcdAILevel, 17, 3, 1, 1);

        labelAI_3 = new QLabel(frameAIBg);
        labelAI_3->setObjectName("labelAI_3");
        labelAI_3->setMinimumSize(QSize(60, 0));
        labelAI_3->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelAI_3, 11, 3, 1, 1);

        labelAINextPiece = new QLabel(frameAIBg);
        labelAINextPiece->setObjectName("labelAINextPiece");
        labelAINextPiece->setMinimumSize(QSize(60, 100));
        labelAINextPiece->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelAINextPiece, 3, 0, 1, 1);

        lcdAIScore = new QLCDNumber(frameAIBg);
        lcdAIScore->setObjectName("lcdAIScore");
        lcdAIScore->setMinimumSize(QSize(60, 60));

        gridLayoutAI->addWidget(lcdAIScore, 10, 3, 1, 1);

        labelAI_2 = new QLabel(frameAIBg);
        labelAI_2->setObjectName("labelAI_2");
        labelAI_2->setMinimumSize(QSize(60, 0));
        labelAI_2->setAlignment(Qt::AlignCenter);

        gridLayoutAI->addWidget(labelAI_2, 4, 3, 1, 1);


        horizontalLayout->addWidget(frameAIBg);

        BattleWindow->setCentralWidget(centralwidget);

        retranslateUi(BattleWindow);
        QObject::connect(pbExit, &QPushButton::clicked, BattleWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(BattleWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BattleWindow)
    {
        BattleWindow->setWindowTitle(QCoreApplication::translate("BattleWindow", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227 - \345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        labelPlayer->setText(QCoreApplication::translate("BattleWindow", "\347\216\251\345\256\266", nullptr));
        labelWarning1->setText(QString());
        pbPause->setText(QCoreApplication::translate("BattleWindow", "\346\232\202\345\201\234", nullptr));
        pbExit->setText(QCoreApplication::translate("BattleWindow", "\351\200\200\345\207\272", nullptr));
        pbsStart->setText(QCoreApplication::translate("BattleWindow", "\345\274\200\345\247\213", nullptr));
        label_4->setText(QCoreApplication::translate("BattleWindow", "\345\267\262\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("BattleWindow", "\351\200\237\345\272\246", nullptr));
        labelNextPiece->setText(QCoreApplication::translate("BattleWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_2->setText(QCoreApplication::translate("BattleWindow", "\345\210\206\346\225\260", nullptr));
        labelAI->setText(QCoreApplication::translate("BattleWindow", "\347\216\251\345\256\2662", nullptr));
        labelWarning2->setText(QString());
        labelAI_4->setText(QCoreApplication::translate("BattleWindow", "\345\267\262\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        labelAI_3->setText(QCoreApplication::translate("BattleWindow", "\351\200\237\345\272\246", nullptr));
        labelAINextPiece->setText(QCoreApplication::translate("BattleWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        labelAI_2->setText(QCoreApplication::translate("BattleWindow", "\345\210\206\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BattleWindow: public Ui_BattleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEWINDOW_H
