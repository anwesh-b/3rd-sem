//1. Demonstrate that complexity of the program changes as per the algorithm design techniques imposed, using C

#include<stdio.h>
#include<time.h>
long fib_a(int);
long fib_b(int);

int main(){
    int x;
    double a,b,c,d,timeByRec,timeByDP;
    printf("Enter any number for fibo = ");
    scanf("%d",&x);
    a=clock();
    printf("\nUsing recursion fib of %d = %ld ",x,fib_a(x));
    b=clock();
    c=clock();
    printf( "\nUsing loop fib of %d = %ld ",x,fib_b(x));
    d=clock();
    timeByRec =(b-a)/(double)CLOCKS_PER_SEC;
    timeByDP = (d-c)/(double)CLOCKS_PER_SEC;
    printf("\nTime By Rec = %lf", timeByRec);
    printf("\nTime By DC = %lf", timeByDP);
    return 0;
}

long fib_a(int n){
    if(n==0||n==1){
        return 1;
    }
    else{
        return fib_a(n-1)+fib_b(n-2);
    }
}

long fib_b(int n){
    long f[n];
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-2]+f[i-1];
    }
    return f[n];
}