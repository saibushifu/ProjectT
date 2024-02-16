#include <QCoreApplication>
#include "server.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //запуск сервера
    Server s;
    return a.exec();
}
