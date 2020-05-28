#ifndef ENEMY_H
#define ENEMY_H

#include <QMediaPlayer>
#include "point.h"
#include"map.h"
#include"map2.h"
//#include <QMessageBox>
class Enemy{
public:
    Enemy():fullHP(100),normspeed(1){HP=fullHP;speed=normspeed;
                                     virus.load("://image/virus1.png");light.load("://image/Light.png");
                                     if(whichmap==1){coor.setX(70);coor.setY(140);}
                                     else{coor.setX(0);coor.setY(280);}//坐标初始化
                                    }
    ~Enemy(){/*QMessageBox::information(NULL,"~Enemy","die");*/}
    Enemy(const Enemy &e):fullHP(100),normspeed(1){
        HP=e.HP;fullHP=e.fullHP;
        speed=e.speed;normspeed=e.normspeed;
        timeline=e.timeline;
        coor=e.coor;
        money=e.money;
        virus=e.virus;
        light=e.light;
    } 
    void show(QPainter &);

    void setSpeed(const double s){speed=s;}
    double getSpeed() const{return speed;}
    int getNormsp() const{return normspeed;}
    int getHP() const{return HP;}
    void setHP(const int hp){HP=hp;}

    Point getCoor() const{return coor;}
    void setCoor(const Point & c){coor=c;}
    void setMap(const int m){whichmap=m;}
    int getMap() const{return whichmap;}

    int getLife() const{return life;}
    int getMoney() const{return money;}
    double getTime() const{return timeline;}

protected:
    Map map;
    Map2 map2;

    int HP;
    int fullHP;//满血
    double speed;
    int normspeed;//正常速度

    double timeline=0;
    Point coor;
    int money=15;
    QImage virus,light;//出现时自带炫光

    static int life;//肺的寿命
    static int whichmap;//地图判断
};

#endif // ENEMY_H
