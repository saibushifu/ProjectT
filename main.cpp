#include "mainwindow.h"
//#include "singletonclient.h"
#include <QCoreApplication>
//#include <iostream>
#include <QString>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //std::string msg;
    //std::cin >> msg;
    //SingletonClient::getInstance()->seng_msg_to_server(QString::fromStdString(msg));
    MainWindow w;
    w.show();
    return a.exec();
}
