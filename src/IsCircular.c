#include <stdio.h>
#include <stdlib.h>
//#include "CircularLinkedList.h"
#include "SingleLinkedList.h"
void add(Node **l1, Node **l2) {
	Node *temp = *l1;
	while(temp->next != NULL) temp = temp->next;

	temp->next = *l2;
}

int size(Node **head);


int isCircle(Node **head) {
	if(*head == NULL) return 0;
	Node *p = *head;
	Node *q;
	if(p->next != NULL) q = p->next->next;

	while (p && q && q->next) 
	{ 
		p = p->next; 
		q  = q->next->next; 

		if (p == q) return size(&p);
	}
	return 0; 
}
