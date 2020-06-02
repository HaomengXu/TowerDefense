
#include"mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("抗疫塔防游戏");//标题栏
    w.show();

    /*Dialog d;
    d.setWindowTitle("TowerDefence - Resistance to disease");
    d.show();*/

    return a.exec();
}
