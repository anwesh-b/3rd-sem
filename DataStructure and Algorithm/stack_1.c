#include"stackk.h"
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define N 30

void infixtoppostfix(char *);
int precedence(char);
int isOperation(char);

int main(){
    char expr[N];
    printf("Enter infix expression:");
    scanf("%s",expr);
    infixtoppostfix(expr);
    return 0;
}

void infixtoppostfix(char *expr){
    int i = 0;
    char x, item;
    stack post, op;
    post.top = -1;
    op.top = -1;

    push(&op, '(');
    strcat(expr, ")");

    item = expr[i];
    while(item != '\0'){
        if(item = '('){
            push(&top, item);
        }
        else if(islnum(item)){
            push(&post,item);
        }
        else if(item==')'){
            x = peek(&op);
            while(isOperator(x)){
                
            }
            pop(&op);
        }
        else if(isOperator(item)){
            x = peek(&op);
            while (isOperator(x) && precedence(x) >= precedence(item)){
                x=pop(&op);
                push(&post,x);
                x = peek(&op);
        }
        else {
            printf("INVALID INFIX EXPRESSION!!");
            exit(EXIT_FAILURE);
        }
        item = expr[++i];
    }    
    }
    push(&post, '\0');
    printf("Postfix Expression = %s\n",post.stack);

}