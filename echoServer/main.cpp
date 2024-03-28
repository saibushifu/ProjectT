#include <QCoreApplication>
#include "server.h"
#include "DataContext.h"

DataContext* DataContext::p_instance = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(!DataContext::getInstance()->connect())
    {
        qDebug("ОШИБКА!!!!");
        return -1;
    }
    //запуск сервера
    Server s;
    return a.exec();
}
