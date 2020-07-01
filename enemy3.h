#ifndef ENEMY3_H
#define ENEMY3_H

#include <QPainter>
#include "enemy.h"
class Enemy3:public Enemy{
public:
    Enemy3(){fullHP=HP=500;speed=1.5;money=35;picLoad();
             virus.load("://image/virus3.png");
            }
    ~Enemy3(){}
    Enemy3(const Enemy3 &e){
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
    //void show(QPainter &);
    void reSpeed(){speed=1.5;slowice=0;}
};

#endif // ENEMY3_H
