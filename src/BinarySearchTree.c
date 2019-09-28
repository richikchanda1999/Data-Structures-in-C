#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Queue.h"
#include "BinarySearchTree.h"

Tree *createBSTNode(int x) {
	Tree *newNode = (Tree *) malloc(sizeof(Tree));
	newNode->value = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insert(Tree **root, int x) {
	Tree *newNode = createBSTNode(x);
	if(*root == NULL) *root = newNode;
	else {
		Tree *temp = *root;
		while(1) {
			if(x <= temp->value) {
				if (temp->left != NULL) 
					temp = temp->left; 
				else { 
					temp->left = newNode; 
					break; 
				}
			} else { 
				if(temp->right != NULL) 
					temp = temp->right; 
				else {
					temp-> right = newNode; 	
					break; 	
				}
			}
		}
	}
}

Tree* search(Tree *root, int x) {
	if(root == NULL) return NULL;
	else {
		Tree *temp = root;
		while(1) {
			if(x < temp->value) {
				if(temp->left == NULL) return NULL;
				temp = temp->left;
			} else if(x > temp->value) {
				if(temp->right == NULL) return NULL;
				temp = temp-> right;
			} else return temp;
		}
	}
}

Tree *getParent(Tree *root, Tree *n) {
	if(n == NULL || n->value == root->value) return NULL;
	else {
		Tree *parent = root;
		Tree *child = (n -> value < parent -> value) ? parent -> left : parent-> right;
		while(1) {
			if(n->value < child->value) {
				if(child == NULL) return NULL;
				parent = child;
				child = child->left;
			} else if(n->value > child->value) {
				if(child == NULL) return NULL;
				parent = child;
				child = child-> right;
			} else return parent;
		}
	}
}

void inOrder(Tree *root, int **arr, int *pos) {
	if(root == NULL) return;
	inOrder(root->left, arr, pos);
	//printf("%d, ", root->value);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	inOrder(root->right, arr, pos);
}

void preOrder(Tree *root, int **arr, int *pos) {
	if(root == NULL) return;
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
	preOrder(root->left, arr, pos);
	preOrder(root->right, arr, pos);
}

void postOrder(Tree *root, int **arr, int *pos) {
	if(root == NULL) return;
	postOrder(root->left, arr, pos);
	postOrder(root->right, arr, pos);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
}

void levelOrder(Tree **root, int **arr, int *pos) {
	if(*root == NULL) return;
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	enqueue(&q, (*root)->value);
	int p = peekFromQueue(q);
	while(p != INT_MIN) {
		p = peekFromQueue(q);
		int x = dequeue(&q);
		if(x) {
			(*arr)[*pos] = p;
			*pos = *pos + 1;
			Tree *n = search(*root, p);
			if(n->left != NULL) enqueue(&q, n->left->value);
			if(n->right != NULL) enqueue(&q, n->right->value);
		} 
	}
	printf("\n");
}

int height(Tree *n) {
	if(n == NULL) return -1;
	int a = 1 + height(n->left);
	int b = 1 + height(n->right);
	return (a > b) ? a : b;
}

int depth(Tree *root, Tree *n) {
	Tree *parent = getParent(root, n);
	if(parent == NULL) return 0;
	return 1 + depth(root, parent);
}

int successor(Tree **root, Tree **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> right != NULL) {
		Tree *temp = (*n)->right;
		while(temp->left != NULL) temp = temp->left;
		return temp->value;
	} else {
		Tree *temp = *n;
		while(1) {
			Tree *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value > (*n)->value) return parent->value;
			temp = parent;
		}
		//Tree *parent = getParent(*root, *n);
		/*if(parent->left->value == (*n)->value) return parent->value;*/
	}
}

int predecessor(Tree **root, Tree **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> left != NULL) {
		Tree *temp = (*n)->left;
		while(temp->right != NULL) temp = temp->right;
		return temp->value;
	} else {
		Tree *temp = *n;
		while(1) {
			Tree *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value < (*n)->value) return parent->value;
			temp = parent;
		}
		//if(parent->right->value == (*n)->value) return parent->value;
	}
}

int leastCommonAncestor(Tree **root, Tree **n1, Tree **n2) {
	if(*root == NULL || *n1 == NULL || *n2 == NULL) return -1;
	Tree *temp1 = *n1;
	Tree *temp2 = *n2;
	int depth1 = depth(*root, *n1);
	int depth2 = depth(*root, *n2);
	if(depth1 > depth2) while(depth1-- > depth2) temp1 = getParent(*root, temp1);
	else if (depth2 > depth1) while(depth2-- > depth1) temp2 = getParent(*root, temp2);
	while(temp1->value != temp2 -> value) {
		temp1 = getParent(*root, temp1);
		temp2 = getParent(*root, temp2);
	}
	return (temp1->value);
}

int deleteNode(Tree **root, int x) {
	Tree *n = search(*root, x);
	if(n == NULL) return -1;
	Tree *parent = getParent(*root, n);
	if(parent == NULL && n-> left == NULL && n->right == NULL) {
		free(*root);
		*root = NULL;
		return 1;
	}
	if(n->right == NULL && parent != NULL) {
		if(n->value < parent->value) parent->left = n->left;
		else parent->right = n->left;
	} else if(n->left == NULL && parent != NULL) {
		if(n->value < parent->value) parent->left = n->right;
		else parent->right = n->right;
	} else {
		int s = successor(root, &n);
		deleteNode(root, s);
		n->value = s;
	}
	return 1;
}

int countNodes(Tree *root) {
	if(root == NULL) return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}

void deleteTree(Tree **root) {
	if(*root != NULL) {
		if(((*root)->left == NULL) && ((*root)->right == NULL)) free(*root);
		else {
			deleteTree(&((*root)->left));
			deleteTree(&((*root)->right));
			free(*root);
		}
	}
}

void constructUsingPre(Tree **root, int **in, int **pre, int low, int high, int *pos) {
	int index = linearSearch(*in, low, high, (*pre)[*pos]);
	if(index != -1) {
		Tree *newNode = createBSTNode((*pre)[*pos]);
		if(*root == NULL) {
			*root = newNode;
			*pos = *pos + 1;
			constructUsingPre(&((*root)->left), in, pre, low, index - 1, pos);
			constructUsingPre(&((*root)->right), in, pre, index + 1, high, pos);
		}
	}
}

void constructUsingPost(Tree **root, int **in, int **post, int low, int high, int *pos) {
	int index = linearSearch(*in, low, high, (*post)[*pos]);
	if(index != -1) {
		Tree *newNode = createBSTNode((*post)[*pos]);
		if(*root == NULL) {
			*root = newNode;
			*pos = *pos - 1;
			constructUsingPost(&((*root)->right), in, post, index + 1, high, pos);
			constructUsingPost(&((*root)->left), in, post, low, index - 1, pos);
		}
	}
}
