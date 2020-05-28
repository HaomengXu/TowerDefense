#ifndef ENEMY4_H
#define ENEMY4_H

#include <QPainter>
#include "enemy.h"
class Enemy4:public Enemy{
public:
    Enemy4(){fullHP=HP=2500;normspeed=speed=1;money=80;
             virus.load("://image/virus4.png");light.load("://image/Light.png");
             if(whichmap==1){coor.setX(70);coor.setY(140);}
             else{coor.setX(0);coor.setY(280);}
            }
    ~Enemy4(){}
    Enemy4(const Enemy4 &e){
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

#endif // ENEMY4_H
