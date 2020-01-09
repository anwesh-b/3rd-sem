#include<stdio.h>
#include<math.h>

float f(float x){
    return pow(x,3)-(4*x)-9;
}

int main(){
    float a,b,m,e;
    printf("Enter the value of a and b :");
    scanf("%f %f",&a,&b);
    printf("Enter the tolerance level : ");
    scanf("%f",&e);
    do{
        m=(a+b)/2;
        if(f(m)<0.0){
            a=m;
        }
        else{
            b=m;
        }
        printf("\n%f\t%f\t%f\t%f",a,b,m,f(m));
    }while(fabs(a-b)>e);
    printf("\n%f",m);
    return 0;
}