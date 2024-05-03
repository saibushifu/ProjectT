#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>


class Database
{

private:

    static Database * p_instance;
    QSqlDatabase m_database;

protected:
    Database(){}
    Database(const Database& );
    Database& operator = (Database&);
    ~Database();

public:
    static Database* getInstance();

    QStringList send_query(QString queryStr, bool is_selection, int columns_amount);

    bool connect();

    bool FindUser(QString, QString);

    int FindUserId(QString, QString);

    void disconnect();


};

#endif // DATABASE_H
