//Stacks
#include<stdio.h>
#define MAX 5
int stack[5],top=-1;
int pop();
void push(int x);
// void pop();
int is_full();
int is_empty();
void display();

int main(){
    int i,arr[5];
    printf("Enter the elements of array");
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    // pop();
    push(arr[top]);
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
    if(top-1 == -1){
        return 1;
    }
    else {
        return 0;
    }
}

int is_full(){
    if(MAX == top-1){
        return 1;
    }
    else{
        return 0;
    }
}