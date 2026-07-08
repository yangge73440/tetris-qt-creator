#ifndef LEADERBOARDDIALOG_H
#define LEADERBOARDDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QTabWidget>
#include "scoremanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LeaderboardDialog;
}
QT_END_NAMESPACE

class LeaderboardDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LeaderboardDialog(QWidget *parent = nullptr);
    ~LeaderboardDialog();
    
private slots:
    void refreshData();
    
private:
    Ui::LeaderboardDialog *ui;
    ScoreManager *m_scoreManager;
    
    void setupTopScoresTable();
    void setupHistoryTable();
};

#endif // LEADERBOARDDIALOG_H
