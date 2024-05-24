#include "modelclass.h"
#include "mainwindow.h"
#include "authform.h"
#include "singletonclient.h"
#include "functionsforclient.h"

ModelClass::ModelClass(QObject *parent) : QObject(parent)
{
    this->authf = new authform();
    this->mainf = new MainWindow;
    authf->show();
    connect(authf, //соединяем authf, сигнал логина, modelclass и обработку сигнала логина
            &authform::log,
            this,
            &ModelClass::receive_msg);

    connect(authf,
            &authform::signup,
            this,
            &ModelClass::receive_msg);

    connect(mainf,
            &MainWindow::task,
            this,
            &ModelClass::slot_on_msgRead);



    //////

    //connect будет ронять приложение, если хоть 1 элемент НЕ СУЩЕСТВУЕТ

    //////

    //выход из mainwindow в authform
    connect(mainf,
            &MainWindow::on_exit, // сигнал
            this, // сюда
            &ModelClass::slot_on_exit); // слот


}


void ModelClass::receive_msg(QString msg) //обработка сообщения от сервера, если ответ является отказом во входе/регистрации, то в консоль пишем ошибку, иначе передаём данные в следующий обработчик
{

    if (msg == "auth-" || msg == "reg-")
        qDebug() << "Отказ входа/регистрации";
    else
        this->slot_on_msgRead(msg);
}


void ModelClass::slot_on_msgRead(QString msg) //обрабатываем либо успешное сообщение входа/регистрации, либо запрос на проверку ответа на задание
{
    qDebug() << msg;
    if(msg.mid(0, 4) == "reg+" || msg.mid(0, 5) == "auth+") {
        this->authf->close();
        this->mainf->show();
    }

    else if (msg.mid(0, 1) == "t") {
        if (msg.mid(0, 6) == "task1&") {
            task1(msg);
        }
        else if (msg.mid(0, 6) == "task2&") {
            task2(msg);
        }
        else if (msg.mid(0, 6) == "task3&") {
            task3(msg);
        }
    }

    else qDebug() << "Что-то пошло не так (ModelClass::slot_on_msgRead)";

}

void ModelClass::slot_on_exit() { //при нажатии на кнопку выхода в главном окне вызывается эта функция, закрывает главное окно и показывает окно входа в аккаунт
    authf->show();
    mainf->close();
}