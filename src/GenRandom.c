#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int *genArr(int n) {
	int *a = (int *) malloc(n * sizeof(int));

	int i = 0;
	for(; i < n ; i++) {
		srand(time(NULL));
		a[i] = (int) (rand() % n);
	}
	return a;
}

int isPrime(int n) {
	if (n == 1) return 0;
	if (n % 2 == 0 && n != 2) return 0;
	if (n == 2) return 1;
	int i = 3;
	for(; i * i < n ; i++) if(n % i == 0) return 0;
	return 1;
}

int *genUniqueArr(int x) {
	int y = 2 * x + 1;
	while(!isPrime(y)) y += 2;
	int i = 1;
	int *a = (int *) malloc(sizeof(int) * x);
	srand(time(NULL));
	/*while(i <= x) {
		if(((i * i) % y) != 0) {
			a[i - 1] = (i * i) % y;
			if(rand() % x != 0) a[i - 1] *= (rand() % x);
			//	printf("%d\n", a[i - 1]);
			i++;
		}
		int temp = (i * i) % y;
		int temp2 = (rand() % x);
		if(temp == 0 && temp2 != 0) a[i - 1] = temp2;
		else if(temp != 0 && temp2 != 0) a[i - 1] = temp * temp2;
		else if(temp != 0 && temp2 == 0) a[i - 1] = temp;
		else continue;
	}*/
	int t = 1;
	while(t <= x) {
		if(((i * i) % y) != 0) {
			a[t - 1] = (i * i) % y;
			t++;
		}
		i++;
	}
	return a;
}
