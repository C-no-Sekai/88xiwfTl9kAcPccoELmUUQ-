#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication test2(argc, argv);
    MainWindow m;
    m.show();

    return test2.exec();
}
