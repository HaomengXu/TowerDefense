//#include "mainwindow.h"
#include"dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog d;
    d.setWindowTitle("TowerDefence - Resistance to disease");
    d.show();
    /*MainWindow w;
    w.setWindowTitle("TowerDefence");
    w.show();*/
    return a.exec();
}
