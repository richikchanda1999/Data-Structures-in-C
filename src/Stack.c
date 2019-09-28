#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <limits.h>
void push(Stack **s, int x) {
	insertAtEnd(&((*s)->top), x);
}

int pop(Stack **s) {
	return (deleteIndex(&((*s)->top), size(&((*s)->top)) - 1));
}

int peekFromStack(Stack *s) {
	if(s->top == NULL) return INT_MIN;
	Node *temp = nthNodeEnd(&(s->top), 1);
        return (temp->x);
}
