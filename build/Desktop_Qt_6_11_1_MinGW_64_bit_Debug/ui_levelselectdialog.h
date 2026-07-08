/********************************************************************************
** Form generated from reading UI file 'levelselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELSELECTDIALOG_H
#define UI_LEVELSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LevelSelectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QGridLayout *gridLayout;
    QPushButton *btnLevel1;
    QPushButton *btnLevel2;
    QPushButton *btnLevel3;
    QPushButton *btnLevel4;
    QPushButton *btnLevel5;
    QPushButton *btnLevel6;
    QPushButton *btnLevel7;
    QPushButton *btnLevel8;
    QPushButton *btnLevel9;
    QPushButton *btnLevel10;
    QPushButton *btnLevel11;
    QPushButton *btnLevel12;
    QPushButton *btnLevel13;
    QPushButton *btnLevel14;
    QPushButton *btnLevel15;
    QPushButton *btnLevel16;
    QPushButton *btnLevel17;
    QPushButton *btnLevel18;
    QPushButton *btnLevel19;
    QPushButton *btnLevel20;
    QPushButton *btnEndless;
    QPushButton *btnBack;

    void setupUi(QDialog *LevelSelectDialog)
    {
        if (LevelSelectDialog->objectName().isEmpty())
            LevelSelectDialog->setObjectName("LevelSelectDialog");
        LevelSelectDialog->resize(800, 600);
        LevelSelectDialog->setStyleSheet(QString::fromUtf8("QDialog{\n"
"    background-color: rgb(255, 240, 245);\n"
"}\n"
"QPushButton{\n"
"    background-color: rgb(255, 182, 193);\n"
"    border: 2px solid rgb(255, 85, 127);\n"
"    border-radius: 10px;\n"
"    font: 700 14pt \"Microsoft YaHei UI\";\n"
"    color: rgb(139, 0, 139);\n"
"    padding: 10px;\n"
"}\n"
"QPushButton:hover{\n"
"    background-color: rgb(255, 85, 127);\n"
"    color: white;\n"
"}\n"
"QLabel{\n"
"    color: rgb(255, 85, 127);\n"
"    font: 700 18pt \"Microsoft YaHei UI\";\n"
"}"));
        verticalLayout = new QVBoxLayout(LevelSelectDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(LevelSelectDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnLevel1 = new QPushButton(LevelSelectDialog);
        btnLevel1->setObjectName("btnLevel1");
        btnLevel1->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel1, 0, 0, 1, 1);

        btnLevel2 = new QPushButton(LevelSelectDialog);
        btnLevel2->setObjectName("btnLevel2");
        btnLevel2->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel2, 0, 1, 1, 1);

        btnLevel3 = new QPushButton(LevelSelectDialog);
        btnLevel3->setObjectName("btnLevel3");
        btnLevel3->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel3, 0, 2, 1, 1);

        btnLevel4 = new QPushButton(LevelSelectDialog);
        btnLevel4->setObjectName("btnLevel4");
        btnLevel4->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel4, 0, 3, 1, 1);

        btnLevel5 = new QPushButton(LevelSelectDialog);
        btnLevel5->setObjectName("btnLevel5");
        btnLevel5->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel5, 0, 4, 1, 1);

        btnLevel6 = new QPushButton(LevelSelectDialog);
        btnLevel6->setObjectName("btnLevel6");
        btnLevel6->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel6, 1, 0, 1, 1);

        btnLevel7 = new QPushButton(LevelSelectDialog);
        btnLevel7->setObjectName("btnLevel7");
        btnLevel7->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel7, 1, 1, 1, 1);

        btnLevel8 = new QPushButton(LevelSelectDialog);
        btnLevel8->setObjectName("btnLevel8");
        btnLevel8->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel8, 1, 2, 1, 1);

        btnLevel9 = new QPushButton(LevelSelectDialog);
        btnLevel9->setObjectName("btnLevel9");
        btnLevel9->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel9, 1, 3, 1, 1);

        btnLevel10 = new QPushButton(LevelSelectDialog);
        btnLevel10->setObjectName("btnLevel10");
        btnLevel10->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel10, 1, 4, 1, 1);

        btnLevel11 = new QPushButton(LevelSelectDialog);
        btnLevel11->setObjectName("btnLevel11");
        btnLevel11->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel11, 2, 0, 1, 1);

        btnLevel12 = new QPushButton(LevelSelectDialog);
        btnLevel12->setObjectName("btnLevel12");
        btnLevel12->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel12, 2, 1, 1, 1);

        btnLevel13 = new QPushButton(LevelSelectDialog);
        btnLevel13->setObjectName("btnLevel13");
        btnLevel13->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel13, 2, 2, 1, 1);

        btnLevel14 = new QPushButton(LevelSelectDialog);
        btnLevel14->setObjectName("btnLevel14");
        btnLevel14->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel14, 2, 3, 1, 1);

        btnLevel15 = new QPushButton(LevelSelectDialog);
        btnLevel15->setObjectName("btnLevel15");
        btnLevel15->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel15, 2, 4, 1, 1);

        btnLevel16 = new QPushButton(LevelSelectDialog);
        btnLevel16->setObjectName("btnLevel16");
        btnLevel16->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel16, 3, 0, 1, 1);

        btnLevel17 = new QPushButton(LevelSelectDialog);
        btnLevel17->setObjectName("btnLevel17");
        btnLevel17->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel17, 3, 1, 1, 1);

        btnLevel18 = new QPushButton(LevelSelectDialog);
        btnLevel18->setObjectName("btnLevel18");
        btnLevel18->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel18, 3, 2, 1, 1);

        btnLevel19 = new QPushButton(LevelSelectDialog);
        btnLevel19->setObjectName("btnLevel19");
        btnLevel19->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel19, 3, 3, 1, 1);

        btnLevel20 = new QPushButton(LevelSelectDialog);
        btnLevel20->setObjectName("btnLevel20");
        btnLevel20->setMinimumSize(QSize(120, 80));

        gridLayout->addWidget(btnLevel20, 3, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        btnEndless = new QPushButton(LevelSelectDialog);
        btnEndless->setObjectName("btnEndless");
        btnEndless->setMinimumSize(QSize(200, 60));
        btnEndless->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFD700, stop:1 #FFA500);\n"
"        border: 3px solid #FF8C00;\n"
"        border-radius: 20px;\n"
"        font: 700 18pt \"Microsoft YaHei UI\";\n"
"        color: #8B4513;\n"
"    }\n"
"    QPushButton:hover{\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFA500, stop:1 #FF8C00);\n"
"        color: white;\n"
"    }"));

        verticalLayout->addWidget(btnEndless);

        btnBack = new QPushButton(LevelSelectDialog);
        btnBack->setObjectName("btnBack");
        btnBack->setMinimumSize(QSize(150, 50));

        verticalLayout->addWidget(btnBack);


        retranslateUi(LevelSelectDialog);
        QObject::connect(btnBack, &QPushButton::clicked, LevelSelectDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LevelSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *LevelSelectDialog)
    {
        LevelSelectDialog->setWindowTitle(QCoreApplication::translate("LevelSelectDialog", "\351\200\211\346\213\251\345\205\263\345\215\241", nullptr));
        labelTitle->setText(QCoreApplication::translate("LevelSelectDialog", "\360\237\216\256 \351\227\257\345\205\263\346\250\241\345\274\217 \360\237\216\256", nullptr));
        btnLevel1->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 1 \345\205\263", nullptr));
        btnLevel2->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 2 \345\205\263", nullptr));
        btnLevel3->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 3 \345\205\263", nullptr));
        btnLevel4->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 4 \345\205\263", nullptr));
        btnLevel5->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 5 \345\205\263", nullptr));
        btnLevel6->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 6 \345\205\263", nullptr));
        btnLevel7->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 7 \345\205\263", nullptr));
        btnLevel8->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 8 \345\205\263", nullptr));
        btnLevel9->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 9 \345\205\263", nullptr));
        btnLevel10->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 10 \345\205\263", nullptr));
        btnLevel11->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 11 \345\205\263", nullptr));
        btnLevel12->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 12 \345\205\263", nullptr));
        btnLevel13->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 13 \345\205\263", nullptr));
        btnLevel14->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 14 \345\205\263", nullptr));
        btnLevel15->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 15 \345\205\263", nullptr));
        btnLevel16->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 16 \345\205\263", nullptr));
        btnLevel17->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 17 \345\205\263", nullptr));
        btnLevel18->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 18 \345\205\263", nullptr));
        btnLevel19->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 19 \345\205\263", nullptr));
        btnLevel20->setText(QCoreApplication::translate("LevelSelectDialog", "\347\254\254 20 \345\205\263", nullptr));
        btnEndless->setText(QCoreApplication::translate("LevelSelectDialog", "\342\231\276\357\270\217 \346\227\240\345\260\275\346\250\241\345\274\217", nullptr));
        btnBack->setText(QCoreApplication::translate("LevelSelectDialog", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelSelectDialog: public Ui_LevelSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELSELECTDIALOG_H
