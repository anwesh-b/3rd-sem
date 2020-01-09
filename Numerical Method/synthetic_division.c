//synthetic divison
#include<stdio.h>
int main(){
    int n,c,r;
    printf("Enter the max power of a");
    scanf("%d",&n);
    int a[n],b[n+1];
    b[n]=0;
    printf("Enter the value of c");
    scanf("%d",&c);
    printf("Enter all the coefficients:\n");
    for(int i=n;i>=0;i--){
        scanf("%d",&a[i]);
    }   
    for(int i=n;i>0;i--){
        b[i-1]=a[i]+(c*b[i]);
    }
    r=a[0]+(b[0]*c);
    printf("\nRemainder = %d\n",r);
    for(int i=(n-1);i>=0;i--){
        printf("%d",b[i]);
        if(i!=0)
            printf("x^%d+",i);
    }
    return 0;
}