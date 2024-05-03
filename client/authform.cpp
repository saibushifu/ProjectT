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


void authform::on_change_clicked()
{
    bool isregflag = ui->email->isVisible();
    ui->emailLabel->setVisible(!isregflag);
    ui->email->setVisible(!isregflag);
    ui->reg->setVisible(!isregflag);
    ui->auth->setVisible(isregflag);
}


void authform::on_auth_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString res = auth(login, pass);
    emit log(res);
    //ModelClass::send_msg(res); //что не так???
}

void authform::on_reg_clicked()
{
    QString login = ui->login->text();
    QString pass = ui->password->text();
    QString mail = ui->email->text();
    QString res = reg(login, pass, mail);
    emit signup(res);
}


