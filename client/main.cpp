#include "mainwindow.h"
#include "authform.h"
#include "modelclass.h"
#include "database.h"

#include <QApplication>

//Database* Database::p_instance = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelClass w;
    return a.exec();
}
