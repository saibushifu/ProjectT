#include "authform.h"
#include "ui_authform.h"
#include "functionsforclient.h"
#include "modelclass.h"

authform::authform(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::authform)
{
    ui->setupUi(this);
    ui->emailLabel->setVisible(false);
    ui->email->setVisible(false);
    ui->reg->setVisible(false);
}

authform::~authform()
{
    delete ui;
}


void authform::on_change_clicked() //функция смены режима аутентификации, меняет кнопки и поля на экране (меняются режимы "вход" и "регистрация")
{
    bool isregflag = ui->email->isVisible();
    ui->emailLabel->setVisible(!isregflag);
    ui->email->setVisible(!isregflag);
    ui->reg->setVisible(!isregflag);
    ui->auth->setVisible(isregflag);
}


void authform::on_auth_clicked() //метод, вызываемый нажатием на кнопку входа, даёт серверу данные на проверку, передаёт ответ от сервера на обработку клиенту через emit
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString res = auth(login, pass);
    emit log(res);
}

void authform::on_reg_clicked()//метод, вызываемый нажатием на кнопку регистрации, даёт серверу данные на проверку, передаёт ответ от сервера на обработку клиенту через emit
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString mail = ui->email->text();
    QString res = reg(login, pass, mail);
    emit signup(res);
}


