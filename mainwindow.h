#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <QTimer>
#include <QMessageBox>

#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_btn_clicked();
    void slotTimerAlarm();
private:
    Ui::MainWindow *ui;
    int Array_Numbers[16]={};
    QPushButton *pButton_0=NULL;
    QTimer *timer;
    int Seconds;
};
#endif // MAINWINDOW_H
