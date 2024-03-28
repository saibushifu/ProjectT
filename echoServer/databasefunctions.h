#ifndef DATABASEFUNCTIONS_H
#define DATABASEFUNCTIONS_H

#include <QString>

class dataBaseFunctions
{
public:
    dataBaseFunctions();
    void static AddUser(qint32 id, QString login, QString password);
    quint32 GetUserId();
    void static AddDb();
};

#endif // DATABASEFUNCTIONS_H
