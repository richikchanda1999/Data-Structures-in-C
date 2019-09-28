#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Queue.h"
#include "AVLTree.h"

AVLNode *createAVLNode(int x) {
	AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));
	newNode->value = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

AVLNode *leftRotate(AVLNode **root) {
	AVLNode *temp = (*root)->right;
	(*root)->right = temp->left;
	temp->left = *root;
	return temp;
}

AVLNode *rightRotate(AVLNode **root) {
	AVLNode *temp = (*root)->left;
	(*root)->left = temp->right;
	temp->right = *root;
	return temp;
}

int getBalanceFactor(AVLNode **n) {
	if(*n == NULL) return 0;
	return (height((*n)->right) - height((*n)->left));
}

AVLNode* insert(AVLNode* root, int x)
{
	if (root == NULL) return createAVLNode(x);
	
	if (x <= root->value)
		root->left = insert(root->left, x);
	else if (x > root->value)
		root->right = insert(root->right, x);

	int b = getBalanceFactor(&root);

	if(b<-1)
	{
		if(x < root->left->value)
			return rightRotate(&root);
		else
		{
			root->left = leftRotate(&(root->left));
			return rightRotate(&root);
		}
	}
	if(b>1)
	{
		if(x > root->right->value)
			return leftRotate(&root);
		else
		{
			root->right = rightRotate(&(root->right));
			return leftRotate(&root);
		}
	}
	return root;
}

AVLNode* getMinimumInAVL(AVLNode** root)
{
	if(*root == NULL) return (*root);

	AVLNode *temp = *root;
	while(temp->left != NULL) temp = temp->left;
	return temp;
}

AVLNode* getMaximumInAVL(AVLNode** root)
{
	if(*root == NULL) return (*root);
	
	AVLNode *temp = *root;
	while(temp->right != NULL) temp = temp->right;
	return temp;
}

AVLNode* deleteAVLNode(AVLNode** root, int x)
{
	//AVLNode *root = *node;
	if (*root == NULL)
		return *root;

	if (x < (*root)->value)
		(*root)->left = deleteAVLNode(&((*root)->left), x);
	else if (x > (*root)->value)
		(*root)->right = deleteAVLNode(&((*root)->right), x);
	else
	{
		if ((*root)->left == NULL) return (*root)->right;
		else if ((*root)->right == NULL) return (*root)->left;
		AVLNode* temp = getMinimumInAVL(&((*root)->right));
		(*root)->value = temp->value;
		(*root)->right = deleteAVLNode(&((*root)->right), temp->value);
	}
	
	int b1 = getBalanceFactor(root);

	if(b1<-1)
	{	
		int b2 = getBalanceFactor(&((*root)->left));
		if(b2<=0)
			return rightRotate(root);
		else
		{
			(*root)->left = leftRotate(&((*root)->left));
			return rightRotate(root);
		}
	}
	if(b1>1)
	{
		int b2 = getBalanceFactor(&((*root)->right));
		if(b2>=0)
			return leftRotate(root);
		else
		{
			(*root)->right = rightRotate(&((*root)->right));
			return leftRotate(root);
		}
	}
	return (*root);
}

AVLNode* search(AVLNode *root, int x) {
	if(root == NULL) return NULL;
	else {
		AVLNode *temp = root;
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

AVLNode *getParent(AVLNode *root, AVLNode *n) {
	if(n == NULL || n->value == root->value) return NULL;
	else {
		AVLNode *parent = root;
		AVLNode *child = (n -> value < parent -> value) ? parent -> left : parent-> right;
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

void inOrder(AVLNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	inOrder(root->left, arr, pos);
	//printf("%d, ", root->value);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	inOrder(root->right, arr, pos);
}

void preOrder(AVLNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
	preOrder(root->left, arr, pos);
	preOrder(root->right, arr, pos);
}

void postOrder(AVLNode *root, int **arr, int *pos) {
	if(root == NULL) return;
	postOrder(root->left, arr, pos);
	postOrder(root->right, arr, pos);
	(*arr)[*pos] = root->value;
	*pos = *pos + 1;
	//printf("%d, ", root->value);
}

void levelOrder(AVLNode **root, int **arr, int *pos) {
	if(*root == NULL) return;
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	enqueue(&q, (*root)->value);
	int p = peekFromQueue(q);
	//printf("%d\n", p);
	while(p != INT_MIN) {
		//printf("Loop entered!\n");
		p = peekFromQueue(q);
		//printf("%d", p);
		int x = dequeue(&q);
		if(x) {
			//printf("%d,", p);
			(*arr)[*pos] = p;
			*pos = *pos + 1;
			AVLNode *n = search(*root, p);
			if(n->left != NULL) enqueue(&q, n->left->value);
			if(n->right != NULL) enqueue(&q, n->right->value);
		} 
	}
	printf("\n");
}

int height(AVLNode *n) {
	if(n == NULL) return 0;
	int a = height(n->left);
	int b = height(n->right);
	return (a > b) ? (1 + a) : (1 + b);
}

int depth(AVLNode *root, AVLNode *n) {
	AVLNode *parent = getParent(root, n);
	if(parent == NULL) return 0;
	return 1 + depth(root, parent);
}

int successor(AVLNode **root, AVLNode **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> right != NULL) {
		AVLNode *temp = (*n)->right;
		while(temp->left != NULL) temp = temp->left;
		return temp->value;
	} else {
		AVLNode *temp = *n;
		while(1) {
			AVLNode *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value > (*n)->value) return parent->value;
			temp = parent;
		}
		//AVLNode *parent = getParent(*root, *n);
		/*if(parent->left->value == (*n)->value) return parent->value;*/
	}
}

int predecessor(AVLNode **root, AVLNode **n) {
	if(*root == NULL) return -1;
	//if(n == root) return -1;
	if((*n) -> left != NULL) {
		AVLNode *temp = (*n)->left;
		while(temp->right != NULL) temp = temp->right;
		return temp->value;
	} else {
		AVLNode *temp = *n;
		while(1) {
			AVLNode *parent = getParent(*root, temp);
			if(parent == NULL) return -1;
			else if(parent->value < (*n)->value) return parent->value;
			temp = parent;
		}
		//if(parent->right->value == (*n)->value) return parent->value;
	}
}

int leastCommonAncestor(AVLNode **root, AVLNode **n1, AVLNode **n2) {
	if(*root == NULL || *n1 == NULL || *n2 == NULL) return -1;
	AVLNode *temp1 = *n1;
	AVLNode *temp2 = *n2;
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

int deleteNode(AVLNode **root, int x) {
	AVLNode *n = search(*root, x);
	if(n == NULL) return -1;
	AVLNode *parent = getParent(*root, n);
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

int countNodes(AVLNode *root) {
	if(root == NULL) return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}
