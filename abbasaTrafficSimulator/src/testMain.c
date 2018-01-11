#include <stdio.h>
#include "LinkedListAPI.h"
#include "carList.h"


int main(int argc, char * argv[] ) {

	printf("Start of a program.\n");
	
	List * test = initializeList (compare, deleteNodeFromList);
	
	Cars * input = createCars('N', 'L', 10, 10);
	insertFront(test, input);
	input = createCars('E', 'L', 10, 10);
	insertFront(test, input);
	input = createCars('E', 'L', 10, 10);
	insertFront(test, input);
	input = createCars('L', 'L', 10, 10);
	insertFront(test, input);
	input = createCars('D', 'L', 10, 10);
	insertFront(test, input);
	
	input = createCars('D', 'L', 10, 10);
	
	deleteNodeFromList(test, input);
	
	input = createCars('N', 'L', 10, 10);
	
	deleteNodeFromList(test, input);
	
	input = createCars('E', 'L', 10, 10);
	
	deleteNodeFromList(test, input);
	
	input = createCars('E', 'L', 10, 10);
	
	deleteNodeFromList(test, input);
	
	input = createCars('L', 'L', 10, 10);
	
	deleteNodeFromList(test, input);
	
	
	
	
	Node * a = test->head;
	
	while (a!= NULL) {
		printFunction(a->data);
		a = a->next;
		
	}
	
	if (argv[1] != NULL && fopen(argv[1], "r") != NULL) {
		FILE * inFile = fopen(argv[1], "r");
		char firstDir = 0;
		char secondDir = 0;
		int entryTime = 0;
		Cars * input = malloc(sizeof(Cars));
		
		List * north = initializeList(compare, deleteNodeFromList);
		List * south = initializeList(compare, deleteNodeFromList);
		List * east = initializeList(compare, deleteNodeFromList);
		List * west = initializeList(compare, deleteNodeFromList);
		
		
		while (!feof(inFile)) {
			fscanf(inFile, "%c %c %d\n", &firstDir, &secondDir, &entryTime);
			
			if (firstDir == 'N') {
				input = createCars(firstDir, secondDir, entryTime, 0);
				insertSorted(north, input);
			}
			else if (firstDir == 'E') {
				input = createCars(firstDir, secondDir, entryTime, 0);
				insertSorted(east, input);
			}
			else if (firstDir == 'S') {
				input = createCars(firstDir, secondDir, entryTime, 0);
				insertSorted(south, input);
			}
			else if (firstDir == 'W') {
				input = createCars(firstDir, secondDir, entryTime, 0);
				insertSorted(west, input);
			}
			
		}
		
	Node * n = north->head;
	
	while (n!= NULL) {
		printFunction(n->data);
		n = n->next;
	}
	
	Node * s = south->head;
	
	while (s!= NULL) {
		printFunction(s->data);
		s = s->next;
	}
	
	Node * e = east->head;
	
	while (e!= NULL) {
		printFunction(e->data);
		e = e->next;
	}
	
	Node * w = west->head;
	
	while (w!= NULL) {
		printFunction(w->data);
		w = w->next;
	}
		
		
		
	}
	else {
		printf("Invalid File, Exiting...\n");
	}
	
	
	List * x = initializeList(compare, deleteNodeFromList);
	input = createCars('E', 'L', 10, 10);
	insertFront(x, input);
	
	deleteNodeFromList(x, input);
	
	if (x->head->next == NULL) {
		printf("Success\n");
	}
	
	
	return 0;
	
}



