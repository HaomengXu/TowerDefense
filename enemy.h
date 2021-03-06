#ifndef ENEMY_H
#define ENEMY_H

#include <QMediaPlayer>
#include "point.h"
#include"map.h"
#include"map2.h"
//#include <QMessageBox>
class Enemy{
public:
    Enemy():fullHP(100){HP=fullHP;speed=1;picLoad();
                                  virus.load("://image/virus1.png");
                        }
    virtual ~Enemy(){/*QMessageBox::information(NULL,"~Enemy","die");*/}
    Enemy(const Enemy &e){
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
    void picLoad(){
        slowice=0;fired=0;dietime=0;
        light.load("://image/Light.png");
        ice.load("://image/ice.png");fire.load("://image/fire.png");
        if(whichmap==1){coor.setX(70);coor.setY(140);}
        else{coor.setX(0);coor.setY(280);}//坐标初始化
    }

    void slowSpeed(const int k){if(speed>=1){//减速算法
            if(k==1)speed*=0.7;
            else if(k==2)speed*=0.49;
            else if(k==3)speed*=0.3;
            slowice=1;
        }
    }
    void reSpeed(){speed=1;slowice=0;}//速度恢复
    bool getAct() const{return HP>0 ? 1 : 0;}//病毒活性检测，判断是否析构
    void reduceHP(const int blood){HP-=blood;if(HP<0)HP=0;}//减血

    int getMap() const{return whichmap;}//地图判断
    void setMap(const int m){whichmap=m;}
    void setFire(){fired=400;}
    void reset(){life=10;whichmap=1;}//重置数据

    Point getCoor() const{return coor;}
    int getLife() const{return life;}
    int getMoney() const{return money;}
    double getTime() const{return timeline;}
    bool getDie()const{return dietime==70 ? 1 : 0 ;}//是否演示完死亡动画
    bool startDie(){return dietime==2 ? 1:0;}//是否开始演示死亡动画，便于音效展示

protected:
    int HP;
    int fullHP;//满血
    double speed;
    bool slowice;
    int fired,dietime;

    double timeline=0;
    Point coor;
    int money=15;
    QImage virus,light;//出现时自带炫光
    QImage ice,fire;//减速灼烧效果图
    QImage die;//死亡动画顺序加载

    static int life;//肺的寿命
    static int whichmap;//地图判断
    static Map *map;
    static Map2 *map2;
};

#endif // ENEMY_H
