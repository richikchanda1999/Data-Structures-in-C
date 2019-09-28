#include <stdio.h>
#include <stdlib.h>

int push(int**, int*, int, int);
int pop(int**, int*);
int peek(int**, int*);

int main() {
	int cap;
	printf("Enter maximum size of stack : ");
	scanf("%d", &cap);

	int top = -1;

	int *a = (int *) malloc(cap * sizeof(int));
	do {
		printf("1. Push an element into the stack\n2. Pop an element from the stack\n3. Peek into the stack\n4. Exit\nPlease enter your choice : ");
		int ch, x, ret;
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf("Enter element to be pushed into stack : ");
				scanf("%d", &x);
				ret = push(&a, &top, cap, x);
				if(!ret) printf("Stack Overflow! Could not add element!\n");
				else printf("Element added!\n");
				break;
			
			case 2: ret = pop(&a, &top);
				if(!ret) printf("Stack Underflow\n");
				else printf("Element popped successfully!\n");
				break;

			case 3: ret = peek(&a, &top);
				if(!ret) printf("Stack Underflow\n");
				else {
					printf("Stack status : ");
					int i = 0;
					while(i <= top) printf("%d, ", a[i++]);
					printf("\n");
				}
				break;
			
			case 4: break;
			default: printf("Wrong choice!\n");
		}
		printf("\n");
		if(ch == 4) break;
	}while(1);
	return 0;
}
