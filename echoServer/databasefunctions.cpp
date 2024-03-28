#include "databasefunctions.h"
#include <QSqlQuery>
#include <DataContext.h>
dataBaseFunctions::dataBaseFunctions()
{

}

void dataBaseFunctions::AddDb()
{
    //QSqlQuery query;

    auto context = DataContext::getInstance();
    context->send_query("CREATE TABLE User (id INT,firstName VARCHAR(255) NOT NULL,lastName VARCHAR(255),birthDate Date, typeId INT);", false);
    //query.exec();
}

 void  dataBaseFunctions::AddUser(qint32 id, QString login, QString password)
{
    //QSqlQuery query;

    auto context = DataContext::getInstance();
    context->send_query("INSERT INTO User(id,firstName,lastName) VALUES (" + QString::number(id) + " , '" + login + "', '" + password + "');", false);
    //query.exec();
}
