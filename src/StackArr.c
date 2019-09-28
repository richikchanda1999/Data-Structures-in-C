#include <stdio.h>
#include <stdlib.h>
int push(int **a, int *top, int CAP, int x) {
	if(*top == CAP - 1) return 0;
	*top = *top + 1;	
	(*a)[*top] = x;
	return 1;
}

int pop(int **a, int* top) {
	if(*top == -1) return 0;
	printf("Element popped is %d\n", (*a)[*top]);
	*top = *top - 1;
	return 1;
}

int peek(int **a, int *top) {
	if(*top == -1) return 0;
	printf("Element at top is : %d\n", (*a)[*top]);
	return 1;
}

