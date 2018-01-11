#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedListAPI.h"
#include "carList.h"



int main(int argc, char * argv[] ) {
	
	//Taking file input, if it fails it exits the program!
	if (argv[1] != NULL && fopen(argv[1], "r") != NULL) {
		FILE * inFile = fopen(argv[1], "r");
		char firstDir = 0;
		char secondDir = 0;
		int entryTime = 0;
		Cars * input = malloc(sizeof(Cars));
		
		
		//Declaring the 4 direction lists
		List * north = initializeList(compare, deleteNodeFromList);
		List * south = initializeList(compare, deleteNodeFromList);
		List * east = initializeList(compare, deleteNodeFromList);
		List * west = initializeList(compare, deleteNodeFromList);
		
		//Reading and Sorting the file
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
		
		
		//Now all 4 lists are initialized with their values and is sorted accordingly!		
		
		simulateFunction(north, south, east, west);
		
		//All memory used for the simulation is being freed!
		deleteList(north);
		deleteList(east);
		deleteList(south);
		deleteList(west);
		
	}
	else {
		printf("Invalid File, Exiting...\n");
	}
	
	

	
}

void simulateFunction (List * north, List * south, List * east, List * west) {
	
	double timer = 1;
	
	double max = 0;
	
	double i = 0;
	
	int direction = 0; //North = 0, East = 1, South = 2, West = 3
	
	Node * currentList = malloc(sizeof(Node));
	
	Node * currentNorth = north -> head;
	
	Node * currentSouth = south -> head;
		
	Node * currentEast = east -> head; 
	
	Node * currentWest = west -> head;
	
	Cars * temp = malloc(sizeof(Cars));
	
	printf("Initial Data\t\tArrival\tExit\n");
	
	while (1) {
		
		if (north->tail == NULL && east->tail == NULL && south->tail == NULL && west->tail == NULL) {
			//Exits when all cars are gone!
			free(north);
			free(south);
			free(east);
			free(west);
			break;
		}
		
		if (direction == 0) {
			currentList = currentNorth;
			//printf("North\n");

		}
		else if (direction == 1) {
			currentList = currentEast;
			//printf("East\n");

		}
		else if (direction == 2) {
			currentList = currentSouth;

			//printf("South\n");
		}
		else if (direction == 3) {
			currentList = currentWest;
			//printf("West\n");

		}
		
		max = timer + 13;
		
		for (i = 0; i < 13; i+=0.5, timer+=0.5) {
			
			if (currentList != NULL) {
			
				temp = currentList->data;
			
				//printf("timer : %lf i : %lf\n", timer, i);
			
				if (temp->entryTime <= timer) {
				
					if (temp->secondDir == 'L' && (timer + 2.5) < max ) {
					//Can cross left including on yellows
						temp->exitTime = (timer + 2.5);
						printFunction(temp);
						if (currentList->next!=NULL) currentList = currentList->next;
						else {
							currentList = NULL;
							i = 13;
							timer = max;
							break;
						}
						//increments timer and i by 2.5
						timer+=2.0;
						i+=2.0;
					}
					else if (temp->secondDir == 'R' && (timer + 1.0) < (max - 3)) {
						//Can cross right not on yellows
						temp->exitTime = (timer + 1.0);
						printFunction(temp);
						if (currentList->next!=NULL) currentList = currentList->next;
						else {
							currentList = NULL;
							i = 13;
							timer = max;
							break;
						}
					
					
						//increments timer and i by 1.0
						timer+=0.5;
						i+=0.5;
					}
					else if (temp->secondDir == 'F' && (timer + 2.0) < (max - 3)) {
						//Can go straight not on yellows
						temp->exitTime = (timer + 2.0);
						printFunction(temp);
						if (currentList->next!=NULL) currentList = currentList->next;
						else {
							currentList = NULL;
							i = 13;
							timer = max;
							break;
						}
					//increments timer and i by 2.0
						timer+=1.5;
						i+=1.5;
					}
				}
				
			}
			else {
				if (direction == 0) {
					north->tail = NULL;
				}
					else if (direction == 1) {
					
					east->tail = NULL;
				}
				else if (direction == 2) {
					south->tail = NULL;
				}
				else {
					west->tail = NULL;
				}
			}
			
		}
		timer ++;
		if (direction == 0) {
			currentNorth = currentList;
			direction++;
		}
		else if (direction == 1) {
			currentEast = currentList;
			direction++;
		}
		else if (direction == 2) {
			currentSouth = currentList;
			direction++;
		}
		else {
			currentWest = currentList;
			direction = 0;
		}
		
		
	}
	
	 
	
}




