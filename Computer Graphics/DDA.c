#include<stdio.h>
#include<graphics.h>
#include<math.h>
void DDAline(int x1, int y1, int x2,int y2){
    int dx,dy, steps,i;
    float inc_x, inc_y,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = (abs(dx)>abs(dy))?dx:dy;
    inc_x = (float)dx / steps;
    inc_y = (float)dy / steps;
    putpixel(round(x1),round(y1),15);
    x=x1;
    y=y1;
    for(i=1;i<=steps;i++){
        x+=inc_x;
        y+=inc_y;
        putpixel(round(x),round(y),15);
    }
}

int main(){
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    ddaline(10,20,150,180);
    closegraph();
    return 0;
}