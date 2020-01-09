/*2. WAP to differentiate static memory allocation with
dynamic memory allocation in C.*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

void staticAllocation();
void dynamicAllocation();

int main(){
    printf("\nStatically Allocated Memory Location: ");
    staticAllocation();

    printf("\nDynamically Allocated Memory Locations: ");
    dynamicAllocation();
    
    return 0;
}

void staticAllocation(){
    int i, a[N];
    for(i=0; i<N; i++){
        printf("\n%d ",&a[i]);
    }    
}

void dynamicAllocation(){
    int i, *p;
    p = (int  *)calloc(N, sizeof(int));
    if(p==NULL){
        printf("Insufficient memory");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<5; i++){
        printf("\n%d ", &p[i]);
    }
}