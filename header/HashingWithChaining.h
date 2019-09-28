#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

int hash(int, int);

Node **createHashTable(int);

void insert(int, int, Node **);
int search(int, int, Node **);
