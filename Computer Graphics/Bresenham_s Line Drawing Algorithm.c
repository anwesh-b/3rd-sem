#include<stdio.h>
#include<graphics.h>
#include<math.h>
void DDAtime(int x1, int y1, int x2,int y2){
    int dx,dy, steps,i;
    float inc_x, inc_y,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = (abs(dx)>abs(dy))?dx:dy;
    inc_x = dx / steps;
    inc_y = dy / steps;
    putpixel(round(x1),round(y1),1);
    x=x1;
    y=y1;
    for(i=1;i<=steps;i++){
        x+=inc_x;
        y+=inc_y;
        putpixel(round(x),round(y),1);
    }
    return 0;
}