#include "signup.h"
#include "ui_signup.h"
#include <QIntValidator>

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setValidator( new QIntValidator(1, 999999, this) );
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{

QDate datetemp;
PasswordSignup  = ui->lineEdit_4->text();
PasswordConfirmation = ui->lineEdit_5->text();
if(PasswordSignup == PasswordConfirmation)
{   ui->label_3->setText("");
    NameSignup = ui->lineEdit->text();
    QalamID = ui->lineEdit_2->text();
    Usernamesignup = ui->lineEdit_3->text();
    datetemp = ui->dateEdit->date();
    Date = datetemp.toString();
    std::cout << Date.toStdString() << std::endl;
    this->test();
    std::string testtemp;
    testtemp = "^S^"+NameSignup.toStdString()+"\n\n"+QalamID.toStdString()+"\n\n"+Usernamesignup.toStdString()+"\n\n"+PasswordSignup.toStdString()+"\n\n"+Date.toStdString();
    this->Send_data(testtemp);
}
else{
    ui->label_3->setText("<font color= red >Your Passwords do not match. </font>");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}
}


void signup::on_checkBox_2_stateChanged(int arg1)
{
        ui->lineEdit_4->setEchoMode(ui->checkBox_2->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}


void signup::on_checkBox_stateChanged(int arg1)
{
    ui->lineEdit_5->setEchoMode(ui->checkBox->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}

void signup::displayUpdate(std::string updatedData){

}
