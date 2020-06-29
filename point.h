#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include<cmath>
class Point{
public :
    Point(int xx = -1, int yy = -1) {
            _x = xx;
            _y = yy;
    }
    Point(const Point &p){_x=p.getX();_y=p.getY();}

    void show(QPainter & painter) const{if(_x>0)painter.drawRect(_x-1,_y-1,3,3);}//子弹1
    void show2(QPainter & painter){//子弹2
        bullet.load("://image/mask-bullet.png");
        if(_x>0)painter.drawImage(_x-15,_y-15, bullet);
    }
    void show3(QPainter & painter,const Point &c) const{//子弹3
        double d=dis(c);
        painter.drawEllipse(c.getX()+35-d, c.getY()+35-d, 2*d, 2*d);
    }

    double dis(const Point &p) const{//距离
        return sqrt((_x-p.getX())*(_x-p.getX())+(_y-p.getY())*(_y-p.getY()));
    }
    double getX() const{return _x;}
    double getY() const{return _y;}
    void setX(const double x){_x=x;}
    void setY(const double y){_y=y;}

private:
    double _x;
    double _y;
    QImage bullet;
};

#endif // POINT_H
