#include <limits.h>
#include "CircularLinkedList.h"

typedef struct circularqueue {
	Node *front;
	Node *rear;
} CircularQueue;

void enqueue(CircularQueue **, int);
int dequeue(CircularQueue **);
int peek(CircularQueue *);
int length(CircularQueue *);

