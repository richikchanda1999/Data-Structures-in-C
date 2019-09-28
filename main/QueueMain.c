#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*void enqueue(Node **, Node **, int);
int dequeue(Node **);
int peek(Node *);*/

int main() {
        Queue *q = (Queue *) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
        do {
                printf("1. Enqueue\n2. Dequeue\n3. Peek an element from the queue\n4. Exit\nPlease enter choice : ");
                int ch, x, ret;
                scanf("%d", &ch);

                switch(ch) {
                        case 1: printf("Enter element to add : ");
                                scanf("%d", &x);
                                enqueue(&q, x);
                                break;

                        case 2: ret = dequeue(&q);
                                if(!ret) printf("No elements in queue!\n");
                                break;

                        case 3: ret = peekFromQueue(q);
                                if(ret == INT_MIN) printf("No element in the queue!\n");
				else {
					printf("Element at the popping end is : %d\n", ret);
					printf("Queue status is : ");
					printList(q->front);
				}
                                break;

                        case 4: break;
                        default: printf("Wrong choice!\n");
                }
                if(ch == 4) break;
                printf("\n");
        }while(1);
}
