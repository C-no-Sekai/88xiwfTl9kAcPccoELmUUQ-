/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(800, 600);
        signup->setMinimumSize(QSize(800, 600));
        label = new QLabel(signup);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -7, 800, 585));
        label->setMinimumSize(QSize(800, 585));
        label->setMaximumSize(QSize(800, 585));
        label->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Screen 2-02.png")));
        label->setScaledContents(true);
        layoutWidget = new QWidget(signup);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 179, 291, 207));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout->addWidget(lineEdit_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_2->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);

        label_3 = new QLabel(signup);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 261, 21));
        checkBox = new QCheckBox(signup);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(290, 287, 20, 31));
        checkBox_2 = new QCheckBox(signup);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(290, 266, 20, 16));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Form", nullptr));
        label->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("signup", "Full Name", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("signup", "CMS ID", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("signup", "Username", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("signup", "Password", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("signup", "Confirm Password", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "DOB            MM/DD/YYYY", nullptr));
        pushButton->setText(QCoreApplication::translate("signup", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("signup", "SignUp and Login", nullptr));
        label_3->setText(QString());
        checkBox->setText(QString());
        checkBox_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
