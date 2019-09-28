#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "CircularQueue.h"

void enqueue(CircularQueue **q, int x) {
	insertAtEnd(&((*q)->front), x);
	(*q)->rear = nthNodeEnd(&((*q)->front), 1);
}

int dequeue(CircularQueue **q) {
	if((*q)->front != NULL) {
		int temp = (*q)->front->x;
		deleteIndex(&((*q)->front), 0);
		return temp;
	}
	return INT_MIN;
}

int peek(CircularQueue *q) {
	Node *temp = nthNode(&(q->front), 1);
	if(temp != NULL) return (temp->x);
	else return INT_MIN;
}

int length(CircularQueue *q) {
	return (size(&(q->front)));
}

