#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "authform.h"

#include <QMainWindow>
#include <QStackedWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void on_exit();
    void task(QString);
    void gettask(QString);

private slots:
    void on_exitButton_clicked();

    void on_task1Button_clicked();

    void on_task2Button_clicked();

    void on_task3Button_clicked();

    // можно сделать много кнопок, ссыл. на 1 метод?
    void on_returnButton1_clicked();
    void on_returnButton2_clicked();
    void on_returnButton3_clicked();

    void on_pushButton_3_clicked();

    void on_t1pushButton_clicked();

    void on_t2pushButton_clicked();

    void on_t3pushButton_clicked();

    void on_t1_getTaskpushButton_clicked();


    void on_t3_getTaskpushButton_clicked();

    void on_t2_getTaskpushButton_clicked();

private:
    Ui::MainWindow *ui;
    authform * authf;
};
#endif // MAINWINDOW_H
