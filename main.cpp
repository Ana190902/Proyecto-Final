#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    w.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    w.show();
    return a.exec();
}
