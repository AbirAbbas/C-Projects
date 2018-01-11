#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTreeAPI.h"
#include "integerAPI.h"

int compare(const void * first, const void * second) {
	if (((storeData*)(first))->number > ((storeData*)(second))->number) {
		return 1;
	}
	else if (((storeData*)(first))->number < ((storeData*)(second))->number) {
		return -1;
	}
	else if (((storeData*)(first))->number == ((storeData*)(second))->number){
		return 0;
	}
	
	return 0;	
}

void *  createStorage (int Data) {
	storeData * n = malloc(sizeof(storeData));
	n -> number = Data;
	
	return n;
}


void printFunction (void * data) {
	printf("%d\n", ((storeData*)(data))->number);
}

void deleteAllFunction (void * data) {
	((storeData*)(data))->number = 0;
}
