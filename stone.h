#ifndef STONE_H
#define STONE_H

#include "point.h"
class Stone
{
public:
    Stone(const Point p):fullHP(1500),coor(p){HP=fullHP;
                                              trash.load("://image/trash.png");
                                              tar.load("://image/target.png");
                                              fire.load("://image/fire.png");}
    ~Stone(){}
    Stone(const Stone &s){
        HP=s.HP;fullHP=s.fullHP;
        coor=s.coor;
        money=s.money;
        trash=s.trash;tar=s.tar;
        target=s.target;
        fire=s.fire;
        fired=s.fired;
    }
    void show(QPainter &);

    bool getTar() const{return target;}
    void setTar(){target=!target;}//改变被攻击状态
    void setFire(){fired=200;}

    Point getCoor() const{return coor;}
    bool getAct() const{return HP>0 ? 1 : 0;}//判断是否析构
    int getMoney() const{return money;}
    void reduceHP(const int blood){HP-=blood;}

private:
    int HP;
    int fullHP;//满血

    bool target=0;
    int fired=0;//障碍物是否是攻击目标
    Point coor;
    int money=130;//奖励金币
    QImage trash,tar,fire;
};

#endif // STONE_H
