#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    //Создаём сокет и массив байтов
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer(QString str,QString str2,  quint32 operationNumber);

    //размер передаваемого блока данных
    quint16 nextBlockSize;


    QSqlDatabase db;
    QSqlQuery *sqlQuery;


QSqlTableModel *tableModel;
public slots:
    void slotReadyRead();
};
#endif // MAINWINDOW_H
