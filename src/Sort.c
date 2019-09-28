#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int m , int n) {
	int temp = (*a)[m];
	(*a)[m] = (*a)[n];
	(*a)[n] = temp;
}

void bubbleSort(int **a, int n) {
	int s = 0;
	int i, j;
	for(i = 0 ; i < n - 1 ; i++) {
		for(j = 0 ; j < n - i - 1 ; j++) {
			if((*a)[j] > (*a)[j+1]) { 
				swap(a, j, j+1);
				s++;
			}
		}
	}
	printf("No. of swaps : %d\nNo. of comparisons : %d\n", s, s);
}

void selectionSort(int **a, int n) {
	int s = 0, c = 0;
	int i, j;
	for(i = 0 ; i < n ; i++) {
		int small = i;
		for(j = i + 1 ; j < n ; j++) {
			if((*a)[j] < (*a)[small]) {
				small = j;
				c++;
			}
		}
		if(small != i) {
			swap(a, small, i);
			s++;
		}
	}
	printf("No. of swaps : %d\nNo. of comparisons : %d\n", s, c);
}

void insertionSort(int **a, int n) {
	int s = 0;
	int i;
	for(i = 1 ; i < n ; i++){
		int j = i;
		while((*a)[j] < (*a)[j-1] && j) {
			s++;
			swap(a, j , j - 1);
			j--;
		}
	}
	printf("No. of swaps : %d\nNo. of comparisons : %d\n", s, s);
}
int g_s = 0;
int g_c = 0;
int partition(int **a, int low, int high) {
	int pivot = (*a)[high];
	while(1) {
		while(high >= 0 && (*a)[high] > pivot) {
			high--;
			g_c++;
		}
		while(low <= high && (*a)[low] < pivot) {
			low++;
			g_c++;
		}
		if(low <= high) {
			swap(a, low, high);
			g_s++;
			high--;
			low++;
		} else break;
	}
	return high;
}

void merge(int **arr, int low1, int high1, int low2, int high2) {
	int *a = *arr;
	int *temp = (int *) malloc(sizeof(int) * ((high1 - low1 + 1) + (high2 - low2 + 1)));
	int i = low1;
	int j = low2;
	int k = 0;
	while(i <= high1 && j <= high2) temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	while(i <= high1) temp[k++] = a[i++];
	while(j <= high2) temp[k++] = a[j++];
	for(k = 0 ; k < ((high1 - low1 + 1) + (high2 - low2 + 1)) ; k++) a[k + low1] = temp[k];
	free(temp);
	/*int i = 0, j = 0;
	int *a = (int *) malloc(sizeof(int) * (n1 + n2);
	while(i < n1 && j < n2) a[i + j] = (a1[i] < a2[j]) ? a1[i++] : a2[j++];
	while(i < n1) a[i + j] = a1[i++];
	while(j < n2) a[i + j] = a2[j++];
	return a;*/
}

void mergeSort(int **a, int low, int high) {
	if(low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, mid, mid + 1, high);
	}
}

void quickSort(int **a, int low, int high) {
	if(low < high) {
		int index = partition(a, low, high);
		quickSort(a, low, index);
		quickSort(a, index + 1, high);
	}
}
