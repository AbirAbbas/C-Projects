#include <stdio.h>
#include "queueList.h"
#include "LinkedListAPI.h"
#include "patientList.h"

void insert(List *list, void *toBeAdded) {
	insertBack(list, toBeAdded);
}

void pop(List *list, void *toBeRemoved) {
	printFunction(toBeRemoved);
	deleteNodeFromList(list, toBeRemoved);
}

void destroy (List * destroy) {
	deleteList(destroy);
}

void create (char * userID, int userPriority, char * userCode, double exitTime) {
	createPatient(userID, userPriority, userCode, exitTime);
}

void peek (List * list) {
	getFromFront(list);
}

int isEmpty(List * list) {
	if (list ==  NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
