#ifndef DOUBLEPLAYERWINDOW_H
#define DOUBLEPLAYERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class DoublePlayerWindow;
}
QT_END_NAMESPACE

class DoublePlayerWindow : public QMainWindow
{
    Q_OBJECT

public:
    DoublePlayerWindow(QWidget *parent = nullptr);
    ~DoublePlayerWindow();

private slots:
    void on_pbPause_clicked();
    void on_pbExit_clicked();
    void backToMenu();

private:
    Ui::DoublePlayerWindow *ui;
};

#endif // DOUBLEPLAYERWINDOW_H
