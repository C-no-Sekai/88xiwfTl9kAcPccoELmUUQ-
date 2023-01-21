/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *Name;
    QLabel *label_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QLabel *l4;
    QLabel *l5;
    QLabel *l6;
    QLabel *l7;
    QLabel *l8;
    QLabel *l9;
    QLabel *l10;
    QLabel *label_13;
    QLabel *label_14;

    void setupUi(QWidget *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName("test");
        test->resize(800, 600);
        test->setMinimumSize(QSize(800, 600));
        test->setMaximumSize(QSize(800, 600));
        test->setStyleSheet(QString::fromUtf8("  grid-column: 1 / span 2;\n"
"  display: flex;\n"
"  align-items: flex-end;\n"
"  justify-content: space-between;\n"
"  margin-bottom: 2rem;"));
        label = new QLabel(test);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 800, 600));
        label->setMinimumSize(QSize(800, 600));
        label->setMaximumSize(QSize(800, 600));
        label->setPixmap(QPixmap(QString::fromUtf8("../Project UI UX Front-End/Screen3-03.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(test);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(551, 223, 241, 61));
        QFont font;
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.267045, y1:0.261364, x2:1, y2:1, stop:0 rgba(43, 43, 152, 255), stop:1 rgba(134, 168, 255, 255));\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(test);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(551, 306, 241, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0.0170455 rgba(255, 93, 100, 255), stop:1 rgba(105, 84, 177, 255));\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(test);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(551, 389, 241, 61));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0.238636, y1:0.215909, x2:1, y2:1, stop:0 rgba(62, 141, 175, 255), stop:1 rgba(73, 141, 66, 255));\n"
"border-style: solid;\n"
"border-width: 2px;\n"
"border-radius: 10px;"));
        Name = new QLabel(test);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(180, 70, 201, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft Sans Serif")});
        font1.setPointSize(22);
        Name->setFont(font1);
        label_3 = new QLabel(test);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 125, 141, 21));
        scrollArea = new QScrollArea(test);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 150, 511, 351));
        scrollArea->setStyleSheet(QString::fromUtf8("\n"
"border-width: 2px;\n"
"border-radius: 10px;\n"
"\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 511, 351));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color :#FFFFFF"));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setObjectName("formLayout");
        l1 = new QLabel(scrollAreaWidgetContents);
        l1->setObjectName("l1");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(l1->sizePolicy().hasHeightForWidth());
        l1->setSizePolicy(sizePolicy);
        l1->setMinimumSize(QSize(0, 0));
        l1->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::SpanningRole, l1);

        l2 = new QLabel(scrollAreaWidgetContents);
        l2->setObjectName("l2");
        l2->setMinimumSize(QSize(0, 0));
        l2->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::SpanningRole, l2);

        l3 = new QLabel(scrollAreaWidgetContents);
        l3->setObjectName("l3");
        l3->setMinimumSize(QSize(0, 0));
        l3->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::SpanningRole, l3);

        l4 = new QLabel(scrollAreaWidgetContents);
        l4->setObjectName("l4");
        l4->setMinimumSize(QSize(0, 0));
        l4->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(4, QFormLayout::SpanningRole, l4);

        l5 = new QLabel(scrollAreaWidgetContents);
        l5->setObjectName("l5");
        l5->setMinimumSize(QSize(0, 0));
        l5->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(5, QFormLayout::SpanningRole, l5);

        l6 = new QLabel(scrollAreaWidgetContents);
        l6->setObjectName("l6");
        l6->setMinimumSize(QSize(0, 0));
        l6->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(7, QFormLayout::SpanningRole, l6);

        l7 = new QLabel(scrollAreaWidgetContents);
        l7->setObjectName("l7");
        l7->setMinimumSize(QSize(0, 0));
        l7->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(8, QFormLayout::SpanningRole, l7);

        l8 = new QLabel(scrollAreaWidgetContents);
        l8->setObjectName("l8");
        l8->setMinimumSize(QSize(0, 0));
        l8->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(9, QFormLayout::SpanningRole, l8);

        l9 = new QLabel(scrollAreaWidgetContents);
        l9->setObjectName("l9");
        l9->setMinimumSize(QSize(0, 0));
        l9->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(11, QFormLayout::SpanningRole, l9);

        l10 = new QLabel(scrollAreaWidgetContents);
        l10->setObjectName("l10");
        l10->setMinimumSize(QSize(0, 0));
        l10->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(12, QFormLayout::SpanningRole, l10);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label_13 = new QLabel(test);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(60, 510, 121, 21));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(true);
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        label_14 = new QLabel(test);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(390, 510, 121, 21));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QWidget *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("test", "Transfer Money", nullptr));
        pushButton_2->setText(QCoreApplication::translate("test", "Withdraw Money", nullptr));
        pushButton_3->setText(QCoreApplication::translate("test", "Loan", nullptr));
        Name->setText(QCoreApplication::translate("test", "Placeholder", nullptr));
        label_3->setText(QCoreApplication::translate("test", "TextLabel", nullptr));
        l1->setText(QString());
        l2->setText(QString());
        l3->setText(QString());
        l4->setText(QString());
        l5->setText(QString());
        l6->setText(QString());
        l7->setText(QString());
        l8->setText(QString());
        l9->setText(QString());
        l10->setText(QString());
        label_13->setText(QCoreApplication::translate("test", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("test", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
