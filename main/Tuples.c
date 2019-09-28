#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a, int n, int x) {
        int low = 0;
        int high = n - 1;
        //int comparison = 0;
        while(low <= high) {
                //comparison++;
                int mid = low + (high - low)/2;
                if(a[mid] == x) {
                        //printf("No. of comparisons : %d\n", comparison);
                        return mid;
                }
                else if(a[mid] > x) high = mid - 1;
                else low = mid + 1;
        }
        //printf("No. of comparisons : %d\n", comparison);
        return -1;
}

/*typedef struct tuple {
	int a;
	int b;
} Tuple;
*/
void swap(int **a, int**b, int m , int n) {
	int temp = (*a)[m];
	(*a)[m] = (*a)[n];
	(*a)[n] = temp;

	temp = (*b)[m];
	(*b)[m] = (*b)[n];
	(*b)[n] = temp;

}

int partition(int **a, int**b, int low, int high) {
        int pivot = (*a)[high];
        while(1) {
                while(high >= 0 && (*a)[high] > pivot) {
                        high--;
                }
                while(low <= high && (*a)[low] < pivot) {
                        low++;
                }
                if(low <= high) {
                        swap(a, b, low, high);
                        high--;
                } else break;
        }
        return high;
}


void quickSort(int **a, int **b, int low, int high) {
	if(low < high) {
		int index = partition(a, b, low, high);
		quickSort(a, b, low, index);
		quickSort(a, b, index + 1, high);
	}
}


int main() {
	int n;
	//scanf("%d", &n);
	printf("Enter no. of tuples : ");
	scanf("%d", &n);

	int *a = (int *) malloc(n * sizeof(int));
	int *b = (int *) malloc(n * sizeof(int));

	printf("Enter tuples :\n");
	int i;
	
	//Tuple **t = (Tuple **) calloc(n, sizeof(Tuple*));
	for(i = 0 ; i < n ; i++) scanf("%d %d", &a[i], &b[i]);
	printf("Entered tuples are : ");
        for(i = 0 ; i < n ; i++) printf("(%d,%d),", a[i], b[i]);
	quickSort(&a, &b, 0, n - 1);
	printf("\nSorted tuples are : ");
	for(i = 0 ; i < n ; i++) printf("(%d,%d),", a[i], b[i]);
	int ctr = 0;
	printf("\nFollowing pairs have symmetric pairs : ");
	for(i = 0 ; i < n ; i++) {
		int index = binarySearch(b, n, a[i]);
		if(index != -1) {
			if(a[index] == b[i] && a[i] != b[i]) {
				printf("(%d, %d), ", b[i], a[i]);
				ctr++;
			}
		}
	}
	if(ctr == 0) printf("No tuples present!\n");
	else printf("\n");
	
	return 0;
}

