#include<stdio.h>
#include<graphics.h>

void ellipse(int,int,int,int);

int main(){
    int a,b,h,k;
    printf("Ente the value of a and b: ");
    scanf("%d %d",&a,&b);
    printf("Enter the center of the ellipse: ");
    scanf("%d %d",&h,&k);
    ellipse(a,b,c,d);
}

void ellipse(int a,int b, int h, int k){
    int pk,xk,yk;
    xk=0;
    yk=b;
    pk=(b*b)-(a*a*b)+((a*a)/4);
    while(b*b*xk<a*a*yk)
}