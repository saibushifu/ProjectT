#ifndef MODELCLASS_H
#define MODELCLASS_H

#include "authform.h"
#include "mainwindow.h"

#include <QObject>
#include <QDebug>

class ModelClass : public QObject
{
    Q_OBJECT;

private:
    authform* authf;
    MainWindow* mainf;

public:
    ModelClass(QObject * parent=nullptr);
    // получает имя, на выход говорит что запустить (форму) или какой сигнал вызвать
    void send_msg(QString);
    void task_msg(QString);

public slots:
    void slot_on_msgRead(QString);
    void slot_on_exit();

signals:
    void msgRead(QString);


};

#endif // MODELCLASS_H
