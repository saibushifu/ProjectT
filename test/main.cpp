#include "mainwindow.h"
#include "authform.h"
#include "modelclass.h"
#include "database.h"

#include <QApplication>

//Database* Database::p_instance = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // ModelClass
    // authform
    ModelClass w;
    // w.show();
    return a.exec();
}
