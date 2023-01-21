/********************************************************************************
** Form generated from reading UI file 'connecttointernet.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTTOINTERNET_H
#define UI_CONNECTTOINTERNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnecttoInternet
{
public:
    QLabel *label;
    QPushButton *Retry;

    void setupUi(QWidget *ConnecttoInternet)
    {
        if (ConnecttoInternet->objectName().isEmpty())
            ConnecttoInternet->setObjectName("ConnecttoInternet");
        ConnecttoInternet->resize(800, 600);
        ConnecttoInternet->setMinimumSize(QSize(800, 600));
        ConnecttoInternet->setMaximumSize(QSize(800, 600));
        label = new QLabel(ConnecttoInternet);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setMinimumSize(QSize(800, 600));
        label->setMaximumSize(QSize(800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Project UI UX Front-End/Error Screen-03.png")));
        label->setScaledContents(true);
        Retry = new QPushButton(ConnecttoInternet);
        Retry->setObjectName("Retry");
        Retry->setGeometry(QRect(330, 450, 159, 25));

        retranslateUi(ConnecttoInternet);

        QMetaObject::connectSlotsByName(ConnecttoInternet);
    } // setupUi

    void retranslateUi(QWidget *ConnecttoInternet)
    {
        ConnecttoInternet->setWindowTitle(QCoreApplication::translate("ConnecttoInternet", "Form", nullptr));
        label->setText(QString());
        Retry->setText(QCoreApplication::translate("ConnecttoInternet", "Retry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnecttoInternet: public Ui_ConnecttoInternet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTTOINTERNET_H
