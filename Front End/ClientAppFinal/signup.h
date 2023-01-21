#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <iostream>
#include <string>
static QString Usernamesignup, PasswordSignup, PasswordConfirmation, NameSignup,Date, QalamID;
namespace Ui
{
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    QString Name,QALAMID,USERNAME, password, dateofbirth;
    explicit signup(QWidget *parent = nullptr);
    void updateHomePage(){};
    ~signup();
    void test();
    void Send_data(std::string);
    static void displayUpdate(std::string);
private:
    Ui::signup *ui;

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

};

#endif // SIGNUP_H
