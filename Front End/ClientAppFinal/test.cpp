#include "test.h"
#include "ui_test.h"
#include <QGraphicsDropShadowEffect>
#include <iostream>
#include <QFont>

std::vector<std::string> tokenize1(const std::string& s, const std::string& del){
    int starting_point = 0;
    int ending_point = s.find(del) ;
    std::vector<std::string> tokens;
    std::string temp;
    while (ending_point <= s.length()){
        temp = s.substr(starting_point, ending_point-starting_point);
        starting_point = ending_point + del.length();
        ending_point = s.find(del,starting_point);
        tokens.push_back(temp);
    }
    return tokens;
}


test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
//    QLabel* arr[10]= {ui->l1,ui->l2,ui->l3,ui->l4,ui->l5,ui->l6,ui->l7,ui->l8,ui->l9,ui->l10};
//    for (auto &i:arr){
//        i->setVisible(false);
//    }
    ui->setupUi(this);

}

test::~test()
{
    delete ui;
}

std::vector<std::string> test::transactions(){
    std::string x = get_Transactions();
    return tokenize1(x, "\t\t");
}
std::vector<std::string> test:: transactions_seperated(std::string temp){
    return tokenize1(temp,"\r\r");
}
void test::on_pushButton_clicked()
{
    window_switching_to_transfer();
}


void test::on_pushButton_2_clicked()
{
    window_switching_to_withdraw();
}


void test::on_pushButton_3_clicked()
{
    window_switching_to_loaning();

}
struct MinuteTransactionDetails{
    std::string sender;
    std::string receiver;
    std::string amount;
    };
void test:: transactions_refresh(){
    MinuteTransactionDetails detailsTransactions[10];
    int index = 0, jindex;
    for(std::string i : transactions()){
        std::string temp[3];
        jindex = 0;
        for (std::string s: tokenize1(i, "\r\r")){
            temp[jindex++] = s;
        }
        detailsTransactions[index++] = {temp[0], temp[1], temp[2]};
}
    std::cout << "here4" << std::endl;
    std::cout << detailsTransactions[0].amount<< std::endl;
    std::string new_line = "\n\n";
    std::string tab = "\t\t\t";
    QLabel* arr[10]= {ui->l1,ui->l2,ui->l3,ui->l4,ui->l5,ui->l6,ui->l7,ui->l8,ui->l9,ui->l10};
    index = 0;
    QFont newFont("Segoe Ui", 14, QFont::Bold, true);
    int totalOut  = 0, totalIn = 0;
    for (auto &i: arr){
        i->setVisible(true);
        i->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        i->setStyleSheet("border-radius: 15px; background: #AA55FF; padding: 20px; width: 200px; height: 150px;");
        if (detailsTransactions[index].amount == " " && detailsTransactions[index].receiver == " " && detailsTransactions[index].sender == " ") break;
        if(detailsTransactions[index].receiver == get_name()){ i->setStyleSheet("color:#00FF00;border-radius: 15px; background: #AA55FF; padding: 20px; width: 200px; height: 150px;");}
        else{
            i->setStyleSheet("color:#FF0000;border-radius: 15px; background: #CCCCCC; padding: 20px; width: 100px; height: 150px;");
        }
        std::string x = detailsTransactions[index].amount;
        std::cout << "SET DATA =>> " + detailsTransactions[index].sender +new_line+ detailsTransactions[index].receiver +tab+ detailsTransactions[index].amount << std::endl;
        i->setText(QString ::fromStdString(detailsTransactions[index].sender +new_line+ detailsTransactions[index].receiver +tab+ detailsTransactions[index].amount));
        i->setFont(newFont);
        try{
        (detailsTransactions[index].receiver == getName()) && (totalIn += std::stod(detailsTransactions[index].amount)) || (totalOut += std::stod(detailsTransactions[index].amount));
        } catch (std::invalid_argument){
            break;
        }

        index++;
    }
    ui->label_13->setText(QString::fromStdString(std::to_string(totalIn)));
    ui->label_14->setText(QString::fromStdString(std::to_string(totalOut)));
}

void test:: balance_refresh(){
    std::string temp = get_actual_balance();
    ui ->label_3->setText(QString::fromStdString(temp));
}

void test:: name_refresh(){
    std::string temp = get_name();
    ui ->Name->setText(QString:: fromStdString(temp));

}
void test::updateHomePage(std::string* temp){
    setName(*(temp + 0));
    setTransaction(*(temp + 2));
    setBalance(*(temp + 1));
    transactions_refresh();
    balance_refresh();
    name_refresh();
}
