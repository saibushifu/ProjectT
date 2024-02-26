#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class ResultPage;
}

class ResultPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResultPage(QWidget *parent = nullptr);
    ~ResultPage();

private:
    Ui::ResultPage *ui;
    void display_results(); //отобразить результаты
};

#endif // RESULTPAGE_H
