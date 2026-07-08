#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class SettingsDialog;
}
QT_END_NAMESPACE

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();
    void on_sliderVolume_valueChanged(int value);
    void on_comboFont_currentFontChanged(const QFont &font);
    void on_comboLanguage_currentIndexChanged(int index);

private:
    Ui::SettingsDialog *ui;
    void loadSettings();
    void saveSettings();
};

#endif // SETTINGSDIALOG_H
