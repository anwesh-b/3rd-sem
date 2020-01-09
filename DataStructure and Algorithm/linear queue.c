/* WAP to illustrate array implementation
of Linear Queue in C.*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;

void enqueue(int);
int dequeue();
int is_full();
int is_empty();
void traverse();

int main(){
    int option, item;
    while(1){
        printf("Enter option (0 for enqueue and 1 for dequeue)");
        scanf("%d",&option);

        switch(option){
            case 0:
                printf("Enter an item to enqueue: ");
                scanf("%d",&item);
                enqueue(item);
                traverse();
                break;
            case 1:
                printf("Dequeued item: %d\n", dequeue());
                traverse();
                break;
            default:
                printf("!Invalid option!");
                break;
        }
    }
    return 0;
}

int is_full(){
    if(rear >= (SIZE-1) ){
        printf("Queue Overflow\n");
        return 1;
    }
    return 0;
}

int is_empty(){
    if(rear < front){
        printf("Queue Underflow\n");
        return 1;
    }
    return 0;
}

void enqueue(int item){
    if(!is_full())
        queue[++rear]=item;
    else
        exit(EXIT_FAILURE);
}

int dequeue(){
    if(!is_empty())
        return queue[front++];
    exit(EXIT_FAILURE);
}
void traverse(){
    if(!is_empty()){
        printf("Queue :");
        for(int i=front; i<=rear; i++)
            printf("\t%d",queue[i]);
        printf("\n");
    }
}