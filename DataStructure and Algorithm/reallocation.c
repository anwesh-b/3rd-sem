/* 3. WAP to show that realloc() can only reallocate the
memory that was dynamically allcated in C */

#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, a[2], *p, *p_new, option;
    printf("[1] Initialize with static allocation\n");
    printf("[2] Initialize with dynamic allocation\n");
    printf("Choose option: ");
    scanf("%d",&option);
    switch (option){
        case 1:
            p = a;
            a[0] =10;
            a[1] =20;
            break;
        case 2:
            p = (int *)calloc(2, sizeof(int));
            *p = 10;
            *(p+1) = 20;
            break;
        default:
            printf("Invalid Option!");
            break;
    }
    if(*p==NULL){
        printf("Memory not allocated");
    }
    else{
        p_new = (int *)realloc(p, 3*sizeof(int));
        *(p_new + 2) = 30;

        for(i=0; i<3; i++){
            printf("%d\n", *(p_new + i));
        }
    }
    return 0;
}