#include "map.h"

Point Map::translate(int d)
{
    int x=70,y=140;//初始坐标
    if(d>=210){//分段函数处理
        d-=210;y+=210;
        if(d>=210){
            d-=210;x+=210;
            if(d>=70){
               d-=70;y-=70;
               if(d>=210){
                   d-=210;x+=210;
                   if(d>=70){
                       d-=70;y+=70;
                       if(d>=210){
                           d-=210;x+=210;y-=d;
                           if(d>210){Point p;return p;}
                       }else x+=d;
                   }else y+=d;
               }else x+=d;
            }else y-=d;
        }else x+=d;
    }else y+=d;
    Point p(x,y);
    return p;
}
