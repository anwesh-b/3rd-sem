/*
Algorithm for Newton Rapson Method
Step-1: Start
Step-2: Enter initial guess x0 and Enter tolerance value e
Step-3: Calculate: x1 = x0-(f(x0/df(x0)))
Step-4: If | x0 - x1| <e
        print x1 is a root
        else goto step 3
Step-5: Stop

*/

#include<stdio.h>
#include<math.h>

float f(float x);
float df(float x);

int main(){
    float x0,x1,e,temp;
    printf("Enter the initial guess and tolerance value:");
    scanf("%f %f",&x0, &e);
    do{
        temp = x0;
        x1 = x0-(f(x0)/df(x0));
        x0 = x1;
    }while(fabs(temp-x1)>=e);
    printf("Root = %f",x0);
    return 0;
}


float f(float a){
    return pow(a,3)-(5*a)+3;
}

float df(float a){
    return (3*pow(a,2))-5;
}