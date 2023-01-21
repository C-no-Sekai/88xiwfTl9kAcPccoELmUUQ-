#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QWidget>

namespace Ui {
class withdraw;
}

class withdraw : public QWidget
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    void updateHomePage(){};
    ~withdraw();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
