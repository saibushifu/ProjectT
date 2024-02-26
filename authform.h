#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    void on_regButton_clicked();
    void on_loginButton_clicked();
    void on_changeButton_clicked();

private:
    Ui::AuthForm *ui;

};

#endif // AUTHFORM_H
