#ifndef LOANING_H
#define LOANING_H

#include <QWidget>

namespace Ui {
class loaning;
}

class loaning : public QWidget
{
    Q_OBJECT

public:
    explicit loaning(QWidget *parent = nullptr);
    ~loaning();
    std::string loan_selection, chosenOption;

    void sendMsg(std::string);
    void func();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();



private:
    Ui::loaning *ui;
};

#endif // LOANING_H
