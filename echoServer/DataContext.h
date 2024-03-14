#include <QSqlDatabase>
#include <QSqlQuery>
#include <memory>

#ifndef DATACONTEXT_H
#define DATACONTEXT_H

class DataContext
{
private:
    static std::unique_ptr<QSqlDatabase> db_instance;

    DataContext() {}
    DataContext(const DataContext&);
    DataContext& operator=(DataContext&);

public:
    static QSqlDatabase& getInstance()
    {
        if (!db_instance)
        {
            db_instance = std::make_unique<QSqlDatabase>(QSqlDatabase::addDatabase("QSQLITE", "SQLITE"));
            db_instance->setDatabaseName("./projectTDb.db");
            db_instance->open();
        }
        return *db_instance;
    }

    static void closeInstance()
    {
        if (db_instance && db_instance->isOpen())
        {
            db_instance->close();
        }
    }
};

std::unique_ptr<QSqlDatabase> DataContext::db_instance = nullptr;

#endif // DATACONTEXT_H
