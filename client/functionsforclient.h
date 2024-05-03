#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QString>

QString auth(QString, QString);

QString reg(QString, QString, QString);

QString get_task_text(QString data);

QString task1(QString);

QString task2(QString);

QString task3(QString);

QString func_parse(QString);

QStringList get_stats();

double task1_res(QString);

double FindRoot(double (*f)(double), double a, double b, double eps);

double Func(double x);

#endif // FUNCTIONSFORCLIENT_H
