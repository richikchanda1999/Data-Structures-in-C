#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Stack.h"

int main() {
	Node *top = NULL;
	do {
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice : ");
		int ch, x , ret;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter element to be inserted : ");
				scanf("%d", &x);
				push(&top, x);
				break;

			case 2: if(top != NULL) {
					Node *topTemp = NULL;
					while(top->next != NULL) {
						push(&topTemp, peek(top));
						pop(&top);
					}
					free(top);
					top = NULL;
					while(topTemp != NULL) {
						push(&top, peek(topTemp));
						pop(&topTemp);
					}
					printf("Element successfully deleted!\n");
				} else printf("Queue is empty!\n");
				break;

			case 3: if(top != NULL) {
					printf("Element at front end : %d\n", top -> x);
					Node *temp = top;
					printf("Queue status is : ");
					while(temp != NULL){
						printf("%d, ", temp -> x);
						temp = temp -> next;
					}
					printf("\n");
				} else printf("Queue is empty!\n");
		
			case 4: break;
			default: printf("Wrong choice!\n");
		}
		if(ch == 4) break;
		printf("\n");
	}while(1);
	return 0;
}
