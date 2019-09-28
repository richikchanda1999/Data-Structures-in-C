#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int size = 0;

int enqueue(int **a,int *rear, int cap, int x) {
	if(size < cap) {
		*rear = (*rear + 1) % cap;
		(*a)[*rear] = x;
		size++;
		return INT_MAX;
	}
	return INT_MIN;
}

int dequeue(int **a, int *front, int cap) {
	if(size != 0) {
		int temp = (*a)[*front];
		*front = (*front + 1) % cap;
		size--;
		return temp;
	}
	return INT_MIN;
}

int peek(int **a, int *front) {
	if(size != 0) return (*a)[*front];
	return INT_MIN;
}

void length() {
	printf("No. of elements in queue is : %d\n", size);
}
