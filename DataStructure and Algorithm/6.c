/*WAP to illustrate array implementation of Stack
with all the operations in C. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int stack[SIZE];
int top=-1;
int is_empty();
int is_full();
int push(int);
int pop();
void display();

int main(){
    int item,option;
    while(1){
        printf("\n enter operation (0 for push and 1 for pop)");
        scanf("%d", &option);
        switch(option){
            case 0:
                printf("enter item to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 1:
                printf("popped item:%d \n",pop());
                break;
            default:
                printf("invalid operation");
                break;
        }
        display();
    }
    return 0;
}

int is_empty(){
    if(top<0){
        printf("stack underflow\n");
        return 1;
    }
    return 0;
}

int is_full(){
    if(top==SIZE-1){
        printf("stack overflow\n");
    return 1;
    }
    return 0;
}

int push(int item){
    if(! is_full()){
        top++;
        stack[top]=item;
    }
    else
        exit(EXIT_FAILURE);
}

int pop(){
    if(! is_empty())
        return stack[top--];
    else
        exit(EXIT_FAILURE);
}

void display(){
    int i;
    for(i=0;i<SIZE;i++)
        printf("_");
    printf("\n");
    for(i=0;i<SIZE;i++)
        printf("| %d",stack[i]);
    printf("\n");
    for(i=0;i<SIZE;i++)
        printf("");
}