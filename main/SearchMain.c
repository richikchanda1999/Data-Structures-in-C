#include <stdio.h>
#include <stdlib.h>
#include "Search.h"
#include <time.h>

int main() {
	do {
		printf("1. Perform Binary Search\n2. Find floor and ceiling\n3. Find pivot if present\n4. Find odd pair\n5. Exit\nPlease enter your choice : ");
		int ch;
		scanf("%d", &ch);

		if(ch != 5) {
			int n;
			printf("Enter size of array : ");
			scanf("%d", &n);

			int *a = (int *) malloc(sizeof(int) * n);
			printf("Enter array elements : ");
			int i = 0;
			for(; i < n ; i++) scanf("%d", a + i);
			int index, x;
			switch(ch) {
				case 1: printf("Enter number to be searched : ");
					scanf("%d", &x);
					int start = time(NULL);
					index = binarySearch(a, 0, n - 1, x);
					int end = time(NULL);
					printf("Time taken : %d seconds\n", end - start);
					if(index == -1) printf("Element not found\n");
					else printf("Element found at index %d\n", index);
					
					break;

				case 2: printf("Enter x : ");
					scanf("%d", &x);
					floorCeiling(a, n, x);
					break;

				case 3: index = find(a, n);
					if(index == -1) printf("No such element exists!\n");
					else printf("Pivot is : %d\n", a[index]);
					break;
			
				case 4: index = oddOne(a, 0, n - 1);
					if(index == -1) printf("No such element exists!\n");
					else printf("Odd one is : %d\n", a[index]);
					break;

				case 5: break;					
			}
		} else break;
	}while(1);
	return 0;
}
