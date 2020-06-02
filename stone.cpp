#include "stone.h"

void Stone::show(QPainter &painter)
{
    QBrush brush(QColor(255, 255, 255), Qt::Dense1Pattern);
    painter.setPen(QPen(Qt::white,4));
    //绘制障碍物
    int x=coor.getX(),y=coor.getY();
    if(HP>0){
        painter.drawImage(x+2, y-7, trash);
        if(target==1)painter.drawImage(x+15, y+15, tar);//绘制靶心标志
        //绘制血量
        if(HP!=fullHP){
            brush.setColor(Qt::darkGreen);
            painter.setBrush(brush);
            painter.drawRect(x+4,y,62,4);
            painter.setPen(QPen(Qt::lightGray,3));
            painter.drawRect(x+5,y+1,60,2);
            painter.setPen(QPen(Qt::darkGreen,3));
            painter.drawRect(x+5,y+1,HP*60/fullHP,2);
        }
    }
}
