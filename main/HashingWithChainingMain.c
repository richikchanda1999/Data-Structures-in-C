#include <stdio.h>
#include <stdlib.h>
#include "GenRandom.h"
#include "HashingWithChaining.h"
#include "SingleLinkedList.h"

int main() {
	int N;
	printf("Enter no. of random numbers to generate : ");
	scanf("%d", &N);

	int M;
	printf("Enter size of Hash Table : ");
	scanf("%d", &M);

	int *a = genUniqueArr(N);
	int i = 0;
	printf("Generated random numbers are : ");
	for(i = 0 ; i < N ; i++) printf("%d ", a[i]);
	printf("\n");

	Node **hashTable = createHashTable(M);
	int collision = 0;
	for(i = 0; i < N ; i++) {
		//if((*(hashTable + i))->next != NULL) collision++;
		if(*(hashTable + hash(*(a + i), M)) != NULL) collision++;
		insert(*(a + i), M, hashTable);
	}
	printf("No. of collisions : %d\n", collision);

	int null = 0;
	for(i = 0 ; i < M ; i++) {
		if(*(hashTable + i) == NULL) {
			printf("Slot %d : Empty\n", i + 1);
			null++;
		}else {
			//int s = size(hashTable + i);
			printf("Slot %d : ", i + 1);
			printList(*(hashTable + i));
			//printf("Size : %d\n", s);
		}
	}
	printf("Total null slots : %d\n", null);
	return 0;
}
