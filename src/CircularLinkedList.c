#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"
#include <limits.h>

Node* createNode(int x) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode -> x = x;
	newNode -> next = NULL;
	return newNode;
}

int printList(Node *head) {
	if(head == NULL) return INT_MIN;
	else {
		printf("-->");
		Node *temp = head;
		while(temp->next != head) {
			printf("%d --> ", temp -> x);
			temp = temp->next;
		}
		printf("%d --> \n", temp->x);
	}
	return INT_MAX;
}

int insertAtPos(Node** head, int x, int index) {
	Node* newNode = createNode(x);
	if (index < 0) return INT_MIN;
	if(*head == NULL && index > 0) return INT_MIN;
	if(*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return INT_MAX;		
	}
	else if (index == 0) {
		Node *temp = *head;
		while(temp->next != *head) temp = temp->next;
		newNode->next = *head;
		temp->next = newNode;
		*head = newNode;
		return INT_MAX;
	}
	else {
		Node *temp = *head;
		while(--index && temp->next != *head) temp = temp->next;
		if(index > 0) return 0;	
		else {
			newNode->next = temp->next;
			temp->next = newNode;
			return INT_MAX;
		}
	}
}

void insertAtBeg(Node **head, int x) {
	insertAtPos(head, x, 0);
}

void insertAtEnd(Node **head, int x) {
	Node* newNode = createNode(x);
	if(*head == NULL) {
		newNode->next = newNode;
		*head = newNode;		
	}
	else {
		Node *temp = *head;
		while(temp->next != *head) temp = temp->next;
		newNode->next = *head;
		temp->next = newNode;
	}
}

int deleteKey(Node **head, int x) {
	if(*head == NULL) return INT_MIN;
	Node *temp = *head;
	if(temp->x == x) {
		if(temp->next != *head) {
			while(temp->next != *head) temp = temp->next;
			*head = (*head)->next;
			temp->next = temp->next->next;
		}
		else *head = NULL;
		//free(temp);
		return INT_MAX;
	}
	Node *temp1 = temp -> next;
	while(temp1 != NULL) {
		if(temp1->x == x) {
			temp->next = temp1->next;
			return INT_MAX;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}
	return INT_MIN;
}

int deleteIndex(Node **head, int index) {
	if(*head == NULL) return INT_MIN;
	Node *temp = *head;
	Node *temp1 = temp -> next;

	if(index == 0) return deleteKey(head, temp->x);

	while(--index && temp1->next != *head) {
		temp = temp->next;
		temp1 = temp1->next;
	}

	if(index > 0) return INT_MIN;
	else {
		temp->next = temp1->next;
		return INT_MAX;
	}
}

Node* searchKey(Node** head, int x) {
	if(*head == NULL) return NULL;
	Node *temp = *head;
	do {
		if(temp->x == x) return temp;
		temp = temp->next;
	}while(temp != *head);
	return NULL;
}

Node* searchIndex(Node** head, int index) {
	if(*head == NULL || index < 0) return NULL;
	if(index == 0) return *head;
	Node *temp = *head;
	do {
		temp = temp->next;
		if(temp == *head) return NULL;
	}while(--index);
	if(!index) return temp;
	else return NULL;
}

void deleteList(Node **head) {
	while(*head != NULL) deleteIndex(&(*head), 0);
}

Node* nthNode(Node **head, int n) {
	return (searchIndex(head, n - 1));
}

Node* nthNodeEnd(Node **head, int n) {
	if(*head == NULL) return NULL;
	Node *temp = *head;
	Node *temp1 = nthNode(head, n);
	if(temp1 != NULL) {
		while(temp1 -> next != *head) {
			temp = temp -> next;
			temp1 = temp1 -> next;
		}
		return temp;
	}
	else return NULL;
}

Node* midElement(Node **head) {
	if(*head == NULL) return NULL;
	Node *p = *head;
	Node *q;
	if(p -> next != *head) q = p -> next;
	else return NULL;
	while(1) {
		p = p->next;
		int ctr = 2;
		while(ctr--) {
			if(q->next != *head) q = q->next;
			else return p;
		}
	}
}

int size(Node **head) {
	if(*head == NULL) return INT_MIN;
	int size = 0;
	Node *temp = *head;
	do {
		size++;
		temp = temp -> next;
	}while(temp != *head);
	return size;
}

Node *reverseList(Node **head) {
	if(*head == NULL) return NULL;
	Node *newHead = NULL;
	Node *temp = *head;
	do{
		insertAtBeg(&newHead, temp->x);
		temp = temp->next;
	}while(temp != *head);
	return newHead;
}
