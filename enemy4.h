#ifndef ENEMY4_H
#define ENEMY4_H

#include <QPainter>
#include "enemy.h"
class Enemy4:public Enemy{
public:
    Enemy4(){fullHP=HP=2500;speed=1;money=80;picLoad();
             virus.load("://image/virus4.png");
            }
    ~Enemy4(){}
    Enemy4(const Enemy4 &e){
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
};

#endif // ENEMY4_H
