#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT //this is a macro that tells the compiler that the class has signals and slots

public:
    explicit Form(QWidget *parent = nullptr); //constructor
    void updateHomePage(){}; //create a function to update the homepage
    ~Form(); //destructor

private:
    Ui::Form *ui; //create a new ui object
};

#endif // FORM_H
