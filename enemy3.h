#ifndef ENEMY3_H
#define ENEMY3_H

#include <QPainter>
#include "enemy.h"
class Enemy3:public Enemy{
public:
    Enemy3(){fullHP=HP=500;speed=1.5;slowice=0;fired=0;money=35;
             virus.load("://image/virus3.png");light.load("://image/Light.png");
                  ice.load("://image/ice.png");fire.load("://image/fire.png");
             if(whichmap==1){coor.setX(70);coor.setY(140);}
             else{coor.setX(0);coor.setY(280);}
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
        fired=e.fired;
    }
    //void show(QPainter &);
    void reSpeed(){speed=1.5;slowice=0;}
};

#endif // ENEMY3_H
