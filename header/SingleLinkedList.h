#ifndef TEST
#define TEST
typedef struct node {
        int x;
        struct node* next;
} Node;

int isCircle(Node **);
Node* createNode(int x);
int insertAtPos(Node **head, int x, int index);
void insertAtEnd(Node **head, int x);
void insertAtBeg(Node **head, int x);
Node* searchKey(Node **head, int x);
Node* searchIndex(Node** head, int index);
int deleteKey(Node **head, int x);
int deleteIndex(Node **head, int index); 
void deleteList(Node **head);
void addLists(Node **, Node **);
Node* nthNode(Node **head, int n);
Node* nthNodeEnd(Node **head, int n);
int size(Node **head);
Node* midElement(Node **, Node **); 
int printList(Node *head);
Node *reverseList(Node **head); 
#endif
