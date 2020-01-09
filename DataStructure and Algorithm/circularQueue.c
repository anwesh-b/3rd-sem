/*WAP to illustrate array implementation
of Circular Queue in C. */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = SIZE-1;
int rear = SIZE-1;

void enqueue(int);
int dequeue();
int is_full();
int is_empty();
void traverse();

int main(){
    int option, item;

    while(1){
        printf("Enter option (0 for enqueue and 1 for dequeue): ");
        scanf("%d",&option);

        switch(option){
            case 0:
                printf("Enter item to enqueue: ");
                scanf("%d",&item);
                enqueue(item);
                traverse();
                break;
            case 1:
                printf("Dequeued item: %d\n",dequeue());
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
    if((front== rear+1)||(front==0 && rear== SIZE-1))
        return 1;
    return 0;
}

int is_empty(){
    if(front == -1) return 1;
    return 0;
}

void enqueue(int item){
    if(!is_full()){
        if(front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = item;
    }
}

int dequeue(){
    int item;
    if(!is_empty()){
        item = queue[front];
        if(front == rear){
            front = -1;
            front = -1;
        }
        else{
            front = (front + 1)% SIZE;
        }
        return item;
    }
    else{
        exit(EXIT_FAILURE);
    }
}

void traverse(){
    if(!is_empty()){
        printf("Queue: ");
        for(int i=((front+1)%SIZE); i!=((rear+1)%SIZE);i=((i+1)%SIZE))
            printf("\t%d",queue[i]);
        printf("\n");
    }
}