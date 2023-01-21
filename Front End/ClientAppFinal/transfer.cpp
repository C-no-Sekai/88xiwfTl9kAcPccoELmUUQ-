#include "transfer.h"
#include "ui_transfer.h"
#include <vector>
#include <QIntValidator>

struct MinuteTransactionDetails{
    std::string sender;
    std::string receiver;
    std::string amount;
    };
void Transfer::process(std::string* temp){
    std::string response = *(temp + 0);
    if (response == "^INVALID^"){
        ui->label_3->setText("Incorrect Qalam ID");
        ui->lineEdit_2->setVisible(false);
        ui->pushButton_2->setVisible(false);
    } else {
        int starting_point = 0;
        int ending_point = response.find("\n\n") ;
        std::vector<std::string> tokens;
        std::string temp;
        while (ending_point <= response.length()){
            temp = response.substr(starting_point, ending_point-starting_point);
            starting_point = ending_point + 2;
            ending_point = response.find("\n\n",starting_point);
            tokens.push_back(temp);
        }
        recepient = tokens[1];
        ui->label_3->setText(QString::fromStdString(tokens[0] + "\n" + tokens[1] + "\n" + tokens[2]));
        ui->lineEdit_2->setVisible(true);
        ui->pushButton_2->setVisible(true);
    }
}
std::string Transfer::getEnteredID(){return ui->lineEdit->text().toStdString();}
Transfer::Transfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
    ui->lineEdit_2->setVisible(false);
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->pushButton_2->setVisible(false);
    ui->lineEdit_2->setValidator( new QIntValidator(0, 999999999, this) );
    ui->lineEdit->setValidator( new QIntValidator(0, 999999, this) );
}
void Transfer::authenticate(bool flag){
   if (flag)
{    ui->label_3->setStyleSheet("color: #FFFFFF");
     ui->label_3->setText(QString::fromStdString(auth()));
     ui->lineEdit_2->setVisible(true);
     ui->pushButton_2->setVisible(true);
    }
   if(!flag){
       ui->label_3->setStyleSheet("color: #FF0000");
       ui->label_3->setText("Incorrect Qalam ID");
       ui->lineEdit_2->setVisible(false);
       ui->pushButton_2->setVisible(false);
   }
}

Transfer::~Transfer()
{
    delete ui;
}

void Transfer::displayTransactionResults(std::string* temp){
    std::string response = *(temp + 0);
    if (response == "INVALID"){
        ui->label_4->setStyleSheet("color : #FF0000");
        ui->label_4->setText("Transaction Unsuccessful");
    }else{
        ui->label_4->setStyleSheet("color : #00FF00");
        ui->label_4->setText("Transaction Successful");
    }
}
void Transfer::on_pushButton_2_clicked()

{
    moneyToSend = std::stoll((ui->lineEdit_2->text()).toStdString());

    if(std::stoi((ui->lineEdit_2->text()).toStdString()) >= std::stold(get_balance())) {
        ui->label_4->setStyleSheet("color : #FF0000");
        ui->label_4->setText("Insufficient Balance");
    } else if((std::stoi((ui->lineEdit_2->text()).toStdString())) == 0){
        ui->label_4->setStyleSheet("color : #FF0000");
        ui->label_4->setText("Incorrect Entry");
    } else {
        ui->label_4->setStyleSheet("color : #00FF00");
        ui->label_4->setText("Processing...");
        makeTransfer();
    }

}


void Transfer::on_pushButton_3_clicked()
{
change_to_main();
}

