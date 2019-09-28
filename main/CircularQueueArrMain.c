#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int enqueue(int **, int *, int, int);
int dequeue(int **, int *, int);
int peek(int **, int *);
void length();

int main() {
	int front = 0, rear = -1;

	int cap;
	printf("Enter maximum no. of elements in the circular queue : ");
	scanf("%d", &cap);
	
	int *a = (int *) malloc(cap * sizeof(int));

	do {
		printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. View size\n5. Exit\nPlease enter your choice : ");
		int ch, x, ret;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter number to be enqueued : ");
				scanf("%d", &x);
				ret = enqueue(&a, &rear, cap, x);
				if(ret == INT_MIN) printf("Queue is full!\n");
				else printf("Successfully added element!\n");
				break;
	
			case 2: ret = dequeue(&a, &front, cap);
				if(ret == INT_MIN) printf("Queue is empty!\n");
				else printf("Deleted element is : %d\n", ret);
				break;

			case 3: ret = peek(&a, &front);
				if(ret != INT_MIN) printf("Element at the front is : %d\n", ret);
				else printf("Queue is empty!\n");
				break;

			case 4: length();
			case 5: break;
			default: printf("Wrong choice!\n");
		}

		if(ch == 5) break;
		printf("\n");
	}while(1);
	return 0;
}
