#ifndef CONNECTTOINTERNET_H
#define CONNECTTOINTERNET_H

#include <QWidget>

namespace Ui {
class ConnecttoInternet;
}

class ConnecttoInternet : public QWidget
{
    Q_OBJECT

public:
    explicit ConnecttoInternet(QWidget *parent = nullptr);
    ~ConnecttoInternet();

private slots:
    void on_Retry_clicked();

private:
    Ui::ConnecttoInternet *ui;
};

#endif // CONNECTTOINTERNET_H
