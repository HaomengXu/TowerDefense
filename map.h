#ifndef MAP_H
#define MAP_H

#include"point.h"
class Map
{
public:
    Map(){lenth=18;}
    static Point translate(const int);//敌人行进距离转换为坐标
    int getLenth() const{return lenth;}
    int getRoad(const int i,const int j) const{return road[i][j];}

protected:
    int lenth;//路径长度
private:
    int road[18][2]={{1,2},{1,3},{1,4},{1,5},{2,5},{3,5},
                     {4,5},{4,4},{5,4},{6,4},{7,4},{7,5},
                     {8,5},{9,5},{10,5},{10,4},{10,3},{10,2}};
};

#endif // MAP_H
