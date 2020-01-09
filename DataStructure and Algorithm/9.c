//WAP to evaluate Postfix Expression.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define N 30

int v[N];
int top=-1;
int evaluatePostfix(char *);
int calc(char,int,int);
int isOperator(char);
int is_empty();
int is_full();
void push(int);
int pop();

int main(){
    char expr[N];
    printf("enter postfix expression: ");
    scanf("%s",expr);
    printf("evaluated result =%d\n",evaluatePostfix(expr));
    return 0;
}

int evaluatePostfix(char *expr){
    int i=0,op1,op2;
    char item=expr[i];
    while(item!='\0'){
        if(isdigit(item)){
            push(item-'0');
        }
        else if(isOperator(item)){
            op2=pop();
            op1=pop();
            push(calc(item,op1,op2));
        }
        else{
            printf("Invalid postfix expression");
            exit(EXIT_FAILURE);
        }
        item=expr[++i];
    }
    return pop();
}

int calc(char symbol,int op1,int op2){
    switch(symbol){
        case '^':
            return (int)pow(op1,op2);
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        default:
            printf("Invalid symbol detected!");
            exit(EXIT_FAILURE);
}}

int isOperator(char symbol){
    switch(symbol){
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            return 1;
        default:
            return 0;
}}

int is_empty(){
    if(top<0){
        printf("stack underflow\n");
        return 1;
    }
    return 0;
}

int is_full(){
    if(top==N-1){
        printf("stack overflow\n");
        return 1;
    }
    return 0;
}

void push(int item){
    if(! is_full()){
        top++;
        v[top]=item;
    }
    else
        exit(EXIT_FAILURE);
}

int pop(){
    if(! is_empty())
        return v[top--];
    else
        exit(EXIT_FAILURE);
}