#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tree {
	int value;
	struct tree *left;
	struct tree *right;
} Tree;

Tree *createBSTNode(int);
void insert(Tree **, int);
Tree* search(Tree *, int);
Tree *getParent(Tree *, Tree *);
void inOrder(Tree *, int **, int *);
void preOrder(Tree *, int **, int *);
void postOrder(Tree *, int **, int *);
void levelOrder(Tree **, int **, int *);
int height(Tree *);
int depth(Tree*, Tree*);
int successor(Tree **, Tree **);
int predecessor(Tree **, Tree **);
int leastCommonAncestor(Tree **, Tree **, Tree **);
int deleteNode(Tree **, int);
int countNodes(Tree *);
void deleteTree(Tree **);
void constructUsingPre(Tree **, int **, int **, int, int, int *);
void constructUsingPost(Tree **, int **, int **, int, int, int *);
