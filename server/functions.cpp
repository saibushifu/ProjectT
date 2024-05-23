#include "functions.h"
#include "database.h"
#include "sha256.h"
#include "vigenere.h"
#include "graphtasks.cpp"
#include "middletasks.h"


#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <regex>
#include <QFile>
#include <QTextStream>

#include <cstdlib>
#include <ctime>

int cur_task_id = -1;
int cur_user_id = -1;


vector<double> answers_t2 = {1.96875, 2.625, 4.875};
QStringList answers_t3 = {"world", "hir au hlq hziqezieh"};

QByteArray parsing (QString data_from_client) { //обработка информации с клиента, в зависимости от "имени функции" меняются вызываемые функции обработки с выводом в консоль
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth")
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));

    if (nameOfFunc == "reg")
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));

    if (nameOfFunc == "taskget")
        return task_text(data_from_client_list.at(0));

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

QByteArray auth (QString log, QString pass) { //функция входа в аккаунт, возвращает в консоль результат входа
    auto sha = new SHA256;
    auto pass_sha = QString::fromStdString(sha->hashString(pass.toStdString()));
    bool user_in_db = Database::getInstance()->FindUser(log, pass_sha);
    cur_user_id = Database::getInstance()->FindUserId(log, pass_sha);

//Unittest
    QString pass_intended = "a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3"; // password 123 (for user & tester)
    if (pass_sha == pass_intended) qDebug() << "User password unittest completed";


    if (user_in_db)
        return "auth+";
    else
        return "auth-";
}

bool email_valid(const QString& mail) { //проверка валидности почты, возвращает true/false
    std::string mail_std = mail.toStdString(); //regex_match не работает с QString, поэтому делаем std::string
    std::regex pattern("[a-zA-Z0-9_]+@[a-z]+\\.[a-z]{2,}");
    return std::regex_match(mail_std, pattern);
}

QByteArray reg (QString log, QString pass, QString mail) { //функция регистрации, возвращает в консоль результат регистрации
    if (email_valid(mail)) { // если почта может существовать
        auto sha = new SHA256;
        auto pass_sha = QString::fromStdString(sha->hashString(pass.toStdString()));
        bool user_in_db = Database::getInstance()->FindUser(log, pass_sha);
        if (!user_in_db) {
            QString stats_add = QString("INSERT INTO statistics ('task1_count') VALUES ('0');");
            QStringList res_stats = Database::getInstance()->send_query(stats_add, false, 1);
            QString query = QString("INSERT INTO users ('username', 'password', 'mail') VALUES ('%1', '%2', '%3');").arg(log, pass_sha, mail);
            QStringList res = Database::getInstance()->send_query(query, false, 1);
            if (res[0] == "!0!" || res_stats[0] == "!0!"){
                return "Ошибка во время отправки запроса";
            }
            else if (res[0] == "!1!" && res_stats[0] == "!1!"){
                cur_user_id = Database::getInstance()->FindUserId(log, pass_sha);
                return "reg+";
            }
        }
        else
            return "reg-";
        }
    return "reg-";
}


QByteArray task_text(QString task_id) { // возврат случайного условия задачи из БД
    QString query = "SELECT MAX(id) FROM '%1';"; // для task1 не возвращает, сервер падает
    int id = (Database::getInstance()->send_query(query.arg("task"+task_id), true, 1)).at(0).toInt();
    srand(time(0));
    int rand_id = (rand() % id) + 1;
    query = "SELECT text FROM task%1 WHERE id = '%2';";
    QStringList res = Database::getInstance()->send_query(query.arg(task_id).arg(rand_id), true, 1);
    cur_task_id = rand_id;
    return res.at(0).toUtf8();
}

QByteArray task1 (QString data) { //функция обработки данных для задачи на граф, возвращает результат в консоль
    QByteArray qb; //в файл graphtasks перенеси все таски от миши, также делай для себя функционал, отображение статистики и тесты
    int res = task_answer(cur_task_id);
    qb.setNum(res);

    QString query;
    if (res == data.toInt()){
        query = "UPDATE statistics SET task1_right = task1_right + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    }
    else {
        query = "UPDATE statistics SET task1_wrong = task1_wrong + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    };

//Unittest
    if (res == answers_t1.at(cur_task_id-1)) qDebug() << "Graph unittest completed";


    return "1";
}

QByteArray task2 (QString data) { //функция обработки данных для задачи на метод деления пополам, возвращает результат в консоль
    double res = task2_answer(cur_task_id);
    qDebug() << res;
    QString query;
    if (res == data.toDouble()) {
        query = "UPDATE statistics SET task2_right = task2_right + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    }
    else {
        query = "UPDATE statistics SET task2_wrong = task2_wrong + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    };

    //Unittest
    if (res == answers_t2.at(cur_task_id-1)) qDebug() << "Bisection unittest completed";


    return "1";
}

QByteArray task3 (QString data) { //функция обработки данных для задачи на шифр виженера, возвращает результат в консоль
    QString result;
    QStringList q_res;
    QString query = "SELECT word, key, encrypt FROM task3 WHERE id = '%1';";
    q_res = Database::getInstance()->send_query(query.arg(cur_task_id), true, 3);
    QString word = q_res.at(0), key = q_res.at(1), encrypt = q_res.at(2);

    bool need_encrypt = (encrypt.toInt() == 2);
    if (need_encrypt) {
        result = Encrypt(word, key);
    }
    else result = Decrypt(word, key);

    if (result.toLower() == data){
        query = "UPDATE statistics SET task3_right = task3_right + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    }
    else {
        query = "UPDATE statistics SET task3_wrong = task3_wrong + 1 WHERE user_id = '%1';";
        Database::getInstance()->send_query(query.arg(cur_user_id), false, 1);
    };

    //Unittest
    if (result.toLower() == answers_t3.at(cur_task_id-1)) qDebug() << "Vigenere unittest completed";


    return "1";
    //return result.toLower().toLatin1();
}

QByteArray stats () { // метод получения статистики, вывод её в консоль
    QString query = "SELECT * FROM statistics WHERE user_id = '%1';";
    QStringList q_res;
    q_res = Database::getInstance()->send_query(query.arg(cur_user_id), true, 7);
    QString t1y, t1n, t2y, t2n, t3y, t3n;
    int t1c, t2c,  t3c;
    QString t1, t2, t3;
    t1y = q_res.at(1);
    t1n = q_res.at(2);
    t1c = t1y.toInt()+t1n.toInt();

    t2y = q_res.at(3);
    t2n = q_res.at(4);
    t2c = t2y.toInt()+t2n.toInt();

    t3y = q_res.at(5);
    t3n = q_res.at(6);
    t3c = t3y.toInt()+t3n.toInt();

    t1.setNum(t1c);
    t2.setNum(t2c);
    t3.setNum(t3c);

    QString res;
    res = "t1&"+t1+"&"+t1y+"&"+t1n+"$"+
          "t2&"+t2+"&"+t2y+"&"+t2n+"$"+
          "t3&"+t3+"&"+t3y+"&"+t3n;
    return res.toUtf8();
}



