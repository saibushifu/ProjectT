#ifndef TESTPAGE_H
#define TESTPAGE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class TestPage;
}

class TestPage : public QWidget
{
    Q_OBJECT

public:
    explicit TestPage(QWidget *parent = nullptr);
    ~TestPage();

private:
    Ui::TestPage *ui;
    void display_test(); //взять рандомный номер с БД и отобразить тест
    void on_answerButton_clicked(); //проверка ответов
};

#endif // TESTPAGE_H
