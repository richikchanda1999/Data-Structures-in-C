#include "SingleLinkedList.h"

typedef struct queue{
	Node *front;
	Node *rear;
} Queue;

void enqueue(Queue **, int);
int dequeue(Queue **);
int peekfromQueue(Queue *);

