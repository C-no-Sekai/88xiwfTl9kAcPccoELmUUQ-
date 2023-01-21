#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form) //create a new ui object
{
    ui->setupUi(this);   //setup the UI
}

Form::~Form() //destructor
{
    delete ui; //delete the ui object
}

