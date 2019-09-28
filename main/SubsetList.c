#include <stdio.h>
#include <stdlib.h>
#include "ListOperations.h"
#include "SingleLinkedList.h"

int main() {	
	Node *list1 = NULL;
	Node *list2 = NULL;

	printf("Enter list 1 elements (-1 to terminate) : ");
	while(1) {
		int x;
		scanf("%d", &x);
		if(x < 0) break;
		insertAtEnd(&list1, x);
	}

	printf("Enter list 2 elements (-1 to terminate) : ");
	while(1) {
		int x;
		scanf("%d", &x);
		if (x < 0) break;
		insertAtEnd(&list2, x);
	}
	int list1Size = size(&list1);
	int list2Size = size(&list2);

	Node **part1 = divide(&list1, &list2);
	Node **part2 = divide(&list2, &list1);

	int part10size = size(&part1[0]);
	//int part11size = size(&part1[1]);
	int part20size = size(&part2[0]);
	//int part21size = size(&part2[1]);

	if(list1 != NULL && list2 != NULL) {
		if(part10size == part20size) {
			if(part10size == list1Size) printf("Yes, List 1 is the subset of List 2\n");
			else if (part20size == list2Size) printf("Yes, List 2 is the subset of List 1\n");
			else printf("No, neither is a subset of each other!\n");
		}
		else printf("No, neither is a subset of each other!\n");
	} else printf("No elements entered, cannot check!\n");
	return 0;
}
