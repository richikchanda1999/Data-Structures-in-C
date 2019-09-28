#include <stdio.h>
#include <stdlib.h>
int n;

void heapify(int *arr,int i,int n)
{
	int lc,rc,max;
	lc=2*i+1;
	rc=2*i+2;
	while(lc<=n)
	{
		if(lc==n)
			max=lc;
		else
			max=arr[lc]>arr[rc]?lc:rc;
		if(arr[max]<arr[i])
			break;
		int temp=arr[max];
		arr[max]=arr[i];
		arr[i]=temp;
		i=max;
		lc=2*max+1;
		rc=2*max+2;
	}
}

int delete(int *arr)
{
	if(n==0)
		return -1;
	arr[0]=arr[n-1];
	n=n-2;
	heapify(arr,0,n);
	n++;
	return 0;
}

void print(int *arr, int n)
{
        int i;
        for(i = n - 1 ; i >= 0 ; i--)
                printf("%d  ",arr[i]);
        printf("\n");
}

int *heapsort(int *arr,int m)
{
	int *a = (int *) malloc(sizeof(int) * m);
	int i;
	for(i=0;i<m;i++)
	{
		a[i] = arr[0];
		printf("%d  ",arr[0]);
		delete(arr);		
	}
	//print(a, m);
	return a;
}

/*void print(int *arr)
{
	int i;
	for(i = n - 1 ; i >= 0 ; i--)
		printf("%d  ",arr[i]);
	printf("\n");
}*/

int main()
{
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int *a = (int *) malloc(sizeof(int) * n);

	printf("Enter the elements : ");
	int i;
	for(i=0;i<n;i++) scanf("%d", a + i);

	for(i=(n-2)/2;i>=0;i--)	heapify(a,i,n-1);
	printf("The sorted array in descending order is : ");
	a = heapsort(a , n);
	print(a, n);
	return 0;
}
