/********************************************************************************
** Form generated from reading UI file 'transfer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFER_H
#define UI_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transfer
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;

    void setupUi(QWidget *Transfer)
    {
        if (Transfer->objectName().isEmpty())
            Transfer->setObjectName("Transfer");
        Transfer->resize(800, 600);
        label = new QLabel(Transfer);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setMinimumSize(QSize(800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Screen4-03.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(Transfer);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 240, 80, 21));
        layoutWidget = new QWidget(Transfer);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(140, 160, 521, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_2 = new QPushButton(Transfer);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 390, 80, 21));
        pushButton_3 = new QPushButton(Transfer);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(-1, -9, 61, 62));
        QFont font;
        font.setPointSize(28);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: Transparent;\n"
"color: rgb(00,00,00)"));
        pushButton_4 = new QPushButton(Transfer);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(390, 540, 61, 62));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: Transparent;\n"
"color: rgb(00,00,00)"));
        label_3 = new QLabel(Transfer);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(142, 266, 511, 51));
        label_3->setMinimumSize(QSize(0, 25));
        widget = new QWidget(Transfer);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(140, 320, 521, 43));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_3->addWidget(lineEdit_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);


        retranslateUi(Transfer);

        QMetaObject::connectSlotsByName(Transfer);
    } // setupUi

    void retranslateUi(QWidget *Transfer)
    {
        Transfer->setWindowTitle(QCoreApplication::translate("Transfer", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Transfer", "Verify", nullptr));
        label_2->setText(QCoreApplication::translate("Transfer", "Enter Reciepients Qalam ID:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Transfer", "Qalam ID", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Transfer", "Send Money", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Transfer", "\342\206\220", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Transfer", "\342\206\220", nullptr));
        label_3->setText(QCoreApplication::translate("Transfer", "Incorrect", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Transfer", "Enter Amount:", nullptr));
        label_4->setText(QCoreApplication::translate("Transfer", "Insufficient Balance.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transfer: public Ui_Transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFER_H
