#include <QCoreApplication>
#include "mytcpserver.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    if(!Database::getInstance()->connect())
    {
        qDebug("Ощибка подключения к БД!");
        return -1;
    }
    MyTcpServer myserv;
    return a.exec();
}
