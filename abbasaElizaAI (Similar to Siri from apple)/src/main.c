#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "elizaAPI.h"
#include "BinarySearchTreeAPI.h"

int fileExist (const char * fileName);

void returnName (char * fileName);

void readFile (Tree * treeContainer, FILE * inFile);

void getLower(char * string);

int main (int argc, char ** argv) {
	
	char fileName[100];
	FILE * inFile = NULL;
	char userInput[100];
	
	if (argc > 1) {
		if (fileExist(argv[1]) == 1) {
			strcpy(fileName, argv[1]);
		}
		else {
			returnName(fileName);
		}
	}
	else {
		returnName(fileName);
	}
	
	
	
	inFile = fopen(fileName, "rw");
	
	Tree * treeContainer = createBinTree(compare, deleteAllFunction, printFunction);
	
	readFile(treeContainer, inFile);
	
	fclose(inFile);
	
	
	while (strcmp("9", userInput) != 0) {
		printf("1) Add a new rule\n");
		printf("2) Remove a rule\n");
		printf("3) Display rules\n");
		printf("4) Modify rule ratings\n");
		printf("5) Discuss\n");
		printf("9) Quit\n");
		printf("Please select an option : \n");
		fgets(userInput, 1000, stdin);
		userInput[strlen(userInput) - 1] = '\0';
		
		if (strcmp("1", userInput) == 0) {
			char keyWord[1000] = "";
			char replyLine[1000] = "";
			double userRating = -1;
			while (strcmp(keyWord, "") == 0) {
				printf("Please enter a proper key word\n");
				fgets(keyWord, 1000, stdin);
				keyWord[strlen(keyWord) - 1] = '\0';
			}
			while (strcmp(replyLine, "") == 0) {
				printf("Please enter a proper conversation text reponse\n");
				fgets(replyLine, 1000, stdin);
				replyLine[strlen(replyLine) - 1] = '\0';
			}
			while (userRating < 0 || userRating >1) {
				printf("Please enter a proper user rating\n");
				scanf("%lf", &userRating);
			}
			
			getLower(keyWord);
			
			addToTree(treeContainer, createStorage(keyWord, replyLine, userRating));
			printf("Data was added!\n");
			printf("Press enter to continue\n");
			getchar();
		}
		else if (strcmp("2", userInput) == 0) {
			char keyWord[1000] = "";
			storeData * temp = NULL;
			while (strcmp(keyWord, "") == 0) {
				printf("Please enter a proper key word to remove\n");
				fgets(keyWord, 1000, stdin);
				keyWord[strlen(keyWord) - 1] = '\0';
			}
			
			getLower(keyWord);
			
			temp = createStorage(keyWord, "empty", 5);
			
			if (findInTree(treeContainer, temp) == NULL) {
				printf("%s was not found in the tree!\n", keyWord);
			}
			else {
				removeFromTree(treeContainer, temp);
				printf("%s has been deleted\n", keyWord);
			}
			
			printf("Press Enter to continue\n");
			getchar();
		}
		else if (strcmp("3", userInput) == 0) {
			printInOrder(treeContainer, printFunction);
			printf("Press Enter to continue\n");
			getchar();
		}
		else if (strcmp("4", userInput) == 0) {
			char keyWord[100] = "";
			double userRating = -1;
			while (strcmp(keyWord, "") == 0) {
				printf("Please enter a proper key word to Edit\n");
				fgets(keyWord, 1000, stdin);
				keyWord[strlen(keyWord) - 1] = '\0';
			}
			
			getLower(keyWord);
			
			storeData * temp = findInTree(treeContainer, createStorage(keyWord, "empty", 5));
			
			if (temp == NULL) {
				printf("%s was not found in the tree!\n", keyWord);
			}
			else {
				printf("%s has been found\n", keyWord);
				
				while (userRating < 0 || userRating >1) {
					printf("Please enter a new proper user rating\n");
					scanf("%lf", &userRating);
				}
				
				temp -> userRating = userRating;
	
			}
			printf("Press enter to continue...\n");
			getchar();
			
		}
		else if (strcmp("5", userInput) == 0) {
			char keyWord[1000];
			char * output;
			char delimeter[] = " ,.-?!";
			double max = 0;
			double sum = 0;
			storeData * maxNode = NULL;
			
			printf("Personal Assistant : Hi! i'm Eliza, ask me anything! : \n");
			fgets(keyWord, 1000, stdin);
			keyWord[strlen(keyWord)-1] = '\0';
			getLower(keyWord);
			if (strcmp(keyWord, "") == 0) {
					printf("Personal Assistant : Seems like you don't want to talk!\n");
					break;
			}
			else {
				output = strtok(keyWord, delimeter);
				
				while (output != NULL) {
					sum = 0;
					storeData * temp = findInTree(treeContainer, createStorage(output, "empty", 0));
					
					if (temp != NULL) {
						sum = temp->userRating + temp->systemRating;
						if (max < sum) {
							max = sum;
							maxNode = temp;
						}
					}
					
					output = strtok(NULL, delimeter);
				}
				
				if (maxNode == NULL) {
					printf("Personal Assistant : Sorry i'm not sure what you meant by that!\n");
				}
				else {
					maxNode->views++;
					printf("Personal Assistant : %s\n", maxNode->replyLine);
					
					char userFeedback[100] = "";
					
					while (strcmp(userFeedback, "y") != 0 && strcmp(userFeedback, "n") != 0) {
						printf("Personal Assistant : was this feedback helpful? 'y' or 'n'\n");
						fgets(userFeedback, 1000, stdin);
						userFeedback[strlen(userFeedback) - 1] = '\0';
						
						if (strcmp(userFeedback, "y") == 0) {
							printf("Thank you for your feedback!\n");
							if (maxNode->systemRating < 1) maxNode->systemRating = maxNode->systemRating + (maxNode->systemRating * maxNode->incrementValue);
						}
						else {
							printf("Thank you for your feedback!\n");
							if (maxNode->systemRating > 0) maxNode->systemRating = maxNode->systemRating - (maxNode->systemRating * maxNode->incrementValue);
						}
					}
					
				}
			}
			
			printf("Press any key to continue...\n");
			getchar();	
		}
		else if (strcmp("9", userInput) == 0) {
			printf("Good bye!\n");
		}
		else {
					
		}
		
	}
	
	
	return 0;
}

int fileExist (const char * fileName) {
	FILE * f = NULL;
	if ((f = fopen(fileName, "r"))) {
		fclose(f);
		return 1;
	}
	
	return 0;
}

void returnName (char * fileName) {
	do {
		printf("Please enter the proper file name\n");
		fgets(fileName, 1000, stdin);
		fileName[strlen(fileName) - 1] = '\0';
	} while (fileExist(fileName) == 0);
}

void readFile (Tree * treeContainer, FILE * inFile) {
	int alternate = 0;
	char input[1000] = "";
	char keyWord[1000] = "";
	char replyLine[1000] = "";
	
	while (!feof(inFile)) {
		fgets(input, 1000, inFile);
		input[strlen(input)-1] = '\0';
				
		if (alternate == 0) {
			getLower(input);
			strcpy(keyWord, input);
			alternate = 1;
		}
		else {
			strcpy(replyLine, input);
			addToTree(treeContainer, createStorage(keyWord, replyLine, 0.5));
			alternate = 0;
		}
	}
}

void getLower(char * string) {
	int i = 0;
	
	for (i = 0; i < strlen(string);i++) {
		if (isalpha(string[i])){
			string[i] = tolower(string[i]);
		}
	}
	
}
