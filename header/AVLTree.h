#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tree {
	int value;
	struct tree *left;
	struct tree *right;
} AVLNode;

AVLNode *createAVLNode(int);
AVLNode* insert(AVLNode *, int);
AVLNode* getMinimumInAVL(AVLNode**);
AVLNode* getMaximumInAVL(AVLNode**);
AVLNode* deleteAVLNode(AVLNode **, int);
AVLNode* search(AVLNode *, int);
AVLNode *getParent(AVLNode *, AVLNode *);
void inOrder(AVLNode *, int **, int *);
void preOrder(AVLNode *, int **, int *);
void postOrder(AVLNode *, int **, int *);
void levelOrder(AVLNode **, int **, int *);
int height(AVLNode *);
int depth(AVLNode*, AVLNode*);
int successor(AVLNode **, AVLNode **);
int predecessor(AVLNode **, AVLNode **);
int leastCommonAncestor(AVLNode **, AVLNode **, AVLNode **);
int countNodes(AVLNode *);
