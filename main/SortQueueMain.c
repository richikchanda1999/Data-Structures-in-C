#include "Stack.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void buildQueue(Queue **);
int canAscending(Queue **, Stack **, Queue **);

int main() {
	Stack *s = (Stack *) malloc(sizeof(Stack));
        Queue *q = (Queue*) malloc(sizeof(Queue));
	Queue *Q = (Queue *) malloc(sizeof(Queue));
	
	q->front = NULL;
	q->rear = NULL;
        s->top = NULL;
        Q->front = NULL;
	Q->rear = NULL;
	
	buildQueue(&q);
	
	clock_t begin = clock();
	int ret = canAscending(&q, &s, &Q);
	clock_t end = clock();
	double elapse = (double) (end - begin);
	printf("Time taken : %lf\n", elapse);
	if (!ret) printf("\nOops! It cannot be arranged!\n");
	else {
		printf("Yaay! It can be arranged!\nThe arrangement will be : ");
		dequeue(&Q);
		dequeue(&Q);
		printList(Q->front);
	}

	return 0;
}

