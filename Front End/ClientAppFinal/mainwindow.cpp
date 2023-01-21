#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Username->setPlaceholderText("Username"); //set the placeholder text for the username line edit
    ui->Password->setPlaceholderText("Password"); //set the placeholder text for the password line edit
    ui->Password->setEchoMode(QLineEdit::Password); //set the password line edit to be hidden

    ui->Username->setEchoMode(QLineEdit::Normal); //set the username line edit to be normal
    ui->label->setText(""); //set the label to be empty
    QColor col = QColor(25,210,100);    //set the color to be green
       QString qss = QString("background-color: %1").arg(col.name()); //set the background color to be green
       ui->Login->setStyleSheet(qss); //set the style sheet to be green
} //end of constructor

MainWindow::~MainWindow() //destructor
{
    delete ui; //delete the ui object
}



void MainWindow::on_Login_clicked()
{
    std::string UandP;
    Username = ui->Username->text();
    Password = ui->Password->text();
    setName(Username.toStdString());
    UandP = "^L^"+(Username.toStdString())+"\n\n"+(Password.toStdString());
    send_data(UandP);
    authenticate();
}

void MainWindow::Colorchange()
{
ui->label->setText("<font color= red > Error incorrect Username or Password</font>");
ui->Password->setText("");
}

void MainWindow::on_checkBox_stateChanged(int arg1){
    ui->Password->setEchoMode(ui->checkBox->checkState() == Qt::Checked ? QLineEdit::Normal : QLineEdit::Password );
}
