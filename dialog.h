#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector>
#include<QKeyEvent>
#include"point.h"
#include"enemy.h"
#include"enemy2.h"
#include"enemy3.h"
#include"enemy4.h"
#include"stone.h"
#include"tower.h"
#include"tower2.h"
#include"tower3.h"
#include"map.h"
#include"map2.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

signals:
    void sendsignal();//返回主界面信号

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void reset();//游戏重置

protected slots:
    void moveArmy();//时间槽函数

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    //void mouseReleaseEvent(QMouseEvent *event);
    void gameOver(QPainter &);
    void gameWin(QPainter &);
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::Dialog *ui;
    QTimer *timer0;
    Point p_click;//点击的区域
    int buttonCover=0;//选择建塔

    QVector<Stone> stone;//障碍物
    QVector<Enemy> enemy;
    QVector<Enemy2> enemy2;
    QVector<Enemy3> enemy3;
    QVector<Enemy4> enemy4;
    int virussum[4]={8,5,2,0};//这一轮各种敌人总数
    int virusnum[4]={virussum[0],virussum[1],virussum[2],virussum[3]};//当前各未阵亡敌人数

    QVector<Tower> tower;
    QVector<Tower2> tower2;
    QVector<Tower3> tower3;
    QImage towerpic;

    int time0=0;//主时间线
    int coins=500;//金币数
    QMediaPlayer attack[3],die[4],appear,setow,levelup,
                del,crash,trash,perfect,lose,select,diselect;//音效

    int wavenum=0;//第几波r敌人
    Map map;//地图1
    Map2 map2;//地图2
    bool gameover=0;//判断游戏结束
    bool stop=0;//暂停
    bool speed=0;//是否快进
    int piclive=enemy[0].getLife();//被攻击时的动画参数
};

#endif // DIALOG_H
