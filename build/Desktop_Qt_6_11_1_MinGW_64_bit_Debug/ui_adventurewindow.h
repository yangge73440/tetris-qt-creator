/********************************************************************************
** Form generated from reading UI file 'adventurewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVENTUREWINDOW_H
#define UI_ADVENTUREWINDOW_H

#include <QtCore/QVariant>
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

class Ui_AdventureWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frameBg;
    QGridLayout *gridLayout_2;
    QLabel *labelLevel;
    QLabel *labelMonster;
    QLabel *labelMonsterHealth;
    QLabel *labelEnergy;
    TetrixBoard *frameTetrixBoard;
    QLabel *label;
    QLabel *labelNextPiece;
    QLabel *label_2;
    QLCDNumber *lcdScore;
    QLabel *label_3;
    QLCDNumber *lcdLevel;
    QLabel *label_4;
    QLCDNumber *lcdLines;
    QPushButton *pbStart;
    QPushButton *pbPause;
    QPushButton *pbExit;
    QLabel *label_5;
    QLabel *labelInstructions;

    void setupUi(QMainWindow *AdventureWindow)
    {
        if (AdventureWindow->objectName().isEmpty())
            AdventureWindow->setObjectName("AdventureWindow");
        AdventureWindow->resize(700, 650);
        AdventureWindow->setStyleSheet(QString::fromUtf8("*{\n"
"    border-style:double;\n"
"	border-color: rgb(255, 85, 127);\n"
"    border-width:4px;\n"
"	color: rgb(255, 85, 127);\n"
"    border-radius:10px;\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"    padding:4px;\n"
"}\n"
"QFrame#frameBg{\n"
"	background-color: rgb(255, 240, 245);\n"
"}\n"
"QLabel{\n"
"border-width:0px;\n"
"}\n"
"QLabel#labelNextPiece{\n"
"border-width:2px;\n"
"}\n"
"QFrame#frameTetrixBoard{\n"
"	background-color: rgb(232, 221, 203);\n"
"    padding:0px;\n"
"}\n"
"QPushButton{\n"
"border-width:2px;\n"
"background-color: rgb(255, 182, 193);\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(255, 85, 127);\n"
"color: white;\n"
"}\n"
"QLabel#labelMonster{\n"
"border-width:0px;\n"
"font-size: 48px;\n"
"}"));
        centralwidget = new QWidget(AdventureWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frameBg = new QFrame(centralwidget);
        frameBg->setObjectName("frameBg");
        frameBg->setStyleSheet(QString::fromUtf8(""));
        frameBg->setFrameShape(QFrame::StyledPanel);
        frameBg->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frameBg);
        gridLayout_2->setObjectName("gridLayout_2");
        labelLevel = new QLabel(frameBg);
        labelLevel->setObjectName("labelLevel");
        labelLevel->setMinimumSize(QSize(0, 40));
        labelLevel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelLevel, 0, 0, 1, 4);

        labelMonster = new QLabel(frameBg);
        labelMonster->setObjectName("labelMonster");
        labelMonster->setMinimumSize(QSize(0, 80));
        labelMonster->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelMonster, 1, 0, 1, 4);

        labelMonsterHealth = new QLabel(frameBg);
        labelMonsterHealth->setObjectName("labelMonsterHealth");
        labelMonsterHealth->setMinimumSize(QSize(0, 30));
        labelMonsterHealth->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelMonsterHealth, 2, 0, 1, 4);

        labelEnergy = new QLabel(frameBg);
        labelEnergy->setObjectName("labelEnergy");
        labelEnergy->setMinimumSize(QSize(0, 30));
        labelEnergy->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelEnergy, 3, 0, 1, 4);

        frameTetrixBoard = new TetrixBoard(frameBg);
        frameTetrixBoard->setObjectName("frameTetrixBoard");
        frameTetrixBoard->setMinimumSize(QSize(300, 0));
        frameTetrixBoard->setStyleSheet(QString::fromUtf8(""));
        frameTetrixBoard->setFrameShape(QFrame::StyledPanel);
        frameTetrixBoard->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frameTetrixBoard, 4, 1, 12, 1);

        label = new QLabel(frameBg);
        label->setObjectName("label");
        label->setMinimumSize(QSize(80, 0));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        labelNextPiece = new QLabel(frameBg);
        labelNextPiece->setObjectName("labelNextPiece");
        labelNextPiece->setMinimumSize(QSize(80, 100));
        labelNextPiece->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelNextPiece, 5, 0, 1, 1);

        label_2 = new QLabel(frameBg);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 6, 0, 1, 1);

        lcdScore = new QLCDNumber(frameBg);
        lcdScore->setObjectName("lcdScore");
        lcdScore->setMinimumSize(QSize(80, 50));

        gridLayout_2->addWidget(lcdScore, 7, 0, 1, 1);

        label_3 = new QLabel(frameBg);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 8, 0, 1, 1);

        lcdLevel = new QLCDNumber(frameBg);
        lcdLevel->setObjectName("lcdLevel");
        lcdLevel->setMinimumSize(QSize(80, 50));

        gridLayout_2->addWidget(lcdLevel, 9, 0, 1, 1);

        label_4 = new QLabel(frameBg);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_4, 10, 0, 1, 1);

        lcdLines = new QLCDNumber(frameBg);
        lcdLines->setObjectName("lcdLines");
        lcdLines->setMinimumSize(QSize(80, 50));

        gridLayout_2->addWidget(lcdLines, 11, 0, 1, 1);

        pbStart = new QPushButton(frameBg);
        pbStart->setObjectName("pbStart");
        pbStart->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pbStart, 12, 0, 1, 1);

        pbPause = new QPushButton(frameBg);
        pbPause->setObjectName("pbPause");
        pbPause->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pbPause, 13, 0, 1, 1);

        pbExit = new QPushButton(frameBg);
        pbExit->setObjectName("pbExit");
        pbExit->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pbExit, 14, 0, 1, 1);

        label_5 = new QLabel(frameBg);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 4, 3, 1, 1);

        labelInstructions = new QLabel(frameBg);
        labelInstructions->setObjectName("labelInstructions");
        labelInstructions->setMinimumSize(QSize(80, 200));
        labelInstructions->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(labelInstructions, 5, 3, 1, 1);


        gridLayout->addWidget(frameBg, 0, 0, 1, 1);

        AdventureWindow->setCentralWidget(centralwidget);

        retranslateUi(AdventureWindow);

        QMetaObject::connectSlotsByName(AdventureWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdventureWindow)
    {
        AdventureWindow->setWindowTitle(QCoreApplication::translate("AdventureWindow", "\351\227\257\345\205\263\346\250\241\345\274\217", nullptr));
        labelLevel->setText(QCoreApplication::translate("AdventureWindow", "\347\254\254 1 \345\205\263", nullptr));
        labelMonster->setText(QCoreApplication::translate("AdventureWindow", "\360\237\221\276", nullptr));
        labelMonsterHealth->setText(QCoreApplication::translate("AdventureWindow", "\342\235\244\357\270\217\342\235\244\357\270\217\342\235\244\357\270\217", nullptr));
        labelEnergy->setText(QCoreApplication::translate("AdventureWindow", "\342\227\213\342\227\213\342\227\213\342\227\213\342\227\213", nullptr));
        label->setText(QCoreApplication::translate("AdventureWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        labelNextPiece->setText(QCoreApplication::translate("AdventureWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        label_2->setText(QCoreApplication::translate("AdventureWindow", "\345\210\206\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("AdventureWindow", "\351\200\237\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("AdventureWindow", "\345\267\262\346\266\210\351\231\244", nullptr));
        pbStart->setText(QCoreApplication::translate("AdventureWindow", "\345\274\200\345\247\213", nullptr));
        pbPause->setText(QCoreApplication::translate("AdventureWindow", "\346\232\202\345\201\234", nullptr));
        pbExit->setText(QCoreApplication::translate("AdventureWindow", "\351\200\200\345\207\272", nullptr));
        label_5->setText(QCoreApplication::translate("AdventureWindow", "\346\223\215\344\275\234\350\257\264\346\230\216", nullptr));
        labelInstructions->setText(QCoreApplication::translate("AdventureWindow", "\342\206\221\357\274\232\346\227\213\350\275\254\n"
"\342\206\223\357\274\232\344\270\213\347\247\273\n"
"\342\206\220\357\274\232\345\267\246\347\247\273\n"
"\342\206\222\357\274\232\345\217\263\347\247\273\n"
"\347\251\272\346\240\274\357\274\232\345\212\240\351\200\237\344\270\213\350\220\275\n"
"Q\357\274\232\345\206\273\347\273\223\347\242\216\350\243\202\n"
"E\357\274\232\350\201\232\351\233\206\347\242\216\350\243\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdventureWindow: public Ui_AdventureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVENTUREWINDOW_H
