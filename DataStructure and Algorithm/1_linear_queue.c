#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0;
int rear = -1;

void enqueue(int);
int dequeue();
int is_full();
int is_empty();
void traverse();

int main({
    int option, item;

    while(1){
        printf("Enter option (0 for enqueue and 1 for dequeue):");
        scanf("%d",&option);

        switch(option){
            case 0:
                printf("Enter an item to enqueue: ");
                scanf("%d",&item);
                enqueue(item);
                traverse();
                break;
            case 1:
                printf("Dequeued item: %d\n\n",dequeue());
                traverse();
                break;
            default:
                printf("!!!Invalid option!!!");
                break;
        }
    }
}


void enqueue(int x){
    if(!is_full()){
        queue[++rear];
        printf("\n%d added in the stack",x);
    }
    exit(EXIT_FAILURE);
}

int dequeue(){
    if(!is_empty()){
        return queue[front++];
    }
    else printf("")
}

int is_full(){
    return (rear>=MAX_SIZE-1)?0:1;
}

int is_empty(){
    return (rear<front)?1:0;
}

void traverse(){
    int i;
    if(!is_empty()){
        printf("FRONT: ");
        for(i= front; i<= rear; i++)
            printf("%d\t",queue[i]);
        printf("\n");
    }
}