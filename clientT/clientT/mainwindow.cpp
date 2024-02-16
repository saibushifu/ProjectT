#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //создаём сокет
    socket = new QTcpSocket(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    db.setDatabaseName("./projectTDb.db");
db.open();
    sqlQuery = new QSqlQuery(db);
    sqlQuery->exec("CREATE TABLE user(id INT, login TEXT, password TEXT);");

    tableModel = new QSqlTableModel(this, db);
    tableModel->setTable("user");
    tableModel->select();

    ui->tableView->setModel(tableModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Подключаем сокет к серверу
    socket->connectToHost("127.0.0.1", 7777);
    //Подключаем сигналы
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;
}

void MainWindow::SendToServer(QString login, QString password, quint32 operationNumber)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
//это соообщение передаётся
    out << quint16(0) << operationNumber << login << password;
    out.device()->seek(0);
    //размер сообщения = длина блока - выделенные для размера байты
    out << quint16(Data.size() - sizeof(quint16));


    socket->write(Data);

    ui->lineEdit->clear();
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_9);
    if(in.status()==QDataStream::Ok)
    {

        for(;;)
        {
             //считываем размер блока
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {break;}
                //считываем размер блока
                in >> nextBlockSize;
            }
            //сравниваем размер блока с кол-вом байт, пришедшим с сервера
            if(socket->bytesAvailable() < nextBlockSize)
            {
                //данные пришли не полностью
                break;
            }
            //типы получаемых значений из потока
            QString str;
            in >> str;
            //обнуляем размер блока, чтобы принимать новые сообщения
            nextBlockSize = 0;
            //выводим текст на экран
            ui->textBrowser->append(str);


        }



        /*QString str;
        in >> str;
        //добавляем строку в текст браузер
        ui->textBrowser->append(str);*/

    }
    else
    {
        ui->textBrowser->append("read error");

    }
}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_lineEdit_returnPressed()
{

}


void MainWindow::on_pushButton_5_clicked()
{
    SendToServer(ui->lineEdit_2->text(),ui->lineEdit_3->text(), 1);
}


void MainWindow::on_pushButton_4_clicked()
{
    SendToServer(ui->lineEdit_2->text(),ui->lineEdit_3->text(), 2);
}

