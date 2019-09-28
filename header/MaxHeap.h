#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maxHeap {
	int value;
	struct maxHeap *left;
	struct maxHeap *right;
	struct maxHeap *parent;
} MaxHeapNode;

static int n = 0;

MaxHeapNode *createMaxHeapNode(int);
char *getPath(int);
MaxHeapNode *getNode(MaxHeapNode **, char**);
int insert(MaxHeapNode **, int);
void levelOrder(MaxHeapNode **);
