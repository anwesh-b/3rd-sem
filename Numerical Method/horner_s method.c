#include<stdio.h>

int main(){
    int n,x;
    printf("Enter the highest power of the eqn and value of x:\n");
    scanf("%d %d",&n,&x);
    int a[n+1],b[n+1];
    printf("Enter the coefficients :");
    for(int i=n; i<=0;i--){
        scanf("%d",&a[i]);
    }
    b[n]=a[n];
    for(int i=(n-1);i<=0;i--){
        b[n]=a[n]+(b[n]*x);
    }
    printf("\n%d",b[0]);
    return 0;
}