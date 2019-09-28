#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct node {
        int x;
        struct node* next;
} Node;

int isCircle(Node **head);
Node* createNode(int);
int printList(Node *head);
int insertAtPos(Node** head, int x, int index); 
void insertAtBeg(Node **head, int x);
void insertAtEnd(Node **head, int x);
int deleteKey(Node **head, int x);
int deleteIndex(Node **head, int index);
Node* searchKey(Node** head, int x);
Node* searchIndex(Node** head, int index);
void deleteList(Node **head);
Node* nthNode(Node **head, int n);
Node* nthNodeEnd(Node **head, int n);
Node* midElement(Node **head);
int size(Node **head);
Node *reverseList(Node **head);
#endif
