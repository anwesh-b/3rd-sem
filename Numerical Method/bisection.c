/* 
Algorithm to find root using Bisection Method
Step-1: Start
Step-2: Choose a and b such that f(a)<0 and f(b)>0
Step-3: Take tolerance value e
Step-4: m = (a+b)/2
Step-5: Calculate f(m), if f(m)<0
                            a=m
                        else
                            b=m
Step-6: Absolute Error |a-b|
            if |a-b|<e
                print the root is m
            else
                goto step 5
Step-7: End
*/

#include<stdio.h>
#include<math.h>

float f(float x){
    return (3*x*x)-(6*x)+2;
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
    }while(fabs(a-b)>e);
    printf("%f",m);
    return 0;
}