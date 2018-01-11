#include <stdio.h>
#include "LinkedListAPI.h"
#include "queueList.h"
#include "patientList.h"
#include "LinkedListAPI.h"


int main(int argc, char * argv[] ) {

	printf("Start of a program.\n");
	
	List * test = initializeList (compare, deleteNodeFromList);
	
	Patient * input = createPatient("testid1", 1, "EV", 10);
	insert(test, input);
	input = createPatient("testid2", 2, "TR", 10);
	insert(test, input);
	input = createPatient("testid3", 3, "UC", 10);
	insert(test, input);
	input = createPatient("testid4", 4, "TC", 10);
	insert(test, input);
	input = createPatient("testid5", 5, "IC", 10);
	insert(test, input);
	
	input = createPatient("testid2", 2, "TR", 10);
	
	pop(test, input);
	
	input = createPatient("testid4", 4, "TC", 10);
	
	pop(test, input);
	
	input = createPatient("testid2", 2, "TR", 10);
	
	pop(test, input);
	
	peek(test);
	
	Node * a = test->head;
	
	while (a!= NULL) {
		printFunction(a->data);
		a = a->next;
	}
	
	
	printf("Succes!\n");
	
	
	
	return 0;
	
}



