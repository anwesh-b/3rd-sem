//WAP to convert Infix expression to Prefix.

#include "stack.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define N 30

void infixToPrefix(char *);
int precendence(char);
int isOperator(char);

int main(){
    char expr[N];
    printf("enter infix expression: ");
    scanf("%s",expr);
    strrev(expr);
    infixToPrefix(expr);
    return 0;
}

void infixToPrefix(char *expr){
    int i=0;
    char x,item;
    STACK post,op;
    post.top=-1;
    op.top=-1;
    push(&op,')');
    strcat(expr,"(");
    item =expr[i];
    while(item != '\0'){
        if(item ==')'){
        push(&op,item);
        }
        else if(isalnum(item)){
            push(&post,item);
        }
        else if(item=='('){
            x=peek(&op);
            while(isOperator(x)){
                x=pop(&op);
                push(&post,x);
                x=peek(&op);
            }
            pop(&op);
        }
        else if(isOperator(item)){
            x=peek(&op);
            while(isOperator(x) && precendence(x)>=precendence(item)){
                x=pop(&op);
                push(&post,x);
                x=peek(&op);
            }
            push(&op,item);
        }
        else{
            printf("invalid inflix expression");
            exit(EXIT_FAILURE);
        }
        item=expr[++i];
    }
    push(&post,'\0');
    printf("%s\n",strrev(post.stack));
}