#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {
	Node *front = NULL;
	Node *rear = NULL;
	do{
		printf("1. Push an element into the stack\n2. Pop an element from the stack\n3. Peek into the stack\n4. Exit\nPlease enter a choice : ");
		int ch, x, ret;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter element to be inserted into the stack :");
				scanf("%d", &x);
				enqueue(&front, &rear, x);
				break;

			case 2: if(front == NULL) printf("Stack underflow!\n");
				else { 
					Node *frontTemp = NULL;
					Node *rearTemp = NULL;
					while(front->next != NULL) {
						enqueue(&frontTemp, &rearTemp, front->x);
						dequeue(&front);
					}
					front = frontTemp;
					rear = rearTemp;
					printf("Successfully deleted element!\n");
				}
				break;

			case 3: ret = peek(front);
				if(ret == INT_MIN) printf("Stack is empty!\n");
				else {
					printf("Element at top : %d\n", ret);
					printf("Status of Stack : ");
					printList(front);
					printf("\n");
				}
				break;

			case 4: break;
			default: printf("Wrong choice!\n");
		}

		if(ch == 4) break;
		printf("\n");
	}while(1);
}

