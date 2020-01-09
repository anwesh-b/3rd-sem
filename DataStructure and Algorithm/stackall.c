#include<stdio.h>
#define MAX 5
int stack[5],top=-1;

void push(int x);
int pop();
int is_full();
int is_empty();
void display();

int main(){
    int item, option;
    while(1){
        printf("\nEnter operation (0 for PUSH and 1 for POP): ");
        scanf("%d",&option);
        switch(option){
            case 0:
                printf("Enter item to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 1:
                printf("Popped item: %d\n",pop());
            default:
                printf("Invalid option selected!!!");
                break;
        }
        display();
    }
    return 0;
}


void push(int x){
    if(is_full()==1){
        printf("\nStack is full. Couldnot push");
    }
    else{
        stack[++top] = x;
        printf("\n%d added in stack\n\nTop = %d",stack[top],top);
    }
}

int pop(){
    if(is_empty()==1){
        printf("\nStack is empty, couldnot pop");
        return 0;
    }
    else{
        return stack[top--];
    }
}

int is_empty(){
    if(top < 0){
        printf("Stack underflow!!\n");
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(){
    if(MAX-1 == top){
        printf("Stack overflow!!!");
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    printf("The elements of stack is :\n");
    // for(int i=(MAX-1);i>=0;i--){
    //     printf("\n%d",stack[i]);
    // }
    
    for(int i=0;i<(MAX*4)+1;i++)
        printf("_");
    printf("\n");
    for(int i=0;i<MAX;i++)
        printf("| %d ",stack[i]);
    printf("|\n");
    for(int i=0;i<(MAX*4)+1;i++)
        printf("-");
}