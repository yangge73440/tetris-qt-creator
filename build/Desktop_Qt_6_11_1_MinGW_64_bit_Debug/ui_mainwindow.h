/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <tetrixboard.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frameBg;
    QGridLayout *gridLayout_2;
    QLabel *label;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(622, 530);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/tetrixlcon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
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
"QLabel#labelNextPiece{\n"
"border-width:2px;\n"
"}\n"
"QFrame#frameTetrixBoard{\n"
"	background-image: url(:/tetrixbackground.jpg);\n"
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(0, 0));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frameBg = new QFrame(centralwidget);
        frameBg->setObjectName("frameBg");
        frameBg->setStyleSheet(QString::fromUtf8(""));
        frameBg->setFrameShape(QFrame::StyledPanel);
        frameBg->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frameBg);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(frameBg);
        label->setObjectName("label");
        label->setMinimumSize(QSize(60, 0));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pbPause = new QPushButton(frameBg);
        pbPause->setObjectName("pbPause");
        pbPause->setMinimumSize(QSize(0, 60));

        gridLayout_2->addWidget(pbPause, 17, 0, 1, 1);

        pbExit = new QPushButton(frameBg);
        pbExit->setObjectName("pbExit");
        pbExit->setMinimumSize(QSize(0, 60));

        gridLayout_2->addWidget(pbExit, 18, 0, 1, 1);

        frameTetrixBoard = new TetrixBoard(frameBg);
        frameTetrixBoard->setObjectName("frameTetrixBoard");
        frameTetrixBoard->setMinimumSize(QSize(300, 0));
        frameTetrixBoard->setStyleSheet(QString::fromUtf8(""));
        frameTetrixBoard->setFrameShape(QFrame::StyledPanel);
        frameTetrixBoard->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frameTetrixBoard, 0, 1, 19, 1);

        pbsStart = new QPushButton(frameBg);
        pbsStart->setObjectName("pbsStart");
        pbsStart->setMinimumSize(QSize(0, 60));
        pbsStart->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(pbsStart, 16, 0, 1, 1);

        lcdRemoved = new QLCDNumber(frameBg);
        lcdRemoved->setObjectName("lcdRemoved");
        lcdRemoved->setMinimumSize(QSize(60, 0));

        gridLayout_2->addWidget(lcdRemoved, 18, 3, 1, 1);

        label_4 = new QLabel(frameBg);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 17, 3, 1, 1);

        lcdLevel = new QLCDNumber(frameBg);
        lcdLevel->setObjectName("lcdLevel");
        lcdLevel->setMinimumSize(QSize(60, 0));

        gridLayout_2->addWidget(lcdLevel, 16, 3, 1, 1);

        label_3 = new QLabel(frameBg);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 10, 3, 1, 1);

        labelNextPiece = new QLabel(frameBg);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setMinimumSize(QSize(60, 100));
        labelNextPiece->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelNextPiece, 2, 0, 1, 1);

        lcgScore = new QLCDNumber(frameBg);
        lcgScore->setObjectName("lcgScore");
        lcgScore->setMinimumSize(QSize(60, 60));

        gridLayout_2->addWidget(lcgScore, 9, 3, 1, 1);

        label_2 = new QLabel(frameBg);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 3, 3, 1, 1);


        gridLayout->addWidget(frameBg, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(pbExit, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        pbPause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        pbExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        pbsStart->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\267\262\346\266\210\351\231\244\350\241\214\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        labelNextPiece->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
