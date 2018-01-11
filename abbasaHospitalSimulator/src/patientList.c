#include <stdio.h>
#include <string.h>
#include "queueList.h"
#include "LinkedListAPI.h"
#include "patientList.h"

Patient * createPatient(char * userID, int userPriority, char * userCode, double exitTime) {
	Patient * c = malloc(sizeof(Patient));
	strcpy((c->userID), userID);
	
	c->userPriority = userPriority;
	
	strcpy((c->userCode), userCode);
		
	c->exitTime = exitTime;
	
	return c;
}

void printFunction(void * data) {
	Patient * c = data;
	
	printf("%s\t%d\t%s\t%.2lf\n", c->userID, c->userPriority,(c->userCode), c->exitTime);
}

void simulateFunction(List * hospital) {
	Node * temp = hospital -> head;
	Patient * output;
	int timer = 1;
	int i = 0;
	
	for (i = 1; i < 6; i ++) {
		temp = hospital -> head;
		while (temp != NULL) {
			output = temp->data;
			if (output->userPriority == i) {
				output->exitTime = timer + returnTime(output->userCode);
				timer = timer + returnTime(output->userCode) + 1;
				//printFunction(temp->data);
			}
			temp = temp -> next;
		}
	}
	
	temp = hospital -> head;
	
	while (temp != NULL) {
		pop(hospital, temp->data);
		temp = temp -> next;
	} 
	
}

int returnTime (char * userCode) {

	if (strcmp(userCode, "CV") == 0) {
		return 5;
	}
	else if (strcmp(userCode, "HN") == 0) {
		return 3;
	}
	else if (strcmp(userCode, "EV") == 0) {
		return 10;
	}
	else if (strcmp(userCode, "GI") == 0) {
		return 2;
	}
	else if (strcmp(userCode, "MH") == 0) {
		return 5;
	}
	else if (strcmp(userCode, "NC") == 0) {
		return 5;
	}
	else if (strcmp(userCode, "EC") == 0) {
		return 1;
	}
	else if (strcmp(userCode, "RC") == 0) {
		return 1;
	}
	else if (strcmp(userCode, "SK") == 0) {
		return 2;
	}
	else if (strcmp(userCode, "SA") == 0) {
		return 7;
	}
	else if (strcmp(userCode, "TR") == 0) {
		return 4;
	}
	else {
		printf("Invalid symptom code detected, program will skip 1 second\n");
		return 0;
	}
}
