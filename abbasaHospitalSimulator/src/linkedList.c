#include <stdio.h>
#include <string.h>
#include "queueList.h"
#include "LinkedListAPI.h"
#include "patientList.h"


List *initializeList(int (*compareFunction)(const void *first,const void *second), int (*deleteFunction)(List * list, void * toBeDeleted)) {
	
	List * l = malloc(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	l->compare = compareFunction;
	l->deleteF = deleteFunction;
	return l;
}

Node *initializeNode(void *data) {
	
	Node * n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	n->previous = NULL;
	
	return n;
}

void insertFront(List *list, void *toBeAdded) {
	//ADD to head
	if (list->head != NULL && list->tail != NULL) {
		Node * temp = malloc(sizeof(Node));
		temp = initializeNode(toBeAdded);
		list->head->previous = temp;
		temp -> next = list->head;
		temp -> previous = NULL;
		list->head = temp;
		
	}
	else {
		list->head = initializeNode(toBeAdded);
		list->tail = list->head;
	}
	
	
}

void insertBack(List *list, void *toBeAdded) {
	//ADD to tail
	if (list->head != NULL && list->tail != NULL) {
		
		Node * temp = malloc(sizeof(Node));
		temp = initializeNode(toBeAdded);
		list->tail->next = temp;
		temp -> previous = list->tail;
		temp -> next = NULL;
		list->tail = temp;
	}
	else {
		list->head = initializeNode(toBeAdded);
		list->tail = list->head;
	}
	
}

void deleteList(List *list) {
	free(list);
	//Deletes the whole list
}

void insertSorted(List *list, void *toBeAdded) {
	
	Node * temp = list->head;
	
	Node * head = temp;
	
	Node * enterNode = malloc(sizeof(Node));
	
	if (temp == NULL) {
		enterNode = initializeNode(toBeAdded);
		list->head = enterNode;
		list->tail = enterNode;

	}
	else {
	
		while (temp != NULL) {
		
			if (list->compare(toBeAdded, temp->data) == 1) {
			
				if (temp->next != NULL && list->compare(toBeAdded, temp->next->data) == -1) {
					enterNode = initializeNode(toBeAdded);
					enterNode->next = temp->next;
					temp->next->previous = enterNode;
					enterNode->previous = temp;
					temp->next = enterNode;
					list->head = head;
					break;
				}
				else if (temp->next == NULL) {
					insertBack(list, toBeAdded);
					break;
				}
			
			}
			else if (list->compare(toBeAdded, temp->data) == -1) {
				insertFront(list, toBeAdded);
				break;
			}
			else if (list->compare(toBeAdded, temp->data) == 0 && temp->next != NULL && list->compare(toBeAdded, temp->next->data) != 0) {
				enterNode = initializeNode(toBeAdded);	
				enterNode->next = temp->next;
				temp->next->previous = enterNode;
				enterNode->previous = temp;
				temp->next = enterNode;
				list->head = head;
				break;
			}
			else if (list->compare(toBeAdded, temp->data) == 0 && temp->next == NULL) {
				insertBack(list, toBeAdded);
				break;
			}
			temp = temp->next;
		}
	}
}

int deleteNodeFromList(List *list, void *toBeDeleted) {
	
	Node * temp = list->head;
	
	Node * holder;
	
	Patient * data = malloc(sizeof(Patient));
	Patient * deleteData = malloc(sizeof(Patient));
	deleteData = toBeDeleted;
	
	int returnVal = 0;
	
	while (temp != NULL) {
		data = temp->data;
				
		if (strcmp(data->userID, deleteData->userID) == 0 && strcmp(data->userCode, deleteData->userCode) && data->userPriority == deleteData->userPriority) {
			
			holder = temp;
			
			if (temp -> next) {
				temp->next->previous = temp -> previous;
			}
			else {
				list->tail = temp->previous;
				if (list->tail) {
					list->tail->next = NULL;
				}
			}
			if (temp->previous) {
				temp -> previous -> next = temp -> next;
			}
			else {
				list->head = temp -> next;
				if (list->head) list->head->previous = NULL;
			}
			
			holder->next = NULL;
			holder->previous = NULL;
			free(holder);
		}
		temp = temp->next;
	}
	
	return returnVal;
}

void *getFromFront(List *list) {
//points to head
	return list->head;
}

void *getFromBack(List *list) {
//points to tail
	return list->tail;
}

int compare(const void *first,const void *second) {
	
	if (((Patient*)first)->userPriority < ((Patient*)second)->userPriority) return -1;
	
	else if (((Patient*)first)->userPriority > ((Patient*)second)->userPriority) return 1;
		
	else return 0;
	
}
