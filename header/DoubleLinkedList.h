typedef struct node {
        int x;
        struct node* prev;
        struct node* next;
} Node;

Node* createNode(int x);
int insertAtPos(Node **head, int x, int index);
void insertAtBeg(Node **head, int x);
void insertAtEnd(Node **head, int x);
int printList(Node *head);
Node* searchKey(Node** head, int x); 
Node* searchIndex(Node** head, int index); 
int deleteKey(Node **head, int x);
int deleteIndex(Node **head, int index); 
void deleteList(Node **head);
Node* nthNode(Node **head, int n); 
Node* nthNodeEnd(Node **head, int n); 
int size(Node **head);
Node* midElement(Node **head); 
Node *reverseList(Node **head);
