#ifndef TRANSFER_H
#define TRANSFER_H

#include <QWidget>
#include "ClientConnection.h"

namespace Ui {
class Transfer;
}

class Transfer : public QWidget
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = nullptr);
    void updateHomePage(){};
    ~Transfer();
    void authenticate(bool);
    std::string auth();
    std::string get_balance();
    void sendMoney(ClientConn*);
    int moneyToSend;
    std::string recepient;
    std::string getEnteredID();
    void makeTransfer();
    void change_to_main();

public slots:
        void process(std::string*);
        void displayTransactionResults(std::string*);

signals:
        void processTransaction(std::string*);
        void transactionResults(std::string*);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Transfer *ui;
};

#endif // TRANSFER_H
