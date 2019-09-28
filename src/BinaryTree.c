#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Queue.h"
#include "BinaryTree.h"

BTNode *createBTNode(int x) {
	BTNode *newNode = (BTNode *) malloc(sizeof(BTNode));
	newNode->value = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/*void insert(BTNode **root, int x) {
	BTNode *newNode = createBTNode(x);
	if(*root == NULL) *root = newNode;
	else {
		BTNode *temp = *root;
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
}*/

BTNode* search(BTNode *root, int x) {
	if(root == NULL) return NULL;
	if(root->value == x) return root;
	BTNode *t1 = search(root->left, x);
	BTNode *t2 = search(root->right, x);
	
	if(t1 == NULL && t2 == NULL) return NULL;
	else if(t1 != NULL) return t1;
	else return t2;
}

BTNode *getParent(BTNode *root, BTNode *n) {
	if(root == NULL) return NULL;
	if(root->left == n || root->right == n) return root;
	BTNode *t1 = getParent(root->left, n);
	BTNode *t2 = getParent(root->right, n);
	if(t1 != NULL) return t1;
	if(t2 != NULL) return t2;
}

/*BTNode *getParent(Tree *root, Tree *n) {
	if(n == NULL || n->value == root->value) return NULL;
	else {
		BTNode *parent = root;
		BTNode *child = (n -> value < parent -> value) ? parent -> left : parent-> right;
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
}*/

void inOrder(BTNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	inOrder(root->left, arr, pos);
	//printf("%d, ", root->value);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	inOrder(root->right, arr, pos);
}

void preOrder(BTNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
	preOrder(root->left, arr, pos);
	preOrder(root->right, arr, pos);
}

void postOrder(BTNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	postOrder(root->left, arr, pos);
	postOrder(root->right, arr, pos);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
}

void levelOrder(BTNode **root, int **arr, int *pos) {
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
			BTNode *n = search(*root, p);
			if(n->left != NULL) enqueue(&q, n->left->value);
			if(n->right != NULL) enqueue(&q, n->right->value);
		} 
	}
}

int height(BTNode *n) {
	if(n == NULL) return -1;
	int a = 1 + height(n->left);
	int b = 1 + height(n->right);
	return (a > b) ? a : b;
}

int depth(BTNode *root, BTNode *n) {
	BTNode *parent = getParent(root, n);
	if(parent == NULL) return 0;
	return 1 + depth(root, parent);
}

int successor(BTNode **root, BTNode **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> right != NULL) {
		BTNode *temp = (*n)->right;
		while(temp->left != NULL) temp = temp->left;
		return temp->value;
	} else {
		BTNode *temp = *n;
		while(1) {
			BTNode *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value > (*n)->value) return parent->value;
			temp = parent;
		}
		//BTNode *parent = getParent(*root, *n);
		/*if(parent->left->value == (*n)->value) return parent->value;*/
	}
}

int predecessor(BTNode **root, BTNode **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> left != NULL) {
		BTNode *temp = (*n)->left;
		while(temp->right != NULL) temp = temp->right;
		return temp->value;
	} else {
		BTNode *temp = *n;
		while(1) {
			BTNode *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value < (*n)->value) return parent->value;
			temp = parent;
		}
		//if(parent->right->value == (*n)->value) return parent->value;
	}
}

int leastCommonAncestor(BTNode **root, BTNode **n1, BTNode **n2) {
	if(*root == NULL || *n1 == NULL || *n2 == NULL) return -1;
	BTNode *temp1 = *n1;
	BTNode *temp2 = *n2;
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

int deleteNode(BTNode **root, int x) {
	BTNode *n = search(*root, x);
	if(n == NULL) return -1;
	BTNode *parent = getParent(*root, n);
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

int countNodes(BTNode *root) {
	if(root == NULL) return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}

void deleteBTNode(BTNode **root) {
	if(*root != NULL) {
		if(((*root)->left == NULL) && ((*root)->right == NULL)) free(*root);
		else {
			deleteBTNode(&((*root)->left));
			deleteBTNode(&((*root)->right));
			free(*root);
		}
	}
}

void deleteTree(BTNode **root) {
	if(*root == NULL) return;
	if((*root)->left == NULL && (*root)->right == NULL) free(*root);
	deleteTree(&((*root)->left));
	deleteTree(&((*root)->right));
	if(*root != NULL) free(*root);
	*root = NULL;
}

BTNode *getSibling(BTNode *root, int x) {
	BTNode *node = search(root, x);
	if(node != NULL) {
		BTNode *parent = getParent(root, node);
		if(parent != NULL) {
			printf("Parent is : %d\n", parent->value);
			BTNode *left = parent->left;
			BTNode *right = parent->right;
			if(left != NULL) if(left->value == x) return right;
			if(right != NULL) if(right->value == x) return left;
		}
		return NULL;
	}
	return NULL;
}

int getSum(BTNode *root) {
	if(root == NULL) return 0;
	return (root->value + getSum(root->left) + getSum(root->right));
}

void maxSumPath(BTNode *root, int *sum) {
	if(root == NULL) return;
	int sum1 = getSum(root->left);
	int sum2 = getSum(root->right);
	*sum = *sum + root->value;
	printf("%d, ", root->value);
	if(sum1 > sum2) maxSumPath(root->left, sum);
	else maxSumPath(root->right, sum);
}

void constructUsingPre(BTNode **root, int **in, int **pre, int low, int high, int *pos) {
	int index = linearSearch(*in, low, high, (*pre)[*pos]);
	if(index != -1) {
		BTNode *newNode = createBTNode((*pre)[*pos]);
		if(*root == NULL) {
			*root = newNode;
			*pos = *pos + 1;
			constructUsingPre(&((*root)->left), in, pre, low, index - 1, pos);
			constructUsingPre(&((*root)->right), in, pre, index + 1, high, pos);
		}
	}
}

void constructUsingPost(BTNode **root, int **in, int **post, int low, int high, int *pos) {
	int index = linearSearch(*in, low, high, (*post)[*pos]);
	if(index != -1) {
		BTNode *newNode = createBTNode((*post)[*pos]);
		if(*root == NULL) {
			*root = newNode;
			*pos = *pos - 1;
			constructUsingPost(&((*root)->right), in, post, index + 1, high, pos);
			constructUsingPost(&((*root)->left), in, post, low, index - 1, pos);
		}
	}
}
