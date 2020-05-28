#include "map2.h"

Point Map2::translate(int d)
{
    int x=0,y=420;//初始坐标
    if(d>=70){//分段函数处理
        d-=70;x+=70;
        if(d>=280){
            d-=280;y-=280;
            if(d>=140){
               d-=140;x+=140;
               if(d>=280){
                   d-=280;y+=280;
                   if(d>=70){
                       d-=70;x+=70;
                       if(d>=140){
                           d-=140;y-=140;
                           if(d>=210){
                               d-=210;x+=210;
                               if(d>=140){
                                   d-=140;y+=140;
                                   if(d>=70){
                                       d-=70;x+=70;
                                       if(d>=280){
                                           d-=280;y-=280;
                                           if(d>=140){
                                               d-=140;x+=140;
                                               if(d>=280){
                                                   d-=280;y+=280;x+=d;
                                                   if(d>70){Point p;return p;}
                                               }else y+=d;
                                           }else x+=d;
                                       }else y-=d;
                                   }else x+=d;
                               }else y+=d;
                           }else x+=d;
                       }else y-=d;
                   }else x+=d;
               }else y+=d;
            }else x+=d;
        }else y-=d;
    }else x+=d;
    Point p(x,y);
    return p;
}
