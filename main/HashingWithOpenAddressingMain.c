#include <stdio.h>
#include <stdlib.h>
#include "GenRandom.h"
#include "HashingWithOpenAddressing.h"

int main() {
	do{
		printf("1. Hashing with Linear Probing\n2. Hashing with Quadratic Probing\n3. Double Hashing\n4. Print current Hash Table\n5. Exit\nPlease enter your choice : ");
		int ch;
		scanf("%d", &ch);
		int N, M, *a, *hashTable, j, collision = 0;
		//if(hashTable != NULL) free(hashTable);
		if(ch >= 1 && ch <= 3) {
			printf("Enter no. of elements to be inserted : ");
			scanf("%d", &N);
			do{
				printf("Enter size of Hash Table : ");
				scanf("%d", &M);
				if(M >= N) break;
				else printf("Please enter a size more than the no. of elements!\n");
			}while(1);
			a = genUniqueArr(N);
			printf("Generated random numbers are : ");
			for(j = 0; j < N  ; j++) printf("%d ", a[j]);
			printf("\n"); 

			hashTable = createHashTable(M);
		}
		
		switch(ch) {
			case 1: for(j = 0; j < N ; j++) {
					if(hashTable[hash(a[j], M)] != -1) collision++; 
					insertLP(a[j], M, hashTable);
					printf("Inserted : %d\n", a[j]);
				}
				printf("All integers inserted successfully!\n");
				printf("Collisions suffered : %d\n", collision);
				printf("Null slots : %d\n", calcNullSlots(hashTable, M));
				break;

			case 2: for(j = 0; j < N ; j++) {
                                        if(hashTable[hash(a[j], M)] != -1) collision++;
                                        insertQP(a[j], M, hashTable);
                                        printf("Inserted : %d\n", a[j]);
                                }
                                printf("All integers inserted successfully!\n");
                                printf("Collisions suffered : %d\n", collision);
                                printf("Null slots : %d\n", calcNullSlots(hashTable, M));
                                break;

			case 3: for(j = 0 ; j < N ; j++) insertDH(a[j], M, hashTable);
				printf("All integers inserted successfully!\n");
				printf("Null slots : %d\n", calcNullSlots(hashTable, M));
				break;
			
			case 4: printHashTable(hashTable, M);
				break;
			
			case 5: break;
		}
		if(ch == 5) break;
	}while(1);
	return 0;
}
