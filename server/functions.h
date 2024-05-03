#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>


    QByteArray parsing (QString data_from_client);
    QByteArray auth (QString log, QString pass);
    bool email_valid(const QString& mail);
    QByteArray reg (QString log, QString pass, QString mail);
    QByteArray task_text(QString task_id);
    QByteArray task1(QString data);
    QByteArray task2(QString data);
    QByteArray task3(QString data);
    QByteArray stats();


    std::string cipher(std::string word, std::string key, bool encrypt);
    //void shifr(char* text, char* key, bool encrypt);



#endif // FUNCTIONS_H
