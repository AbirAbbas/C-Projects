#include <stdio.h>
#include <string.h>
#include "HashTableAPI.h"
#include <ctype.h>

int fileExist (const char * fileName);

void printList (HTable * hashList);

void returnName (char * fileName, char * type);

void readDictionary (HTable * hashList, FILE * dictionary);

void addWord (HTable * hashList, char * input, int size);

int main(int argc, char ** argv )
{
	int size = 10;
	
	dataFile * storeData = malloc(sizeof(dataFile));
	//creates hash list of size 10	
	HTable * hashList = createTable(size, hashNode, destroyNodeData, printNodeData);
	
	if (hashList == NULL) {
		printf("List was not created successfully\n");
	}
	else {
		printf("List was created successfully\n");
	}
	
	storeData = createFile("Potato");
	insertData(hashList, returnKey("Potato", size), storeData);
	
	if (lookupData(hashList, "Potato") != NULL) {
		printf("Word was added successfully\n");
	}
	else {
		printf("Word was not added successfully\n");
	}
	
	storeData = createFile("");
	insertData(hashList, returnKey("", size), storeData);
	
	if (lookupData(hashList, "") != NULL) {
		printf("Entering nothing was accepted successfully but does not cause errors\n");
	}
	else {
		printf("Entering nothing is not possbile\n");
	}
	
	storeData = createFile("Abir");
	insertData(hashList, returnKey("Abir", size), storeData);
	
	if (lookupData(hashList, "Potato") == NULL) {
		printf("Potato doesn't exist in the list\n");
	}
	else {
		printf("Potato exists in the list\n");
	}
	
	removeData(hashList, "Abir");
	
	if (lookupData(hashList, "Abir") == NULL) {
		printf("Abir was deleted successfully\n");
	}
	else {
		printf("Abir was not deleted successfully\n");
	}
	
	printList(hashList);
	storeData = createFile("Test");
	insertData(hashList,returnKey("Test", size), storeData);
	
	if (lookupData(hashList, "Test") == NULL) {
		printf("Test was added successfully\n");
	}
	else {
		printf("Test was not added!\n");
	}
	
	printList(hashList);
	
	lookupData(hashList, "");
	
	printf("Testing for keys : \n");
	
	printf("Abir : index : %d real key : %d\n", returnKey("Abir", 10), returnRealkey("Abir"));
	printf("Potato : index : %d real key : %d\n", returnKey("Potato", 10), returnRealkey("Potato"));
	printf("(Testing if nothing entered works) Empty String : index : %d real key : %d\n", returnKey("", 10), returnRealkey(""));
	printf("(Testing if numbers work)44 : index : %d real key : %d\n", returnKey("44", 10), returnRealkey("44"));
	
	
		
	return 0;
}

void readDictionary (HTable * hashList, FILE * dictionary) {
	
	char input[100];
	int size = 10;
	dataFile * storeData = malloc(sizeof(dataFile));
	
	while (!feof(dictionary)) {
		fscanf(dictionary, "%s", input);
		getLower(input);
		printf("%s\n", input);
		storeData = createFile(input);
		insertData(hashList, returnKey(input, size), storeData);
	}

}

void addWord (HTable * hashList, char * input, int size) {
	dataFile * storeData = malloc(sizeof(dataFile));
	
	storeData = createFile(input);
	insertData(hashList, returnKey(input, size), storeData);
	
}

void returnName (char * fileName, char * type) {
	
	do {
		printf("Please enter the proper file name for the %s : \n", type);
		scanf("%s", fileName);
		//strcpy(fileName, "test.txt");
	} while (fileExist(fileName) == 0);

}

int fileExist (const char * fileName) {
	FILE * f = NULL;
	if ((f = fopen(fileName, "r"))) {
		fclose(f);
		return 1;
	}
	
	return 0;
}

void printList (HTable * hashList) {
	int i = 0;
	
	dataFile * test = malloc(sizeof(dataFile));
	
	//removeData(hashList, returnRealkey("longing"));
	//removeData(hashList, returnRealkey("different"));
	
	for (i = 0; i < 10; i++) {
		
		Node * temp = hashList->table[i]->next;
		
		if (temp == NULL) {
			test = hashList -> table [i] -> data;
			int test1 = hashList -> table [i] -> key;
			if (strcmp("", test->word) != 0) printf("<%d>:<%d>:<%s>\n",test1, returnRealkey(test->word), test->word);
		}
		else {
			test = hashList -> table [i] -> data;
			int test1 = hashList -> table [i] -> key;
			if (strcmp("", test->word) != 0) printf("<%d>:<%d>:<%s>\n",test1, returnRealkey(test->word), test->word);
			
			Node * temp = hashList->table[i]->next;
			
			while (temp != NULL) {
				test = temp->data;
				if (strcmp("", test->word) != 0) printf("<%d>:<%d>:<%s>\n",test1, returnRealkey(test->word), test->word);
				temp = temp->next;
			}
		}

	}
}


