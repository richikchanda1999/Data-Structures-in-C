#include <stdio.h>
#include <stdlib.h>
#include "MaxHeap.h"

int main() {
	MaxHeapNode *root = NULL;
	do{
		printf("1. Insert element into heap\n2. Print level order\n3. Delete maximum priority element\n4. Exit\nEnter your choice : ");
		int ch;
		scanf("%d", &ch);	
		int x;
		switch(ch) {
			case 1: printf("Enter element to insert : ");
				scanf("%d", &x);
				insert(&root, x);
				break;

			case 2: printf("Level Order is : ");
				levelOrder(&root);
				break;

			case 3: break;
			case 4: break;
		}

		if(ch == 4) break;
	}while(1);
	return 0;
}
