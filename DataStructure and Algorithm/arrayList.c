/*WAP to show array implementation of Lists in C */

#include<stdio.h>
#include<stdlib.h>

#define NUMNODES 5

typedef struct nodetype{
    int data,next;
}Node;

Node node[NUMNODES];
int avail = 0;

int main(){
    initList();
    while(1){
        int option, data, p;
        printf("\nEnter option (1 for Insert, 2 for Delete): ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter node after which you want to insert: ");
                scanf("%d",&p);
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insertAfter(p, data);
                break;
            case 2:
                printf("Enter the node you want to delete: ");
                scanf("%d",&p);
                deleteAfter(p);
                break;
            default:
                printf("!Wrong input selected!\n");
                break;
        }
        traverse();
    }
    return 0;
}

void initList(){
    for(int i=0; i<NUMNODES;i++)
        node[i].next = i+1;
    node[NUMNODES-1].next=-1;
}

int getNode(){
    int p;
    if(avail=-1){
        printf("%d!Overflow!\n",avail);
        exit(EXIT_FAILURE);
    }
    p=avail;
    avail = node[avail].next;
    return p;
}

void freeNode(int p){
    node[p].next= avail;
    avail = p;
    return;
}

void insertAfter(int p, int data){
    int q;
    if(p==-1){
        printf("Insertion Failed!\n");
        return;
    }
    q=getNode();
    node[q].data=data;
    node[q].next=node[p].next;
    node[p].next=q;
    return;
}

void deleteAfter(int p){
    int q,deletedData;
    if(p==-1||node[p].next==-1){
        printf("!Deletion Failed!\n");
        exit(EXIT_FAILURE);
    }
    q=node[p].next;
    deletedData = node[q].data;
    node[p].next=node[q].next;
    freeNode(q);
    return deletedData;
}

void traverse(){
    int p=0;
    for(int i=0; i<NUMNODES; i++)
        printf(" |%d|%d|",node[i].data, node[i].next);
    printf("\n");
    do{
        printf(" -> %d", node[p].data);
        p=node[p].next;
    }while(p!=0);
    printf("\n");
}