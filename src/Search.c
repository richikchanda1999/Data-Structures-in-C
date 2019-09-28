#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *a, int low, int high, int x) {
	while(low <= high) if(a[low++] == x) return (low - 1);
	return -1;
}

int binarySearch(int *a, int low, int high, int x) {
	//int comparison = 0;
	while(low <= high) {
	//	comparison++;
		int mid = low + (high - low)/2;
		if(a[mid] == x) {
	//		printf("No. of comparisons : %d\n", comparison);
			return mid;
		}
		else if(a[mid] > x) high = mid - 1;
		else low = mid + 1;
	}
	//printf("No. of comparisons : %d\n", comparison);
	return -1;
}

void floorCeiling(int *a, int n, int x) {
	int low = 0;
	int high = n - 1;

	while(low <= high) {
		int mid = low + (high - low)/2;
		if(a[mid] == x) {
			printf("Floor = %d, Ceiling = %d\n", a[mid], a[mid]);
			return;
		}
		else if(a[mid] > x) high = mid - 1;
		else low = mid + 1;
	}
	if(high % n == high && high >= 0) printf("Floor = %d, ", a[high]);
	else printf("Floor not present in array, ");
	if(low % n == low && low >= 0) printf("Ceiling = %d\n", a[low]);
	else printf("Ceiling is not present in array!\n");
}

int find(int *a, int n) {
	int i = 1;
	for(; i < n - 1 ; i++) {
		int j = 0;
		for(; j < i ; j++) if(a[i] < a[j]) break;
		int k;
		for(k = i + 1 ; k < n ; k++) if(a[i] > a[k]) break;
		printf("Element considered : %d\tj : %d, k : %d\n", a[i], j, k);
		if(j == i && k == n) return i;
	}
	return -1;
}

int oddOne(int *a, int low, int high) {
    while(low <= high) {
    	        if(low == high) return low;
        int mid = low + (high - low) / 2;
        if(a[mid] != a[mid + 1] && a[mid] != a[mid - 1]) return mid;
        if(mid % 2 == 0) {
            if(a[mid] == a[mid + 1]) low = mid + 2;
            else high = mid - 2;
        } else {
            if(a[mid] == a[mid - 1]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}
