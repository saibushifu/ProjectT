#include "functions.h"
#include <QString>
#include <QDebug>
#include <QCoreApplication>

int t1y = 0;
int t1n = 0;
int t2y = 0;
int t2n = 0;
int t3y = 0;
int t3n = 0;

QByteArray parsing (QString data_from_client) {
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth")
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    if (nameOfFunc == "reg")
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    if (nameOfFunc == "task1")
        return task1(data_from_client_list.at(0));
    if (nameOfFunc == "task2")
        return task2(data_from_client_list.at(0));
    if (nameOfFunc == "task3")
        return task3(data_from_client_list.at(0));
    if (nameOfFunc == "stats")
        return stats();
    else
        return "error1\r\n";
}

QByteArray auth (QString log, QString pass) {
    if (log == "user" and pass == "123")
        return "auth+";
    else
        return "auth-";
}

QByteArray reg (QString log, QString pass, QString mail) {
    if (log == "user" and pass == "123" and mail == "ivan@")
        return "reg+";
    else
        return "reg-";
}

QByteArray task1 (QString data) { //граф
    if (data == "52") {
        t1y++;
        return "t1&y";
    }
    else {
        t1n++;
        return "t1&n";
    }
}

QByteArray task2 (QString data) { //сред
    if (data == "63.42"){
        t2y++;
        return "t2&y";
    }
    else {
        t2n++;
        return "t2&n";
    }
}

/*

ROT0, home, ключ-test
результат-asex

*/
QByteArray task3 (QString data) { //виженер
    if (data == "asex") {
        t3y++;
        return "t3&y";
    }
    else {
        t3n++;
        return "t3&n";
    }
}

QByteArray stats () {
    QByteArray t1a, t2a, t3a;
    t1a.setNum(t1y+t1n);
    t2a.setNum(t2y+t2n);
    t3a.setNum(t3y+t3n);
    QByteArray Qt1y, Qt1n, Qt2y, Qt2n, Qt3y, Qt3n;
    Qt1y.setNum(t1y);
    Qt1n.setNum(t1n);
    Qt2y.setNum(t2y);
    Qt2n.setNum(t2n);
    Qt3y.setNum(t3y);
    Qt3n.setNum(t3n);


    return ("t1&"+t1a+"&"+Qt1y+"&"+Qt1n+
            "$t2&"+t2a+"&"+Qt2y+"&"+Qt2n+
            "$t3&"+t3a+"&"+Qt3y+"&"+Qt3n);
}
