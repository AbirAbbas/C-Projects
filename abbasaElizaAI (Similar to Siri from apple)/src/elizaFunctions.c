#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinarySearchTreeAPI.h"
#include "elizaAPI.h"


int compare(const void * first, const void * second) {
	char * firstWord = ((storeData*)(first))->keyWord;
	char * secondWord = ((storeData*)(second))->keyWord;
	
	if (strcmp(firstWord,secondWord) > 0) {
		return 1;
	}
	else if (strcmp(firstWord,secondWord) < 0) {
		return -1;
	}
	else if (strcmp(firstWord,secondWord) == 0){
		return 0;
	}
	
	return 0;	
}

void *  createStorage (char * key, char * line, double userRating) {
	storeData * n = malloc(sizeof(storeData));
	strcpy(n->keyWord, key);
	strcpy(n->replyLine, line);
	n->userRating = userRating;
	n->systemRating = userRating;
	n->incrementValue = 0.05;
	n->views = 0;
	
	return n;
}


void printFunction (void * data) {
	printf("<%s>\tRating:<%.2lf>\tSystem:<%.2lf>\tOccurences:<%d>\n", ((storeData*)(data))->keyWord, ((storeData*)(data))->userRating, ((storeData*)(data))->systemRating, ((storeData*)(data))->views);
}

void deleteAllFunction (void * data) {
	strcpy(((storeData*)(data))->keyWord, "");
	strcpy(((storeData*)(data))->replyLine, "");
	((storeData*)(data))->userRating = 0;
	((storeData*)(data))->systemRating = 0;
	((storeData*)(data))->incrementValue = 0;
	((storeData*)(data))->views = 0;
}
