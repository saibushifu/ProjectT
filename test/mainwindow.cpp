#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authform.h"
#include "ui_authform.h"
#include "functionsforclient.h"
#include "modelclass.h"

#include <QStackedWidget>
#include <QTableView>
#include <QStandardItemModel>

/*

    СТАТИСТИКА:
    НА ГЛАВНОМ ОКОШКЕ СНИЗУ СДЕЛАТЬ ТАБЛИЧКУ, ГДЕ БУДЕТ СТАТИСТИКА ПО ТОМУ, СКОЛЬКО РАЗ ЧЕЛОВЕК ПРАВИЛЬНО РАСЧИТАЛ,
    К ПРИМЕРУ, ПУТИ В ГРАФЕ. ИЛИ ПРАВИЛЬНО ПО ШИФРУ ВИЖЕНЕРА ПРЕОБРАЗИЛ СЛОВО

*/


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStackedWidget * stackedWidget = new QStackedWidget;
    //stackedWidget->addWidget(stackedWidget);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked() // кнопка exit
{
    this->hide();
    emit on_exit();
}



void MainWindow::on_task1Button_clicked() {
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_task2Button_clicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_resButton_clicked() {
    ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_returnButton1_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton2_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton3_clicked() {
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_t1pushButton_clicked() //task 1
{
    QString data1 = ui->t1_lineEdit->text();
    emit task("task1&"+data1);
}

void MainWindow::on_t2pushButton_clicked()
{
    QString data2 = ui->t2_lineEdit->text();
    emit task("task2&"+data2);
}

void MainWindow::on_t3pushButton_clicked()
{
    QString data3 = ui->t3_lineEdit->text();
    emit task("task3&"+data3);
}

void MainWindow::on_pushButton_3_clicked() //stats
{
    QStringList stats = get_stats();
    QStringList statst1 = stats.at(0).split(QLatin1Char('&'));
    QStringList statst2 = stats.at(1).split(QLatin1Char('&'));
    QStringList statst3 = stats.at(2).split(QLatin1Char('&'));

    ui->t1stat_label->setText("Шифр Виженера: "+statst1.at(1)+" ("+statst1.at(2)+"/"+statst1.at(3)+")");
    ui->t2stat_label->setText("Метод Деления Пополам: "+statst2.at(1)+" ("+statst2.at(2)+"/"+statst2.at(3)+")");
    ui->t3stat_label->setText("Кратчайший Путь: "+statst3.at(1)+" ("+statst3.at(2)+"/"+statst3.at(3)+")");
    qDebug() << statst1 << "\n" << statst2 << "\n" << statst3;
}







