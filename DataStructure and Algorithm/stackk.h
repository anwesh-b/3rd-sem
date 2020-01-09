// #include<stdio.h>
// #define STACK_SIZE 5
// struct stack{
//     char stack[STACK_SIZE];
//     int top;
// }
// typedef struct stack STACK_SIZE;

// int is_empty(STACK *s){
//     if(s->top < 0){
//         printf("Stack underflow!!\n");
//         return 1;
//     }
//     return 0;
// }

// int is_full(STACK *s){
//     if(s->top == STACK_SIZE-1){
//         printf("Stack overflow!!!");
//         return 1;
//     }
//     return 0;
// }

// void push(STACK *s,char item){
//     if(!is_full(s))
//         s-> stack[++s->top] = item;    
// }

// int pop(STACK *s){
//     if(!is_empty(s))
//         return s->stack[s->top--];
// }

// char peek(STACK *s){
//     return s->stack[s->top];
// }

#include<stdio.h>
#define STACK_SIZE 30
struct stack
{
    char stack[STACK_SIZE];
    int top;
};

typedef struct stack STACK;

int is_empty(STACK *s)
{
    if (s -> top < 0)
    {
        printf("Stack Underflow!\n");
        return 1;
    }
    return 0;
}

int is_full(STACK *s)
{
    if (s -> top == STACK_SIZE - 1)
    {
        printf("Stack Overflow! \n");
        return 1;
    }
    return 0;
}
void push(STACK *s, char item)
{
    if (!is_full(s))
    {
        s->stack[++s -> top] = item;
    }
}
char pop(STACK *s)
{
    if (!is_empty(s))
    {
        return s->stack[s->top--];
    }
}
char peek(STACK *s)
{
    return s-> stack[s->top];
}