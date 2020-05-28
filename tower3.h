#ifndef TOWER3_H
#define TOWER3_H

#include "tower.h"
class Tower3:public Tower{
public:
    Tower3(){range=100-20;attack=50-20;money=150;timerID=100;interval=100+10;}
    ~Tower3(){}
    Tower3(const Tower3& t){
        level=t.level;
        money=t.money;
        range=t.range;
        attack=t.attack;
        timerID=t.timerID;
        coor=t.coor;
        interval=t.interval;
    }

    void setLevel(const int l){level=l;range+=20;attack+=20;money+=120;interval-=10;}//升级
    void resetPoint(){bullet.setX(0);bullet.setY(0);timerID=30;}//重置子弹
    void show(QPainter &);

    int Attack(const Point);//判断是否攻击
    int Attack();//判断攻击效果
};

#endif // TOWER3_H
