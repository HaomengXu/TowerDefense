#ifndef TOWER2_H
#define TOWER2_H

#include "tower.h"
class Tower2:public Tower{
public:
    Tower2(){range=120-60;attack=40-25;money=120;interval=40+10;}
    ~Tower2(){}
    Tower2(const Tower2& t){
        level=t.level;
        money=t.money;
        range=t.range;
        attack=t.attack;
        timerID=t.timerID;
        coor=t.coor;
        interval=t.interval;
    }

    void setLevel(const int l){level=l;range+=60;attack+=25;money+=100;interval-=10;}//升级
    void show(QPainter &);

    int Attack(const Point);//子弹攻击过程
    bool reSpeed(Point);//减速后离开攻击范围的速度恢复
};

#endif // TOWER2_H
