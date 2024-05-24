#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authform.h"
#include "ui_authform.h"
#include "functionsforclient.h"
#include "modelclass.h"

#include <QStackedWidget>
#include <QTableView>
#include <QStandardItemModel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStackedWidget * stackedWidget = new QStackedWidget;
    ui->stackedWidget->setCurrentIndex(0);
    //stackedWidget->addWidget(stackedWidget);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked() // кнопка exit, закрывает главное окно и открывает окно входа в аккаунт
{
    this->hide();
    emit on_exit();
}



void MainWindow::on_task1Button_clicked() { // меняем отображение в главном окне, открывается задача на граф
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_task2Button_clicked() { // меняем отображение в главном окне, открывается задача на метод деления
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_task3Button_clicked() { // меняем отображение в главном окне, открывается задача на шифр виженера
    emit gettask("taskget&3");
    ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_returnButton1_clicked() { // возвращаемся на главное окно
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton2_clicked() { // возвращаемся на главное окно
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton3_clicked() { // возвращаемся на главное окно
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_t1pushButton_clicked() //отправка ответа пользователя на сервер, загрузка следующего текста задачи
{
    QString data1 = ui->t1_lineEdit->text();
    emit task("task1&"+data1);
    QString res = get_task_text("taskget&1");
    ui->t1_label->setText(res);
}

void MainWindow::on_t2pushButton_clicked() //отправка ответа пользователя на сервер, загрузка следующего текста задачи
{
    QString data2 = ui->t2_lineEdit->text();
    emit task("task2&"+data2);
    QString res = get_task_text("taskget&2");
    ui->t2_label->setText(res);
}

void MainWindow::on_t3pushButton_clicked() //отправка ответа пользователя на сервер, загрузка следующего текста задачи
{
    QString data3 = ui->t3_lineEdit->text();
    emit task("task3&"+data3);
    QString res_text = get_task_text("taskget&3");
    ui->t1_label->setText(res_text);
}

void MainWindow::on_pushButton_3_clicked() //получение статистики с сервера, в главном окне меняем статистику в зависимости от новых данных
{
    QStringList stats = get_stats();
    QStringList statst1 = stats.at(0).split(QLatin1Char('&'));
    QStringList statst2 = stats.at(1).split(QLatin1Char('&'));
    QStringList statst3 = stats.at(2).split(QLatin1Char('&'));

    ui->t1stat_label->setText("Кратчайший Путь: "+statst1.at(1)+" ("+statst1.at(2)+"/"+statst1.at(3)+")");
    ui->t2stat_label->setText("Метод Деления Пополам: "+statst2.at(1)+" ("+statst2.at(2)+"/"+statst2.at(3)+")");
    ui->t3stat_label->setText("Шифр Виженера: "+statst3.at(1)+" ("+statst3.at(2)+"/"+statst3.at(3)+")");
}


void MainWindow::on_t1_getTaskpushButton_clicked() // обновление условия задачи на граф
{
    QString res = get_task_text("taskget&1");
    ui->t1_label->setText(res);
}


void MainWindow::on_t2_getTaskpushButton_clicked() // обновление условия задачи на метод сечения
{
    QString res = get_task_text("taskget&2");
    ui->t2_label->setText(res);
}

void MainWindow::on_t3_getTaskpushButton_clicked() // обновление условия задачи на виженер
{
    QString res = get_task_text("taskget&3");
    ui->t3_label->setText(res);
}


