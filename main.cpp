#include "mainwindow.h"
#include <string>
#include <iostream>
#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.resize(800, 600);
    return a.exec();
}
