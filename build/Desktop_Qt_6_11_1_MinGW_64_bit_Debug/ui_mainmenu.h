/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "jellybutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frameBg;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QSpacerItem *verticalSpacer;
    JellyButton *btnSinglePlayer;
    JellyButton *btnAIBattle;
    JellyButton *btnDoublePlayer;
    JellyButton *btnAdventure;
    JellyButton *btnLeaderboard;
    JellyButton *btnSettings;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(622, 530);
        MainMenu->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-image: url(:/images/mainmenu_background.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: contain;\n"
"}\n"
"QLabel{\n"
"border-width:0px;\n"
"}\n"
""));
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frameBg = new QFrame(centralwidget);
        frameBg->setObjectName("frameBg");
        frameBg->setFrameShape(QFrame::StyledPanel);
        frameBg->setFrameShadow(QFrame::Raised);
        frameBg->setStyleSheet(QString::fromUtf8("QFrame#frameBg {\n"
"    background-color: rgba(255, 255, 240, 0.9);\n"
"    border: 4px solid rgba(222, 184, 135, 0.8);\n"
"    border-radius: 15px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(frameBg);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(frameBg);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);
        labelTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 127);\n"
"text-shadow: 2px 2px 4px rgba(0,0,0,0.3);\n"
""));

        verticalLayout->addWidget(labelTitle);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnSinglePlayer = new JellyButton(frameBg);
        btnSinglePlayer->setObjectName("btnSinglePlayer");
        btnSinglePlayer->setMinimumSize(QSize(200, 60));

        verticalLayout->addWidget(btnSinglePlayer);

        btnAIBattle = new JellyButton(frameBg);
        btnAIBattle->setObjectName("btnAIBattle");
        btnAIBattle->setMinimumSize(QSize(200, 60));

        verticalLayout->addWidget(btnAIBattle);

        btnDoublePlayer = new JellyButton(frameBg);
        btnDoublePlayer->setObjectName("btnDoublePlayer");
        btnDoublePlayer->setMinimumSize(QSize(200, 60));

        verticalLayout->addWidget(btnDoublePlayer);

        btnAdventure = new JellyButton(frameBg);
        btnAdventure->setObjectName("btnAdventure");
        btnAdventure->setMinimumSize(QSize(200, 60));
        btnAdventure->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(btnAdventure);

        btnLeaderboard = new JellyButton(frameBg);
        btnLeaderboard->setObjectName("btnLeaderboard");
        btnLeaderboard->setMinimumSize(QSize(200, 60));

        verticalLayout->addWidget(btnLeaderboard);

        btnSettings = new JellyButton(frameBg);
        btnSettings->setObjectName("btnSettings");
        btnSettings->setMinimumSize(QSize(200, 60));

        verticalLayout->addWidget(btnSettings);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        gridLayout->addWidget(frameBg, 0, 0, 1, 1);

        MainMenu->setCentralWidget(centralwidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227 - \344\270\273\350\217\234\345\215\225", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainMenu", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227", nullptr));
        btnSinglePlayer->setText(QCoreApplication::translate("MainMenu", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        btnAIBattle->setText(QCoreApplication::translate("MainMenu", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        btnDoublePlayer->setText(QCoreApplication::translate("MainMenu", "\345\217\214\344\272\272\345\257\271\346\210\230", nullptr));
        btnAdventure->setText(QCoreApplication::translate("MainMenu", "\360\237\216\256 \351\227\257\345\205\263\346\250\241\345\274\217", nullptr));
        btnLeaderboard->setText(QCoreApplication::translate("MainMenu", "\346\216\222\350\241\214\346\246\234", nullptr));
        btnSettings->setText(QCoreApplication::translate("MainMenu", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
