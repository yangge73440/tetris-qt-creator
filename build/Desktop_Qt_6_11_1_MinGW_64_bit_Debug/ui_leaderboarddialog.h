/********************************************************************************
** Form generated from reading UI file 'leaderboarddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARDDIALOG_H
#define UI_LEADERBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeaderboardDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabTopScores;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *topScoresTable;
    QWidget *tabHistory;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *historyTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *LeaderboardDialog)
    {
        if (LeaderboardDialog->objectName().isEmpty())
            LeaderboardDialog->setObjectName("LeaderboardDialog");
        LeaderboardDialog->resize(600, 500);
        LeaderboardDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: rgb(232, 221, 203);\n"
"}\n"
"QTabWidget::pane {\n"
"    border: 2px solid rgb(255, 85, 127);\n"
"    background-color: rgb(245, 238, 230);\n"
"    border-radius: 5px;\n"
"}\n"
"QTabBar::tab {\n"
"    background: rgb(232, 221, 203);\n"
"    color: rgb(255, 85, 127);\n"
"    padding: 10px;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: rgb(255, 85, 127);\n"
"    color: white;\n"
"}\n"
"QTableWidget {\n"
"    background-color: white;\n"
"    border: 1px solid rgb(255, 85, 127);\n"
"    border-radius: 3px;\n"
"    gridline-color: lightgray;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: rgb(255, 85, 127);\n"
"    color: white;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: rgb(255, 85, 127);\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}"
                        "\n"
"QPushButton {\n"
"    background-color: rgb(255, 85, 127);\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgb(255, 120, 150);\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(220, 60, 100);\n"
"}"));
        verticalLayout = new QVBoxLayout(LeaderboardDialog);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(LeaderboardDialog);
        tabWidget->setObjectName("tabWidget");
        tabTopScores = new QWidget();
        tabTopScores->setObjectName("tabTopScores");
        verticalLayout_2 = new QVBoxLayout(tabTopScores);
        verticalLayout_2->setObjectName("verticalLayout_2");
        topScoresTable = new QTableWidget(tabTopScores);
        topScoresTable->setObjectName("topScoresTable");

        verticalLayout_2->addWidget(topScoresTable);

        tabWidget->addTab(tabTopScores, QString());
        tabHistory = new QWidget();
        tabHistory->setObjectName("tabHistory");
        verticalLayout_3 = new QVBoxLayout(tabHistory);
        verticalLayout_3->setObjectName("verticalLayout_3");
        historyTable = new QTableWidget(tabHistory);
        historyTable->setObjectName("historyTable");

        verticalLayout_3->addWidget(historyTable);

        tabWidget->addTab(tabHistory, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(LeaderboardDialog);
        closeButton->setObjectName("closeButton");

        horizontalLayout->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LeaderboardDialog);
        QObject::connect(closeButton, &QPushButton::clicked, LeaderboardDialog, qOverload<>(&QDialog::accept));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LeaderboardDialog);
    } // setupUi

    void retranslateUi(QDialog *LeaderboardDialog)
    {
        LeaderboardDialog->setWindowTitle(QCoreApplication::translate("LeaderboardDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTopScores), QCoreApplication::translate("LeaderboardDialog", "\346\216\222\350\241\214\346\246\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistory), QCoreApplication::translate("LeaderboardDialog", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        closeButton->setText(QCoreApplication::translate("LeaderboardDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LeaderboardDialog: public Ui_LeaderboardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARDDIALOG_H
