#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>

namespace Ui {
class authform;
}

class authform : public QWidget
{
    Q_OBJECT

public:
    explicit authform(QWidget *parent = nullptr);
    ~authform();


signals:
    void authok(QString); //удали

    void log(QString);

    void signup(QString);


private slots:
    void on_change_clicked();

    void on_auth_clicked();

    void on_reg_clicked();

private:
    Ui::authform *ui;

    //void auth(QString, QString);
};

#endif // AUTHFORM_H
