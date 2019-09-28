#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

int main() {
	CircularQueue *q;
	q->front = NULL;
	q->rear = NULL;
	
	do {
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. No. of elements\n5. Exit\nPlease enter your choice : ");
		int ch, x, ret;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter element to be enqueued : ");
				scanf("%d", &x);
				enqueue(&q, x);
				break;

			case 2: ret = dequeue(&q);
				if(ret != INT_MIN) printf("Dequeued element : %d\n", ret);
				else printf("Queue is empty!\n");
				break;

			case 3: ret = peek(q);
				if(ret != INT_MIN) {
					printf("Element in the front is : %d\n", ret);
					printf("Present state of queue is : ");
					printList(q->front);
				}
				else printf("Queue is empty!\n");
				break;

			case 4: ret = length(q);
				if (ret != INT_MIN) printf("No. of elements are : %d\n", ret);
				else printf("No element in the queue!\n");
			case 5: break;
			default: printf("Oops! Wrong choice!\n");
		}

		if(ch == 5) break;
		printf("\n");
	}while(1);

	return 0;
}
