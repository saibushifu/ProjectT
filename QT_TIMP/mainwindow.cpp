#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
#include "resultpage.h"
#include "ui_resultpage.h"
#include "testpage.h"
#include "ui_testpage.h"
*/
#include <QMessageBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auth_ui = new AuthForm;
    auth_ui->show();
}

MainWindow::~MainWindow()
{
    delete auth_ui;
    delete ui;
}

//как сделать отображение имени нынешнего пользователя?
//сделать разделение на ученика и учителя (учитель смотрит результаты теста всех, ученик только свой?)

// https://russianblogs.com/article/66721056213/
// как?
// можно ли проще? (не создавая файлы resultpage.h/.cpp/.ui и testpage.h/.cpp/.ui)
void MainWindow::on_testButton_clicked()
{
 //переключить на виджет test
}

void MainWindow::on_resultButton_clicked()
{
 //переключить на виджет result
}
