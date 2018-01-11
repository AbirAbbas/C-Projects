#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedListAPI.h"
#include "patientList.h"
#include "queueList.h"



int main(int argc, char * argv[] ) {
	
	//Taking file input, if it fails it exits the program!
	if (argv[1] != NULL && fopen(argv[1], "r") != NULL) {
		FILE * inFile = fopen(argv[1], "r");
		char userID[100];
		char userCode[100];
		int userPriority = 0;
		int userInput = 0;
		Patient * input = malloc(sizeof(Patient));
		
		List * hospital = initializeList(compare, deleteNodeFromList);
		
		//Reading and Queing files
		while (!feof(inFile)) {

			fscanf(inFile, "%s %d %s\n", userID, &userPriority, userCode);
			input = createPatient(userID, userPriority, userCode, 0);
			insert(hospital, input);
		}
		
		while (userInput != 3) {
			userInput = 0;
			printf("Menu : \n1. Add a patient.\n2. Simulate current patients.\n3. Exit\n");
			scanf("%d", &userInput);
			if (userInput == 1) {
				printf("Patient ID : \n");
				scanf("%s", userID);
				userPriority = 6;
				while (userPriority <= 0 || userPriority > 5) {
					printf("Priority (Must be 1-5): \n");
					scanf("%d", &userPriority);
				}
				
				printf("Symptom Code (Must be valid else patient will be skipped): \n");
				scanf("%s", userCode);

				input = createPatient(userID, userPriority, userCode, 0);
				insert(hospital, input);
			}
			else if (userInput == 2) {
				simulateFunction(hospital);
			}
			else if (userInput == 3) {
				printf("Good bye!.\n");
			}
		}
		
		deleteList(hospital);
		fclose(inFile);
		
	}
	else {
		printf("Invalid File, Exiting...\n");
	}
	
}



	





