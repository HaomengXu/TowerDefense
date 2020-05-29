#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include"point.h"
#include"enemy.h"
#include"enemy2.h"
#include"enemy3.h"
#include"enemy4.h"
#include"tower.h"
#include"tower2.h"
#include"tower3.h"
#include"map.h"
#include"map2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void sendsignal();//返回主界面信号

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void moveArmy();//时间槽函数

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
    void gameOver(QPainter &painter);
    void gameWin(QPainter &painter);

private:
    Ui::MainWindow *ui;
    QTimer *timer0;
    int _x=-1, _y=-1;//点击的区域
    int buttonCover=0;//选择建塔

    QVector<Enemy> enemy;
    QVector<Enemy2> enemy2;
    QVector<Enemy3> enemy3;
    QVector<Enemy4> enemy4;
    int virussum=10,virussum2=5,virussum3=3,virussum4=0;//这一轮敌人总数
    int virusnum=virussum,virusnum2=virussum2,virusnum3=virussum3,virusnum4=virussum4;//当前敌人数

    QVector<Tower> tower;
    QVector<Tower2> tower2;
    QVector<Tower3> tower3;
    QImage towerpic;

    int time0=0;//主时间线
    int coins=500;//金币数
    QMediaPlayer appear,attack1,attack2,attack3,die1,die2,die3,die4,setow,levelup,del,crash;//音效

    int wavenum=0;//第几波r敌人
    Map map;//地图1
    Map2 map2;//地图2
    bool over=0;
};
#endif // MAINWINDOW_H
