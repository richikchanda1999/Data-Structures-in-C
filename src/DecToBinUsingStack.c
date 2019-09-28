#include <stdio.h>
#include <stdlib.h>
#include <Stack.h>
#include <limits.h>

int main() {
	int n;
	printf("Enter a number : ");
	scanf("%d", &n);
	
	Stack *s;
	s->top = NULL;

	while(n > 0) {
		push(&s, n % 2);
		n /= 2;
	}

	printf("Binary Number is : ");
	while(1) {
		int x = peekFromStack(s);
		if(x == INT_MIN) break;
		else printf("%d", x);
		pop(&s);
	}
	printf("\n");
	return 0;
}
