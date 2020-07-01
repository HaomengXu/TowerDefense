#include "tower2.h"

void Tower2::show(QPainter & painter){//三个等级图片的加载
    QBrush brush(QColor(255, 255, 255), Qt::Dense1Pattern);
    if(level==1)tower.load("://image/facemask.png");
    else if(level==2)tower.load("://image/facemask2.png");
    else tower.load("://image/facemask3.png");
    //塔的绘制
    painter.drawImage(coor.getX(),coor.getY(), tower);
    //根据塔的等级绘制子弹
    /*if(level==1)painter.setPen(QPen(Qt::yellow,4));
    else if(level==2)painter.setPen(QPen(Qt::green,4));
    else painter.setPen(QPen(Qt::red,4));*/
    this->bullet.show2(painter);
}

int Tower2::Attack(Point viruscoor){
    if(coor.dis(viruscoor)<=range){//射程内判断
        if(timerID>=interval){//子弹坐标的设定
            if(timerID>=25+interval){//敌人身上停留一段时间
                bullet.setX(35+viruscoor.getX());bullet.setY(35+viruscoor.getY());
            }else{//子弹发射过程
                bullet.setX(35+coor.getX()+(viruscoor.getX()-coor.getX())*(double)(timerID-interval)/25);
                bullet.setY(35+coor.getY()+(viruscoor.getY()-coor.getY())*(double)(timerID-interval)/25);
            }
            if(timerID==interval){timerID++;return 1;}//发出声效
        }
        if(timerID>40+interval){timerID=5;bullet.setX(-1);bullet.setY(-1);return 3;}//子弹再次上膛，延时发射
        timerID++;return 2;//时间标志+1
    }else{bullet.setX(-1);bullet.setY(-1);}//停止攻击
    return 0;
}

bool Tower2::reSpeedjud(Point viruscoor){//恢复速度
    if(coor.dis(viruscoor)<=range+2)return 1;//判断是否刚刚离开射程
    return 0;
}
