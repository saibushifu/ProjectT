#include "authform.h"
#include "ui_authform.h"
#include <QMessageBox>
#include <QApplication>
/*

сделать метод void getData на получение инфы из БД, при этом сделать 3 переменные
на хранение данных из клиента, и сравнение данных с клиента и с БД ?

*/
AuthForm::AuthForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->login->setPlaceholderText("Login");
    ui->password->setPlaceholderText("Password");
    ui->fio->setPlaceholderText("Full Name");

    //включение кнопок на быструю очистку поля ввода (а нахуй оно надо?)
    //ui->login->setClearButtonEnabled(true);
    //ui->password->setClearButtonEnabled(true);
    //ui->fio->setClearButtonEnabled(true);

    //statusBar только в mainwindow (он типа QMainWindow, может сделать такого же типа и окно с регой?)
    //ui->statusBar->showMessage("Неправильн(ый/ое) логин/пароль/ФИО");
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_regButton_clicked() {
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString fio = ui->fio->text();
    // метод void getData, которым получаем проверяемые данные (login не в БД) (или пароль не тот)
    // регистрация
}

void AuthForm::on_loginButton_clicked() {
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString fio = ui->fio->text();

    // getData, смотрим правильность всех данных

    /*

    здесь проверка, хз пока, но в случае нахождения проблемы с логином (не тот пароль/логин/ФИО)
    выводим ошибку (только надо что бы она конкретно указывала в чём беда, как это сделать?
    ui->statusBar->showMessage("Неправильн(ый/ое) логин/пароль/ФИО");

    */
}

// чёт пока не понятно, разберись как скрывать/показывать (а также менять) label и поле ввода
// сделать что бы сверху был label отображающий нынешний режим (вход/рега)
// сделать что бы в каждом режиме было по 2 кнопки (в реге кнопка реги и смены, во входе - входа и смены)
void AuthForm::on_changeButton_clicked() {
    int i = 0;
    if (i % 2 == 0) { //режим регистрации
        ui->fio->setVisible(true);
        ui->fio_label->setVisible(true);
        i++;
    }
    else {
        ui->fio->setVisible(false);
        ui->fio_label->setVisible(false);
        i--;
    }
}
