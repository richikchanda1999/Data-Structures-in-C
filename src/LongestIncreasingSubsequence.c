#include <stdio.h>
#include <stdlib.h>

int lis(int *a, int n) {
	int i;
	int max = 0;
	for(i = 1; i < n ; i++) {
		int j = i - 1, m = 0;
		while( j >= 0) {
			if((a[j] < a[j + 1]) && (a[j] < a[i])) m++;
			j--;
		}
		if (m > max) max = m;
	}
	return (max + 1);
}

int main() {
	int n;
	printf("Enter size : ");
	scanf("%d", &n);

	int *a = (int *) malloc(sizeof(int) * n);
	int i = 0;
	printf("Enter elements : ");
	for(; i < n ; i++) scanf("%d", a + i);
	int l = lis(a, n);
	printf("No. of elements to be deleted : %d\n", n - l);
	return 0;
}
