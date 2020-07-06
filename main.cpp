#include "mainwindow.h"
#include <string>
#include <iostream>
#include <QDebug>
#include <QFont>
#include <QApplication>

int main(int argc, char *argv[])
{
    QFont font("");
    QApplication a(argc, argv);
    MainWindow w;
    a.setFont(font);
    w.show();
    w.resize(800, 600);
    return a.exec();
}
