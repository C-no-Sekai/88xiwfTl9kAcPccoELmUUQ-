/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsecond_screen;
    QWidget *centralwidget;
    QLabel *ArtBoard1;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *Username;
    QLineEdit *Password;
    QHBoxLayout *horizontalLayout;
    QPushButton *SignUp;
    QPushButton *Login;
    QLabel *label;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(1000000, 1000000));
        actionsecond_screen = new QAction(MainWindow);
        actionsecond_screen->setObjectName("actionsecond_screen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ArtBoard1 = new QLabel(centralwidget);
        ArtBoard1->setObjectName("ArtBoard1");
        ArtBoard1->setGeometry(QRect(0, 0, 800, 585));
        ArtBoard1->setMinimumSize(QSize(800, 550));
        ArtBoard1->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Screen 1-01.png")));
        ArtBoard1->setScaledContents(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 180, 321, 102));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Username = new QLineEdit(layoutWidget);
        Username->setObjectName("Username");

        verticalLayout->addWidget(Username);

        Password = new QLineEdit(layoutWidget);
        Password->setObjectName("Password");

        verticalLayout->addWidget(Password);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        SignUp = new QPushButton(layoutWidget);
        SignUp->setObjectName("SignUp");

        horizontalLayout->addWidget(SignUp);

        Login = new QPushButton(layoutWidget);
        Login->setObjectName("Login");
        Login->setAutoDefault(false);
        Login->setFlat(false);

        horizontalLayout->addWidget(Login);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout_3->addWidget(label);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(320, 210, 16, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Login->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionsecond_screen->setText(QCoreApplication::translate("MainWindow", "second screen", nullptr));
        ArtBoard1->setText(QString());
        Username->setText(QString());
        Password->setText(QString());
        SignUp->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        Login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label->setText(QString());
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
