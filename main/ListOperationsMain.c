#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"
#include "ListOperations.h"

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
	
	findUnion(&list1, &list2);
	findIntersection(&list1, &list2);

	return 0;
}
