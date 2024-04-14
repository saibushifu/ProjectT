#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>


    QByteArray parsing (QString data_from_client);
    QByteArray auth (QString log, QString pass);
    QByteArray reg (QString log, QString pass, QString mail);
    QByteArray task1(QString data);
    QByteArray task2(QString data);
    QByteArray task3(QString data);
    QByteArray stats();


#endif // FUNCTIONS_H
