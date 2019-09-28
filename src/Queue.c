#include "Queue.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void enqueue(Queue **q, int x) {
        insertAtEnd(&((*q)->front), x);
        (*q) -> rear = nthNodeEnd(&((*q)->front), 1);
}

int dequeue(Queue **q) {
        int ret = (deleteIndex(&((*q)->front), 0));
	(*q)->rear = nthNodeEnd(&((*q)->front), 1);
	return ret;
}

int peekFromQueue(Queue *q){
	if(q == NULL) return INT_MIN;
	//printf("Not null!\n");
        if(q->front != NULL) return (q -> front -> x);
        return INT_MIN;
}
