#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
#include "HashingWithChaining.h"
//#include "SortLinkedList.h"

int isPrime(int n) {
	if(n == 2) return 1;
	if(n == 1 || (n % 2 == 0)) return -1;
	int i = 2;
	for(; i * i <= n ; i++) if(n % i == 0) return -1;
	return 1;
}

int getPrime(int n) {
	if(n % 2 == 0) n++;
	while(isPrime(n) == -1) n += 2;
	return n;
}

Node** toHashTable(Node **list) {
	int s = getPrime(size(list));
	Node **hashTable = createHashTable(s);
	Node *temp = *list;
	while(temp != NULL) {
		insert(temp->x, s, hashTable);
		temp = temp -> next;
	}
	return hashTable;
}

//Method which will separate List1 into two parts, where,
//Part 2 - Elements which are present in List1 and not in List2
//Part 1 - Elements which are present in List1 and in List2
Node** divide(Node **list1, Node **list2) {
	Node **parts = (Node **) malloc(sizeof(Node*) * 2);
	parts[0] = parts[1] = NULL;
	Node **hashTable = toHashTable(list2);
	int s = getPrime(size(list2));
	Node *temp = *list1;
	//int ctr = 0;
	do {
		if(temp == NULL) break;
		int p = search(temp->x, s, hashTable);
		if(p == 1) insertAtEnd(&parts[0], temp->x);
		else if(p == -1) insertAtEnd(&parts[1], temp->x);
		//	ctr++;
		temp = temp->next;	
	}while(1);
	return parts;
	/*if(ctr == 0) printf("No common elements!\n");
	else printf(" <-- Union of the two lists\n");*/
}
