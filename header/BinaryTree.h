#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tree {
	int value;
	struct tree *left;
	struct tree *right;
} BTNode;

BTNode *createBSTNode(int);
void insert(BTNode **, int);
BTNode* search(BTNode *, int);
BTNode *getParent(BTNode *, BTNode *);
void inOrder(BTNode *, int **, int *);
void preOrder(BTNode *, int **, int *);
void postOrder(BTNode *, int **, int *);
void levelOrder(BTNode **, int **, int *);
int height(BTNode *);
int depth(BTNode*, BTNode*);
int successor(BTNode **, BTNode **);
int predecessor(BTNode **, BTNode **);
int leastCommonAncestor(BTNode **, BTNode **, BTNode **);
int deleteNode(BTNode **, int);
int countNodes(BTNode *);
void deleteBTNode(BTNode **);
void deleteTree(BTNode **);
BTNode *getSibling(BTNode *root, int);
void constructUsingPre(BTNode **, int **, int **, int, int, int *);
void constructUsingPost(BTNode **, int **, int **, int, int, int *);
