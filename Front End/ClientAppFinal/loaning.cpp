#include "loaning.h"
#include "ui_loaning.h"

loaning::loaning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loaning)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->plainTextEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);
}

loaning::~loaning()
{
    delete ui;
}

void loaning::on_pushButton_clicked()
{   chosenOption = "1";
    loan_selection = "loan with 20% markup";
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_2->setText("Loan With 20% Markup rate");
    ui->lineEdit->setVisible(true);
    ui->plainTextEdit->setVisible(true);
    ui->pushButton_4->setVisible(true);
}


void loaning::on_pushButton_2_clicked()
{   loan_selection = "loan with 25% markup";
    chosenOption = "2";
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_2->setText("Loan With 25% Markup rate");
    ui->lineEdit->setVisible(true);
    ui->plainTextEdit->setVisible(true);
    ui->pushButton_4->setVisible(true);
}

void loaning::on_pushButton_3_clicked()
{   loan_selection = "loan with 30% markup";
    chosenOption = "3";
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->label_2->setVisible(true);
    ui->label_2->setText("Loan With 30% Markup rate");
    ui->lineEdit->setVisible(true);
    ui->plainTextEdit->setVisible(true);
    ui->pushButton_4->setVisible(true);
}

void loaning::on_pushButton_4_clicked()
{
    std::string msg = "^LOAN^" + chosenOption + "\n\n" + ui->lineEdit->text().toStdString() + "\n\n";
    func();
    sendMsg(msg);
}

