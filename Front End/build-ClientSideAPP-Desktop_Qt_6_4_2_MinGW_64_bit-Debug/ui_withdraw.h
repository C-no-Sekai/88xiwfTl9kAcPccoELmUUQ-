/********************************************************************************
** Form generated from reading UI file 'withdraw.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAW_H
#define UI_WITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_withdraw
{
public:
    QLabel *label;
    QPushButton *pushButton_3;

    void setupUi(QWidget *withdraw)
    {
        if (withdraw->objectName().isEmpty())
            withdraw->setObjectName("withdraw");
        withdraw->resize(800, 600);
        label = new QLabel(withdraw);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Withdraw Screen-03.png")));
        label->setScaledContents(true);
        pushButton_3 = new QPushButton(withdraw);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 0, 61, 51));
        QFont font;
        font.setPointSize(28);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: Transparent;\n"
"color: rgb(00,00,00)"));

        retranslateUi(withdraw);

        QMetaObject::connectSlotsByName(withdraw);
    } // setupUi

    void retranslateUi(QWidget *withdraw)
    {
        withdraw->setWindowTitle(QCoreApplication::translate("withdraw", "Form", nullptr));
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("withdraw", "\342\206\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class withdraw: public Ui_withdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAW_H
