#ifndef TOWER_H
#define TOWER_H

#include "point.h"
class Tower{
public:
    Tower(){}
    ~Tower(){}
    Tower(const Tower& t){
        level=t.level;
        money=t.money;
        range=t.range;
        attack=t.attack;
        timerID=t.timerID;
        interval=t.interval;
        coor=t.coor;
        theta=t.theta;
    }
    void show(QPainter &);

    int Attack(const Point);

    int getLevel() const{return level;}
    void setLevel(const int l){level=l;range+=70;attack+=20;money+=80;interval-=10;}
    int getMoney() const{return money;}
    int getAttack() const{return attack;}

    Point getCoor() const{return coor;}
    void setCoor(const Point &c){coor=c;}
    void resetPoint(){bullet.setX(0);bullet.setY(0);timerID=5;}//重置子弹

protected:
    int level=0;
    int money=100;

    int range=150-70;
    int attack=60-20;

    int timerID=5;//时间线
    int interval=60+10;//射击间隔
    Point coor;//塔坐标
    Point bullet;//子弹坐标
    QImage tower;

private:
    double theta=45;//针头旋转角度
};

#endif // TOWER_H
