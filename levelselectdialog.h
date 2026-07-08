#ifndef LEVELSELECTDIALOG_H
#define LEVELSELECTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class LevelSelectDialog; }
QT_END_NAMESPACE

class LevelSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LevelSelectDialog(QWidget *parent = nullptr);
    ~LevelSelectDialog();

signals:
    void levelSelected(int level);

private slots:
    void onLevelButtonClicked();
    void onEndlessClicked();
    void onBackClicked();

private:
    void setupUI();
    
    QPushButton *levelButtons[20];
    QPushButton *pbEndless;
    QPushButton *pbBack;
    QLabel *labelTitle;
};

#endif // LEVELSELECTDIALOG_H
