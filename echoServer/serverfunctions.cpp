#include "serverfunctions.h"
#include "sha256.h"
serverFunctions::serverFunctions()
{

}
QString serverFunctions::answerOnOperation(quint32 operationType, QString text)
{
    //1 - Хэширование, 2 - Шифрование, 3 - авторизация, 4 - регистрация, 5 - получить id пользователя
    if(operationType == 1)
    {
        auto p = new SHA256;
        auto test = QString::fromStdString(p->hashString(text.toStdString()));
        return "Результат хэширования: " + test;
    }
    else if(operationType == 2)
    {
        return "Шифра строки " + text + " нет, но будет";
    }
    else if(operationType == 3)
    {
        return "Авторизация пользователя " + text + " не пройдена. Нет подключения к базе данных.";
    }
    else if(operationType == 4)
    {
        return "Регистрация пользователя " + text + " не пройдена. Нет подключения к базе данных.";
    }
    else if(operationType == 5)
    {
       return "id пользователя " + text + " не найден, нет подключения к базе данных";
    }
    else
    {
        return "Операция отстутсвует.";
    }
}
