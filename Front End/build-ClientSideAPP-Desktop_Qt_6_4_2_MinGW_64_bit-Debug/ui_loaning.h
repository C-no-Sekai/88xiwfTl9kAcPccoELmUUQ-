/********************************************************************************
** Form generated from reading UI file 'loaning.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOANING_H
#define UI_LOANING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loaning
{
public:
    QLabel *label;
    QPushButton *pushButton_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *loaning)
    {
        if (loaning->objectName().isEmpty())
            loaning->setObjectName("loaning");
        loaning->resize(800, 600);
        label = new QLabel(loaning);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Loaning Screen-03.png")));
        label->setScaledContents(true);
        pushButton_4 = new QPushButton(loaning);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(350, 400, 111, 21));
        widget = new QWidget(loaning);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 210, 641, 182));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(loaning);

        QMetaObject::connectSlotsByName(loaning);
    } // setupUi

    void retranslateUi(QWidget *loaning)
    {
        loaning->setWindowTitle(QCoreApplication::translate("loaning", "Form", nullptr));
        label->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("loaning", "Apply", nullptr));
        pushButton->setText(QCoreApplication::translate("loaning", "Loan With 20% markup                                                                                                                           For 3 months", nullptr));
        pushButton_2->setText(QCoreApplication::translate("loaning", "Loan with 25% markup                                                                                                                           For 6 months", nullptr));
        pushButton_3->setText(QCoreApplication::translate("loaning", "Loan with 30% markup                                                                                                                                For 1 year", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("loaning", "Enter Request Amount", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("loaning", "Enter Reason for why you need the loan.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loaning: public Ui_loaning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOANING_H
