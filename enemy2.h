#ifndef ENEMY2_H
#define ENEMY2_H

#include <QPainter>
#include "enemy.h"
class Enemy2:public Enemy{
public:
    Enemy2(){fullHP=HP=150;speed=2;money=25;picLoad();
             virus.load("://image/virus2.png");
            }
    ~Enemy2(){}
    Enemy2(const Enemy2 &e){
        HP=e.HP;fullHP=e.fullHP;
        speed=e.speed;slowice=e.slowice;
        timeline=e.timeline;
        coor=e.coor;
        money=e.money;
        virus=e.virus;
        light=e.light;
        ice=e.ice;fire=e.fire;
        fired=e.fired;dietime=e.dietime;
    }
    void show(QPainter &,bool);
    void reSpeed(){speed=2;slowice=0;}
};

#endif // ENEMY2_H
