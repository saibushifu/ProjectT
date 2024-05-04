#include "database.h"

#include <QCoreApplication>

Database* Database::p_instance = 0;

Database::~Database() {
    if (m_database.isOpen())
        disconnect();
    if (p_instance)
        delete p_instance;
}
Database* Database::getInstance() //Используется для получения единого экземпляра базы данных. Все методы к базе данных выполняются через вызов этого мето
{
    if (!p_instance)
    {
        p_instance = new Database();
    }
    return p_instance;
}

bool Database::FindUser(QString login, QString password)
{
    QString query = "SELECT CASE WHEN COUNT(*) > 0 THEN 'true' ELSE 'false' END AS user_exists FROM users WHERE username = '%1' AND password = '%2';";
    auto result = p_instance->send_query(query.arg(login).arg(password), true, 1);
    if (result[0] == "true") return true;
    else {
        return false;
    }

}

int Database::FindUserId(QString login, QString password)
{
    if (FindUser(login, password)){
        QString query = "SELECT id FROM users WHERE username = '%1'";
        QString result = (p_instance->send_query(query.arg(login), true, 1)).at(0);
        return result.toInt();
    }
}


QStringList Database::send_query(QString queryStr, bool is_selection, int columns_amount)
{ //Отправляет запрос и возвращает список значений, возвращенных запросом типа string. Аргумент: SQL запрос в виде строки
    QSqlQuery query;
    QStringList list;
    query.prepare(queryStr);
    if (!query.exec()){
        qDebug() << "Invalid query:" << query.lastError().text();
        list.append("!0!");
        return list;
    }
    if (!is_selection){
        list.append("!1!");
        return list;
    }

    while (query.next())
        for (int i = 0; i < columns_amount; i++){
            list.append(query.value(i).toString());
        }
    return list;
}

bool Database::connect()
{
    // Устанавливаем соединение с базой данных
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("C:/Users/zeka3/Desktop/TIMP/good/timp.db");
    if (!m_database.open())
    {
        qDebug() << "Ошибка соединения с базой данных";
        return false;
    }

    return true;
}

void Database::disconnect()
{
    // Отключаемся от базы данных
    m_database.close();
}



