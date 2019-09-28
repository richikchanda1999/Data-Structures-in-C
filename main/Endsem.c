#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Search.h"

void printTraversals(BTNode *root) {
	int *a = (int *) malloc(countNodes(root) * sizeof(int));
	int pos = 0;
	inOrder(root, &a, &pos);
	int i = 0;
	printf("In-order Traversal : ");
	for(; i < pos ; i++) printf("%d, ", a[i]);
	printf("\n");
	free(a);

	a = (int *) malloc(countNodes(root) * sizeof(int));
	pos = 0;
	preOrder(root, &a, &pos);
	printf("Pre - order Traversal : ");
	for(i = 0 ; i < pos ; i++) printf("%d, ", a[i]);
	printf("\n");
	free(a);

	a = (int *) malloc(countNodes(root) * sizeof(int));
	pos = 0;
	postOrder(root, &a, &pos);
	printf("Post - order Traversal : ");
	for(i = 0; i < pos ; i++) printf("%d, ", a[i]);
	printf("\n");
	free(a);
	
	a = (int *) malloc(countNodes(root) * sizeof(int));
	pos = 0;
	levelOrder(&root, &a, &pos);
	printf("Level - order Traversal : ");
	for(i = 0; i < pos ; i++) printf("%d, ", a[i]);
	printf("\n\n");
	free(a);
}

void *constructMirror(BTNode **root) {
	if(*root == NULL) return;
	BTNode *temp = (*root)->left;
	(*root)->left = (*root)->right;
	(*root)->right = temp;

	constructMirror(&((*root)->left));
	constructMirror(&((*root)->right));
}

int main() {
	BTNode *root = NULL;
	int i, n, *in, *pre;
	printf("Enter no. of nodes in the tree : ");
	scanf("%d", &n);
	in = (int *) malloc(sizeof(int) * n);
	pre = (int *) malloc(sizeof(int) * n);
	printf("Enter Pre-Order Traversal : ");
	for(i = 0 ; i < n ; i++) scanf("%d", pre + i);
	printf("Enter In-Order Traversal : ");
	for(i = 0 ; i < n ; i++) scanf("%d", in + i);
	i = 0;
	constructUsingPre(&root, &in, &pre, 0, n - 1, &i);
	printf("Tree constructed!\n");
	printTraversals(root);
	
	constructMirror(&root);
	printf("Mirror constructed!\n");	
	printTraversals(root);
}
