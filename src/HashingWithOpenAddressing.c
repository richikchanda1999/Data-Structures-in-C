#include <stdio.h>
#include <stdlib.h>

int hash(int k, int M) {
	return (k % M);
}

int *createHashTable(int M) {
	int i;
	int *ht = (int *) malloc(sizeof(int) * M);

	for(i = 0 ; i < M ; i++) *(ht + i) = -1;
	return ht;
}

void printHashTable(int *hashTable, int N) {
	int i = 0;
	for(; i < N ; i++) {
		if(hashTable[i] != -1) printf("Slot %d : %d\n", i + 1, hashTable[i]);
		else printf("Slot %d : Empty\n", i + 1);
	}
}

void insertLP(int key, int M, int *hashTable) {
	int h = hash(key, M);
	while(hashTable[h] != -1) h = (2 * h) % M;
	hashTable[h] = key;
}

void insertQP(int key, int M, int *hashTable) {
	int h = hash(key, M);
	while(hashTable[h] != -1) h = (h * h) % M;
	hashTable[h] = key;
}

int doubleHash(int k) {
	return (8 - (k % 8));
}

void insertDH(int key, int M, int *hashTable) {
	int h = hash(key, M);
	while(hashTable[h] != -1) {
		h += doubleHash(key);
		h %= M;
	}
	hashTable[h] = key;
}

int calcNullSlots(int *ht, int M) {
	int null = 0, i;
	for(i = 0 ; i < M; i++) if(ht[i] == -1) null++;
	return null;
}
