#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *head = NULL;

int main() {
  int option, item, pos;
  while (1) {
    printf("[1] Node Insertion: Beginning\n");
    printf("[2] Node Insertion: End\n");
    printf("[3] Node Insertion: Specified Position\n");
    printf("[4] Node Deletion: Beginning\n");
    printf("[5] Node Deletion: End\n");
    printf("[6] Node Deletion: Specified Position\n");
    printf("[7] Show Length of the List\n");
    printf("[8] Search for an item\n");
    printf("Choose Option: ");
    scanf("%d", &option);
    switch (option) {
    case 1:
      printf("Enter item to insert at the beginning: ");
      scanf("%d", &item);
      insertBeg(item);
      break;
    case 2:
      printf("Enter item to insert at the end: ");
      scanf("%d", &item);
      insertEnd(item);
      break;
    case 3:
      printf("Enter position where you want to insert: ");
      scanf("%d", &pos);
      printf("Enter item to insert : ");
      scanf("%d", &item);
      insertAt(pos, item);
      break;
    case 4:
      deleteBeg();
      break;
    case 5:
      deleteEnd();
      break;
    case 6:
      printf("Enter position where you want to delete: ");
      scanf("%d", &pos);
      deleteAt(pos);
      break;
    case 7:
      printf("Length of the List: %d", getLength());
      break;
    case 8:
      printf("Enter item to search: ");
      scanf("%d", &item);
      search(item);
      break;
    default:
      printf("Invalid Option Selected!\n");
      break;
    }
    if (option < 7 && option > 0)
      traverse();
  }
  return 0;
}

Node *getNode() { return (Node *)malloc(sizeof(Node)); }

int getLength() {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  return count;
}

void traverse() {
  Node *temp = head;

  if (getLength() == 0) {
    printf("\nList is Empty!\n");
    return;
  }

  printf("\nHEAD");
  while (temp != NULL) {
    printf(" -> %d", temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}

void insertBeg(int item) {
  Node *newNode = getNode();

  newNode->data = item;
  newNode->next = head == NULL ? NULL : head;
  head = newNode;
}

void insertEnd(int item) {
  Node *temp, *newNode = getNode();

  newNode->data = item;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
  } else {
    temp = head;

    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void insertAt(int pos, int item) {
  Node *temp, *newNode = getNode();

  if (pos > getLength()) {
    printf("Position Overflow!");
    return;
  }

  newNode->data = item;
  if (pos == 0) {
    newNode->next = head == NULL ? NULL : head;
    head = newNode;
  } else {
    temp = head;

    for (int i = 1; i < pos; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void deleteBeg() {
  Node *temp;

  if (head == NULL) {
    printf("Deletion Failed!\n");
    return;
  }
  temp = head;
  head = head->next;
  free(temp);
}

void deleteEnd() {
  Node *temp;

  if (head == NULL) {
    printf("Deletion Failed!\n");
    return;
  }
  temp = head;

  if (head->next == NULL) {
    head = NULL;
    free(temp);
  } else {
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
  }
}

void deleteAt(int pos) {
  Node *temp, *p;

  if (head == NULL) {
    printf("Deletion Failed!\n");
    return;
  }
  temp = head;

  if (pos == 0) {
    head = temp->next;
    free(temp);
    return;
  }

  for (int i = 1; i < pos; i++) {
    temp = temp->next;
  }
  p = temp->next;
  temp->next = p->next;
  free(p);
}

void search(int key) {
  Node *temp = head;
  while (temp->next != NULL) {
    if (temp->data == key) {
      printf("Key = %d Found", key);
      return;
    }
    temp = temp->next;
  }
  printf("Key = %d Not Found!", key);
}