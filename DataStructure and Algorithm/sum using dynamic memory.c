/*4. WAP to calculate the sum of N numbers using
dynamic memory allocation */

#include<stdio.h>
#include<conio.h>

int main(){
    int i,*arr,sum=0,N;
    printf("Enter total numbers : ");
    scanf("%d",&N);
    arr = (int*)malloc(N * sizeof(int));
    printf("Enter the numbers:\n");
    for(i=0;i<N;i++){
        scanf("%d",arr+i);
        sum += *(arr+i);
    }
    printf("Sum is : %d",sum);
    return 0;
}