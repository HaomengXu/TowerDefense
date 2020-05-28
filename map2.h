#ifndef MAP2_H
#define MAP2_H

#include"map.h"
class Map2:public Map
{
public:
    Map2(){lenth=32;}
    static Point translate(const int);//敌人行进距离转换为坐标
    int getRoad(const int i,const int j) const{return road[i][j];}

private:
    int road[32][2]={{0,6},{1,6},{1,5},{1,4},{1,3},{1,2},{2,2},{3,2},
                     {3,3},{3,4},{3,5},{3,6},{4,6},{4,5},{4,4},{5,4},
                     {6,4},{7,4},{7,5},{7,6},{8,6},{8,5},{8,4},{8,3},
                     {8,2},{9,2},{10,2},{10,3},{10,4},{10,5},{10,6},{11,6}};
};

#endif // MAP2_H
