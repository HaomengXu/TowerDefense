#include "enemy.h"

int Enemy::life=10;
int Enemy::whichmap=1;

void Enemy::show(QPainter & painter,bool stop){
    QBrush brush(QColor(255, 255, 255), Qt::Dense1Pattern);
    painter.setPen(QPen(Qt::white,4));
    //坐标判断
    int d=timeline;
    Point p;
    if(whichmap==1)p=map->translate(d);//行进距离转换为坐标
    else p=map2->translate(d);
    int x=p.getX(),y=p.getY();
    if(x<0){if(HP>0)life--;HP=0;}//敌人侵犯成功
    //绘制敌人
    if(HP>0){
        painter.drawImage(x, y, virus);
        if(slowice)painter.drawImage(x, y+35, ice);
        else if(fired>0){
            painter.save();
            painter.setOpacity((double)fired*(double)fired/200/200);
            painter.drawImage(x+3, y+25, fire);
            painter.restore();
            if(fullHP==500&&fired%5==1)HP--;
            fired--;
        }
        coor.setX(x);coor.setY(y);
        //绘制血量
        brush.setColor(Qt::darkGreen);
        painter.setBrush(brush);
        painter.drawRect(x,y-10,52,4);
        painter.setPen(QPen(Qt::lightGray,3));
        painter.drawRect(x+1,y-9,50,2);
        painter.setPen(QPen(Qt::red,3));
        painter.drawRect(x+1,y-9,HP*50/fullHP,2);
        if(timeline<=30){//出现时炫光+渐变效果
            painter.save();
            if(whichmap==1)painter.translate(map->translate(0).getX()+35,map->translate(0).getY()+25);
            else painter.translate(map2->translate(0).getX()+35,map2->translate(0).getY()+25);
            painter.rotate(timeline*10);
            painter.setOpacity(0.9-abs(timeline-10)*0.03);
            painter.drawImage(-40, -40, light);
            painter.restore();
        }
        if(!stop)timeline+=speed;
    }
}
