#include "serverfunctions.h"
#include "sha256.h"
#include "databasefunctions.h"
serverFunctions::serverFunctions()
{

}
QString serverFunctions::answerOnOperation(quint32 operationType, QString text1, QString text2)
{
    //1 - Хэширование, 2 - Шифрование, 3 - авторизация, 4 - регистрация, 5 - получить id пользователя
    if(operationType == 1)
    {
        auto p = new SHA256;
        auto test = QString::fromStdString(p->hashString(text2.toStdString()));
        return "Результат хэширования: " + test;
    }
    else if(operationType == 2)
    {
        dataBaseFunctions::AddUser(1, text1, text2);
        return "Таблица добавлена";
    }
    else if(operationType == 3)
    {
        return "Авторизация пользователя " + text1 + " не пройдена. Нет подключения к базе данных.";
    }
    else if(operationType == 4)
    {
        return "Регистрация пользователя " + text1 + " не пройдена. Нет подключения к базе данных.";
    }
    else if(operationType == 5)
    {
       return "id пользователя " + text1 + " не найден, нет подключения к базе данных";
    }
    else
    {
        return "Операция отстутсвует.";
    }
}
