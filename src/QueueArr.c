#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int enqueue(int **a, int *rear, int cap, int x) {
	if(*rear == cap - 1) return INT_MIN;
	(*a)[++(*rear)] =  x;
	return INT_MAX;
}

int dequeue(int **a, int *front, int *rear) {
	if(*front > *rear) return INT_MIN; 
	return ((*a)[(*front)++]);
}

int peek(int **a, int *front, int *rear) {
	if(*front > *rear) return INT_MIN;
	return ((*a)[*front]);
}
