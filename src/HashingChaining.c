#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

int hash(int k, int M) {
	return (k % M);
}

Node **createHashTable(int M) {
	Node **ht = (Node **) malloc(sizeof(Node *) * M);
	int i = 0;
	for(; i < M ; i++) *(ht + i) = NULL;
	return ht;
}

void insert(int key, int M, Node **hashTable) {
	int h = hash(key, M);
	insertAtEnd(&(*(hashTable + h)), key);
}

int search(int key, int M, Node **hashTable) {
	int h = hash(key, M);
	Node *temp = *(hashTable + h);
	do{
		if(temp == NULL) return -1;
		if(temp->x == key) return 1;
		temp = temp->next;
	}while(1);
}
