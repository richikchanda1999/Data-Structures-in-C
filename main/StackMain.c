#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include <limits.h>

int main() {
        Stack *s;
	s->top = NULL;
        do{
                printf("1. Push an element into the stack\n2. Pop an element from the stack\n3. Peek into the stack\n4. Exit\nPlease enter a choice : ");
                int ch, x, ret;
                scanf("%d", &ch);

                switch(ch) {
                        case 1: printf("Enter element to be inserted into the stack :");
                                scanf("%d", &x);
                                push(&s, x);
                                printf("Element added successfully!\n");
                                break;

                        case 2: ret = pop(&s);
                                if(!ret) printf("Stack underflow!\n");
                                else printf("Successfully deleted element!\n");
                                break;
        
                        case 3: ret = peekFromStack(s);
				if(ret == INT_MIN) printf("Stack is empty!\n");
				else {
					printf("Element at top : %d\n", ret);
					printf("Stack status : ");
					printList(s->top);
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

