#ifndef ENEMY2_H
#define ENEMY2_H

#include <QPainter>
#include "enemy.h"
class Enemy2:public Enemy{
public:
    Enemy2(){fullHP=HP=150;speed=2;slowice=0;fired=0;money=25;
             virus.load("://image/virus2.png");light.load("://image/Light.png");
                  ice.load("://image/ice.png");fire.load("://image/fire.png");
             if(whichmap==1){coor.setX(70);coor.setY(140);}
             else{coor.setX(0);coor.setY(280);}
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
        fired=e.fired;
    }
    void show(QPainter &,bool);
    void reSpeed(){speed=2;slowice=0;}
};

#endif // ENEMY2_H
