#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>

void generateRandom(int **a, int n) {
	*a = (int *) malloc(n * sizeof(int));
	int i = 0;
	srand(time(0));
	for(; i < n ; i++) {
		(*a)[i] = rand() % n;
	}
}

void printArr(int *a, int n) {
	printf("Current state of array ::: \n");
	int i;
	for(i = 0 ; i < n ; i++) {
		printf("%10d", *(a + i));
		if(i % 10 == 0) printf("\n");	
	}
	printf("\n");
}

int main() {
	int *a = NULL;
	int n = 0;
	/*generateRandom(&a, n);
	printf("Elements in the array are : ");
        for(i = 0 ; i < n ; i++) printf("%d, ", *(a + i));
        printf("\n");

	//int *a = (int *) malloc(3 * sizeof(int));
	//a[0] = 1;
	//a[1] = 0;
	//a[2] = 1;
	quickSort(&a, 0, n - 1);
	printf("Elements in the array are : "); 
        for(i = 0 ; i < n ; i++) printf("%d, ", *(a + i));
	printf("\n");*/
	long int start = 0, end = 0;
	start = time(NULL);
	do {
		printf("1. Generate random array\n2. Display array elements\n3. Empty the present array\n4. Sort array using Bubble Sort\n5. Sort array using Selection Sort\n6. Sort array using Insertion Sort\n7. Sort array using Merge Sort\n8. Sort array using Quicksort\n9. Exit\nPlease enter your choice : ");
		int ch;
		char x;
		scanf("%d", &ch);
		if(ch >= 4 && ch <= 8) start = time(NULL);
		switch(ch) {
			case 1: x = 'Y';
				if(a != NULL) {
					printf("Array is not empty! Do you still want to create a new array, (Y/N)? ");
					scanf(" %c", &x);	
				}
				if(x == 'Y') {
					printf("Enter no. of elements in the array : ");
					scanf("%d", &n);
					generateRandom(&a, n);
				}
				break;	 

			case 2: if (a != NULL) printArr(a, n);
				else printf("There are no elements in the array!\n");
				break;

			case 3: if(a != NULL) {
					free(a);
					a = NULL;
					n = 0;
				} else printf("There are no elements to delete!\n");
				break;

			case 4: bubbleSort(&a, n);
				break;

			case 5: selectionSort(&a, n);
				break;

			case 6: insertionSort(&a, n);
				break;

			case 7: mergeSort(&a, 0, n - 1);
				break;

			case 8: quickSort(&a, 0, n - 1);
				break;

			case 9: break;
			default: printf("Wrong choice!\n");
		}	
		if(ch >= 4 && ch <= 8) {
			end = time(NULL);
			printArr(a, n);
			printf("Time taken : %ld seconds\n", (end - start));
		}
		if(ch == 9) break;		
	}while(1);
	return 0;
}
