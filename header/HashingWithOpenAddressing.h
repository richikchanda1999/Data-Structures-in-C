#include <stdio.h>
#include <stdlib.h>

int hash(int, int);
int *createHashTable(int);
void printHashTable(int *, int);
void insertLP(int, int, int *); 
void insertQP(int, int, int *);
int doubleHash(int);
void insertDH(int , int , int *);
int calcNullSlots(int *, int);
