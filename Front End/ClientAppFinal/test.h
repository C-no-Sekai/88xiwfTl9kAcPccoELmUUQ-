#ifndef TEST_H
#define TEST_H
#include <string>
#include <QWidget>
#include <vector>
//#include "Tokenizer.h"

namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    ~test();
    void window_switching_to_transfer();
    void window_switching_to_loaning();
    void window_switching_to_withdraw();
    std::string get_name();
    std::string get_Transactions();
    std::string get_actual_balance();
    void setName(std::string);
    void setTransaction(std::string);
    void setBalance(std::string);
    std::vector<std::string> transactions();
    std::vector<std::string> transactions_seperated(std::string);
    void transactions_refresh();
    void balance_refresh();
    void name_refresh();

    std::string getName();

public slots:
    void updateHomePage(std::string*);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
signals:
    void UpdateHome(std::string*);
private:
    Ui::test *ui;
};

#endif // TEST_H
