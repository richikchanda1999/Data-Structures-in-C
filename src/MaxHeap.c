#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MaxHeap.h"

/*typedef struct maxHeap {
	int value;
	struct maxHeap *left;
	struct maxHeap *right;
	struct maxHeap *parent;
} MaxHeapNode;

static int n = 0;
*/
MaxHeapNode *createMaxHeapNode(int x) {
	MaxHeapNode *mhn = (MaxHeapNode *) malloc(sizeof(MaxHeapNode));
	mhn->value = x;
	mhn->left = NULL;
	mhn->right = NULL;
	mhn->parent = NULL;
	return mhn;
}

char *getPath(int m) {
	int i = 0;
	char *path = (char*) malloc(sizeof(char));
	while(1) {
		path[i] = (char) ((m % 2) + 48);
		i++;
		m /= 2;
		if(m > 1) path = (char *) realloc(path, sizeof(char) * (i + 1));
		else break;
	}
	return path;
}

MaxHeapNode *getNode(MaxHeapNode **root, char **p) {
	char *path = *p;
	int l = strlen(path);
	//printf("Length = %d\n", l); 
	MaxHeapNode *temp = *root;
	while(l--) {
		char c = path[l];
		if(c == '0') temp = temp->left;
		else if(c == '1') temp = temp->right;
	}
	return temp;
}

int insert(MaxHeapNode **root, int x) {
	//MaxHeapNode *newNode = createMaxHeapNode(x);
	if(*root == NULL) {
		n++;
		*root = createMaxHeapNode(x);
		return 1;
	}
	n++;
	char *path = getPath(n);
	printf("%s\t", path);
	int l = strlen(path);
	int m = l;
	MaxHeapNode *temp = *root;
	//l--;
	while(--l > 0) {
		char c = path[l];
		if(c == '0') temp = temp->left;
		else if (c == '1') temp = temp->right;
	}
	if(path[0] == '1') {
		temp->right = createMaxHeapNode(x);
		temp->right->parent = temp;
	}
	else if(path[0] == '0') {
		temp->left = createMaxHeapNode(x);
		temp->left->parent = temp;
	}
	//printf("Path followed : %s, Inserted element : %d\n", path, x);
	return 1;
}
	
void levelOrder(MaxHeapNode **root) {
	if(*root != NULL) {
		printf("\nRoot is : %d\n", (*root)->value);
		int i = 2;
		for(; i <= n+1 ; i++) {
			char *path = getPath(i);
			printf("Path to be followed for value %d is : %s,",i, path);
			MaxHeapNode *n = getNode(root, &path);
			if(n != NULL) printf(" Value : %d\n, ", n->value);	
		}
		printf("\n");
	}
	printf("No. of nodes = %d\n", n);
}

