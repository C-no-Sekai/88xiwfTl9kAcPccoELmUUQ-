#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "signup.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString Username,Password;
    bool signupcondition = false;
    void print();
    void click(signup);
    void send_data(std::string);
    void authenticate();
    void Colorchange();
    void setName(std::string);
    std::string getName();

public slots:
    void updateLogin(bool);
private slots:
    void on_Login_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_SignUp_clicked();

signals:
    void LoginUpdate(bool);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
