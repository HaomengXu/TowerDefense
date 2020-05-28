#include "tower3.h"

void Tower3::show(QPainter & painter){//三个等级图片的加载
    QBrush brush(QColor(255, 255, 255), Qt::Dense5Pattern);
    if(level==1)tower.load("://image/doctor.png");
    else if(level==2)tower.load("://image/doctor2.png");
    else tower.load("://image/doctor3.png");
    //根据塔的等级绘制子弹
    if(bullet.getX()>0){
        if(level==1){brush.setColor(Qt::yellow);painter.setPen(QPen(Qt::yellow,4));}
        else if(level==2){brush.setColor(Qt::green);painter.setPen(QPen(Qt::green,4));}
        else {brush.setColor(Qt::red);painter.setPen(QPen(Qt::red,4));}
        painter.setBrush(brush);
        this->bullet.show3(painter,coor);
    }
    //塔的绘制
    painter.drawImage(coor.getX(),coor.getY(), tower);
}

int Tower3::Attack(Point viruscoor){
    if(coor.dis(viruscoor)<=range){//判断射程范围内
        if(timerID>=interval+40)return 2;//判断是否攻击成功
        return 1;
    }
    return 0;
}

int Tower3::Attack(){
    if(timerID==interval-1){timerID++;return 1;}//发出声效
    else if(timerID>=interval){
        if(timerID<interval+20){//发射扩展动画
            bullet.setX(35+coor.getX()+range*(double)(timerID-interval)/20);
        }else bullet.setX(35+coor.getX()+range);//维持一段时间
        bullet.setY(35+coor.getY());
    }else{bullet.setX(-1);bullet.setY(-1);}//停止攻击
    if(timerID>=interval+40)timerID=30;//恢复，子弹重新上膛，准备新一轮攻击
    timerID++;//时间标志+1
    return 0;
}
