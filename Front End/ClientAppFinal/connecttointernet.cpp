#include "connecttointernet.h"
#include "ui_connecttointernet.h"


ConnecttoInternet::ConnecttoInternet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnecttoInternet)
{
    ui->setupUi(this);
}

ConnecttoInternet::~ConnecttoInternet()
{
    delete ui;
}



