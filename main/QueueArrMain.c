#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int enqueue(int **, int *, int, int);
int dequeue(int **, int *, int *);
int peek(int **, int *, int *);

int main() {
	printf("Enter maximum capacity : ");
	int cap;
	scanf("%d", &cap);

	int *a = (int *) malloc(cap * sizeof(int));
	int front = 0, rear  = -1;
	do {
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nEnter your choice : ");
		int ch, x, ret;
		scanf("%d", &ch);

		switch(ch) {	
			case 1: printf("Enter element to add : ");
				scanf("%d", &x);
				ret = enqueue(&a, &rear, cap, x);
				if(ret == INT_MIN) printf("Queue is full!\n");
				else printf("Element is added!\n");
				break;

			case 2: ret = dequeue(&a, &front, &rear);
				if(ret == INT_MIN) printf("Queue is empty!\n");
				else printf("Element deleted is : %d", ret);
				break;

			case 3: ret = peek(&a, &front, &rear);
				if(ret == INT_MIN) printf("Queue is empty\n");
				else {
					printf("Element at the front is : %d\n", ret);
					printf("All the elements in the queue are : ");
					int i = front-1;
					while(++i <= rear) printf("%d, ", *(a + i));
					printf("\n");
				}

			case 4: break;
			default : printf("Wrong choice!\n");
		}
		if(ch == 4) {
			free(a);
			break;
		}
		printf("\n");
	}while(1);
	return 0;
}
