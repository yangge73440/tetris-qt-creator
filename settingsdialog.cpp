#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QSettings>
#include <QApplication>
#include <QFont>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::loadSettings()
{
    QSettings settings("TetrisGame", "Settings");
    int volume = settings.value("volume", 30).toInt();
    QString fontFamily = settings.value("fontFamily", "Microsoft YaHei UI").toString();
    QString language = settings.value("language", "中文").toString();

    ui->sliderVolume->setValue(volume);
    ui->labelVolumeValue->setText(QString("%1%").arg(volume));
    ui->comboFont->setCurrentFont(QFont(fontFamily));
    ui->comboLanguage->setCurrentText(language);
}

void SettingsDialog::saveSettings()
{
    QSettings settings("TetrisGame", "Settings");
    settings.setValue("volume", ui->sliderVolume->value());
    settings.setValue("fontFamily", ui->comboFont->currentFont().family());
    settings.setValue("language", ui->comboLanguage->currentText());
}

void SettingsDialog::on_btnSave_clicked()
{
    saveSettings();
    accept();
}

void SettingsDialog::on_btnCancel_clicked()
{
    reject();
}

void SettingsDialog::on_sliderVolume_valueChanged(int value)
{
    ui->labelVolumeValue->setText(QString("%1%").arg(value));
}

void SettingsDialog::on_comboFont_currentFontChanged(const QFont &font)
{
    Q_UNUSED(font);
}

void SettingsDialog::on_comboLanguage_currentIndexChanged(int index)
{
    Q_UNUSED(index);
}
