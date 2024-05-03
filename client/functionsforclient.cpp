#include "functionsforclient.h"
#include "singletonclient.h"


#include <QString>

QString auth(QString login, QString pass) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server("auth&"+login+"&"+pass);
    return res;
}

QString reg(QString login, QString pass, QString mail) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server("reg&"+login+"&"+pass+"&"+mail);
    return res;
}

QString get_task_text(QString data) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server(data);
    return res; // возвращает string условия задачи
}

QString task1(QString data) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server(data);
    return res;
}

QString task2(QString data) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server(data);
    return res;
}

QString task3(QString data) {
    QString res = SingletonClient::getInstance()->seng_msg_to_server(data);
    return res;
}

QStringList get_stats(){
    QString res = SingletonClient::getInstance()->seng_msg_to_server("stats&");
    // stats = t1 & t1all & t1yes & t1no
    //         $
    //         t2 & t2all & t2yes & t2no
    //         $
    //         t3 & t3all & t3yes & t3no
    QStringList stats = res.split(QLatin1Char('$'));
    return stats;
}

