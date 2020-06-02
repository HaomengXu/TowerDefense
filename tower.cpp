#include "tower.h"
#include <QtCore/qmath.h>

void Tower::show(QPainter & painter){//三个等级图片的加载
    QBrush brush(QColor(255, 255, 255), Qt::Dense1Pattern);
    if(level==1)tower.load("://image/injection.png");
    else if(level==2)tower.load("://image/injection2.png");
    else tower.load("://image/injection3.png");
    //旋转角度的判断
    double direct_x=35+coor.getX()-bullet.getX(),direct_y=35+coor.getY()-bullet.getY();
    if(bullet.getX()>0){
        if(abs(direct_x)>abs(direct_y)){
            theta=qAtan(direct_y/direct_x)*180/3.1416;
            if(direct_x>0)theta+=180;
        }else{
            theta=-90-qAtan(direct_x/direct_y)*180/3.1416;
            if(direct_y<0)theta+=180;
        }
    }
    painter.save();
    painter.translate(35+coor.getX(),35+coor.getY());
    painter.rotate(theta-135);
    painter.drawImage(-35,-35, tower);
    painter.restore();
    //painter.rotate(-theta+135);
    //painter.translate(-coor.getX()-35,-coor.getY()-35);
    //根据塔的等级绘制子弹
    if(level==1)painter.setPen(QPen(Qt::yellow,4));
    else if(level==2)painter.setPen(QPen(Qt::green,4));
    else painter.setPen(QPen(Qt::red,4));
    this->bullet.show(painter);
}

int Tower::Attack(const Point viruscoor){
    if(coor.dis(viruscoor)<=range){//射程内判断
        if(timerID==interval){timerID++;return 1;}//发出声效
        if(timerID>20+interval){timerID=5;bullet.setX(-1);bullet.setY(-1);return 3;}//子弹再次上膛，延时发射
        if(timerID>=interval+2){//子弹坐标的设定
            bullet.setX(35+coor.getX()+(viruscoor.getX()-coor.getX())*(double)(timerID-interval)/20);
            bullet.setY(35+coor.getY()+(viruscoor.getY()-coor.getY())*(double)(timerID-interval)/20);
        }
        timerID++;return 2;//时间标志+1
    }else{bullet.setX(-1);bullet.setY(-1);}//停止攻击
    return 0;
}
