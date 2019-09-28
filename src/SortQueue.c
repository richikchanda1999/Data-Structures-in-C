#include "Stack.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void buildQueue(Queue **q) {
	do {
		printf("1. Enqueue\n2. Dequeue\n3. View Queue\n4. Queue is ready!\nPlease enter your choice : ");
		int ch, x;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter element : ");
				scanf("%d", &x);
				enqueue(q, x);
				break;

			case 2: dequeue(q);
				break;
			case 3: printList((*q)->front);
			case 4: break;
		}
		
		if(ch == 4) break;
		printf("\n");
	}while(1);
}

int canAscending(Queue **q, Stack **s, Queue **Q) {
	push(s, 0);
	int last = 0;
	enqueue(Q, 0);
	while(1) {
		printf("\n");
		printf("Current status of original queue : ");
		printList((*q)->front);
		printf("Current status of stack is : ");
		printList((*s)->top);
		printf("Current status of new queue : ");
		printList((*Q)->front);
		int top = peekFromStack(*s);
		int x = peekFromQueue(*q);
		if(x == INT_MIN) {
			enqueue(Q, top);
			break;
		}
		if(x >= top) {
			pop(s);
			enqueue(Q, top);
			last = top;
			push(s, x);
			dequeue(q);
		}
		else if (x >= last) {
			enqueue(Q, x);
			last = x;	
			dequeue(q);
		} else	return 0;
		
	}
	return 1;
}

