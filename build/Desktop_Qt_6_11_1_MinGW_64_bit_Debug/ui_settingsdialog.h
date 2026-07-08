/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *labelVolume;
    QSlider *sliderVolume;
    QLabel *labelVolumeValue;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelFont;
    QFontComboBox *comboFont;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelLanguage;
    QComboBox *comboLanguage;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName("SettingsDialog");
        SettingsDialog->resize(500, 400);
        SettingsDialog->setStyleSheet(QString::fromUtf8("*{\n"
"    border-style:double;\n"
"	border-color: rgb(255, 85, 127);\n"
"    border-width:4px;\n"
"	color: rgb(255, 85, 127);\n"
"    border-radius:10px;\n"
"	font: 700 16pt \"Microsoft YaHei UI\";\n"
"    padding:4px;\n"
"}\n"
"QFrame{\n"
"	background-color: rgb(232, 221, 203);\n"
"}\n"
"QLabel{\n"
"border-width:0px;\n"
"}\n"
"QPushButton{\n"
"border-width:2px;\n"
"}\n"
"QPushButton:hover{\n"
"border-width:2px;\n"
"font:  18pt \"Microsoft YaHei UI\";\n"
"}"));
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setObjectName("verticalLayout");
        labelTitle = new QLabel(SettingsDialog);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setMinimumSize(QSize(0, 50));
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        labelVolume = new QLabel(groupBox);
        labelVolume->setObjectName("labelVolume");

        horizontalLayout->addWidget(labelVolume);

        sliderVolume = new QSlider(groupBox);
        sliderVolume->setObjectName("sliderVolume");
        sliderVolume->setMinimum(0);
        sliderVolume->setMaximum(100);
        sliderVolume->setValue(30);
        sliderVolume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolume);

        labelVolumeValue = new QLabel(groupBox);
        labelVolumeValue->setObjectName("labelVolumeValue");

        horizontalLayout->addWidget(labelVolumeValue);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelFont = new QLabel(groupBox_2);
        labelFont->setObjectName("labelFont");

        horizontalLayout_2->addWidget(labelFont);

        comboFont = new QFontComboBox(groupBox_2);
        comboFont->setObjectName("comboFont");

        horizontalLayout_2->addWidget(comboFont);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(SettingsDialog);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelLanguage = new QLabel(groupBox_3);
        labelLanguage->setObjectName("labelLanguage");

        horizontalLayout_3->addWidget(labelLanguage);

        comboLanguage = new QComboBox(groupBox_3);
        comboLanguage->addItem(QString());
        comboLanguage->addItem(QString());
        comboLanguage->setObjectName("comboLanguage");
        comboLanguage->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(comboLanguage);


        verticalLayout->addWidget(groupBox_3);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SettingsDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SettingsDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "\350\256\276\347\275\256", nullptr));
        labelTitle->setText(QCoreApplication::translate("SettingsDialog", "\346\270\270\346\210\217\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsDialog", "\351\237\263\351\207\217", nullptr));
        labelVolume->setText(QCoreApplication::translate("SettingsDialog", "\351\237\263\351\207\217:", nullptr));
        labelVolumeValue->setText(QCoreApplication::translate("SettingsDialog", "30%", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsDialog", "\345\255\227\344\275\223", nullptr));
        labelFont->setText(QCoreApplication::translate("SettingsDialog", "\345\255\227\344\275\223:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SettingsDialog", "\350\257\255\350\250\200", nullptr));
        labelLanguage->setText(QCoreApplication::translate("SettingsDialog", "\350\257\255\350\250\200:", nullptr));
        comboLanguage->setItemText(0, QCoreApplication::translate("SettingsDialog", "\344\270\255\346\226\207", nullptr));
        comboLanguage->setItemText(1, QCoreApplication::translate("SettingsDialog", "English", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
