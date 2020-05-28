#ifndef ENEMY2_H
#define ENEMY2_H

#include <QPainter>
#include "enemy.h"
class Enemy2:public Enemy{
public:
    Enemy2(){fullHP=HP=150;normspeed=speed=2;money=25;
             virus.load("://image/virus2.png");light.load("://image/Light.png");
             if(whichmap==1){coor.setX(70);coor.setY(140);}
             else{coor.setX(0);coor.setY(280);}
            }
    ~Enemy2(){}
    Enemy2(const Enemy2 &e){
        HP=e.HP;fullHP=e.fullHP;
        speed=e.speed;normspeed=e.normspeed;
        timeline=e.timeline;
        coor=e.coor;
        money=e.money;
        virus=e.virus;
        light=e.light;
    }
    void show(QPainter &);
};

#endif // ENEMY2_H
