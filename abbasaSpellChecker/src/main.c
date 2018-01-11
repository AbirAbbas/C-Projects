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
	FILE * dictionary = NULL, * userFile = NULL;
	char fileName[100];
	char userInput[100];
	char addRemove[100];
	char input[100];
	char continueMenu;
	int size = 10;
	char type[100];
	int correct = 0;
	int incorrect = 0;
	
	if (argc > 1) {
		if (fileExist(argv[1]) == 1) {
			strcpy(fileName, argv[1]);
		}
	}
	else {
		strcpy(type, "Dictionary");
		returnName(fileName, type);
	}

	dictionary = fopen(fileName, "rw");
	
	//returnName(fileName);
	//userFile = fopen(fileName, "rw");
	
	//creates hash list of size 10	
	HTable * hashList = createTable(size, hashNode, destroyNodeData, printNodeData);
	readDictionary(hashList, dictionary); //Reads in dictionary file
	fclose(dictionary);
	
	
	while (strcmp("5", userInput) != 0) {
		printf("1) Add a word to Dictionary\n");
		printf("2) Remove a word from Dictionary\n");
		printf("3) Spell Check a file\n");
		printf("4) Show Dictionary Words\n");
		printf("5) Quit\n");
		printf("Please select an option : \n");
		scanf("%s", userInput);
		
		if (strcmp("1", userInput) == 0) {
			printf("Please enter the word you wish to add : \n");
			scanf("%s", addRemove);
			getLower(addRemove);
			if (lookupData(hashList, addRemove) == NULL) {
				addWord(hashList, addRemove, size);
				printf("Word was successfully added!\n");
			}
			else {
				printf("Word already exists!\n");
			}
			
			printf("Press ENTER to continue!\n");
			getchar();
			scanf("%c", &continueMenu);
		}
		else if (strcmp("2", userInput) == 0) {
			printf("Please enter the word you want to remove : \n");
			scanf("%s", addRemove);
			getLower(addRemove);
			
			if (lookupData(hashList, addRemove) != NULL ) {
				removeData(hashList, addRemove);
				printf("Word was successfully removed!\n");
			}
			else {
				printf("Word does not exist already!\n");
			}
			
			printf("Press ENTER to continue!\n");
			getchar();
			scanf("%c", &continueMenu);
		}
		else if (strcmp("3", userInput) == 0) {
			
			strcpy(fileName, "");
			strcpy(type, "Spell checker");
			returnName(fileName, type);
			userFile = fopen(fileName, "rw");
		
			correct = 0;
			incorrect = 0;
			
			printf("\n");
			
			while (!feof(userFile)) {
				strcpy(input, "");
				fgets(input, 100, userFile);
				if (input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
				//fscanf(userFile, "%s", input);
				getLower(input);
				printf("%s\n",input);
				
				if (lookupData(hashList, input) == NULL && strcmp(input, "") != 0) {
					printf("%s was not found in the dictionary.\n", input);
					incorrect++;
				}
				else if (strcmp(input, "") != 0) {
					correct++;
				}
			}

			printf("\n");
			printf("Summary : \n");
			
			printf("Correctly spelt words : %d\n", correct);
			printf("Incorrectly spelt words : %d\n", incorrect);
			printf("Press ENTER to continue!\n");
			getchar();
			scanf("%c", &continueMenu);
			
			fclose(userFile);
		}
		else if (strcmp("4", userInput) == 0) {
			printf("The list contains : \n");
			printList(hashList);
			printf("Press ENTER to continue!\n");
			getchar();
			scanf("%c", &continueMenu);
		}
		else if (strcmp("5", userInput) == 0) {
			printf("Good bye!\n");
		}
		else {
			printf("Invalid input!\n");
		}
		
	}

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


