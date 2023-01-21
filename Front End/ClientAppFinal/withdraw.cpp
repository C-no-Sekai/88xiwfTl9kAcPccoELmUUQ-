#include "withdraw.h"
#include "ui_withdraw.h"

withdraw::withdraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}



