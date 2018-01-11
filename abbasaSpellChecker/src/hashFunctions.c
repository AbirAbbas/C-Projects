#include <stdio.h>
#include <string.h>
#include "HashTableAPI.h"
#include <ctype.h>


/**Function to point the hash table to the appropriate functions. Allocates memory to the struct and table based on the size given.
*@return pointer to the hash table
*@param size size of the hash table
*@param hashFunction function pointer to a function to hash the data
*@param destroyData function pointer to a function to delete a single piece of data from the hash table
*@param printNode function pointer to a function that prints out a data element of the table
**/
HTable *createTable(size_t size, int (*hashFunction)(size_t tableSize, int key),void (*destroyData)(void *data),void (*printNode)(void *toBePrinted)) {
	
	HTable * h = malloc(sizeof(HTable)); // initialize HTable list
	h->size = size; // set size
	Node ** hashList = malloc(sizeof(Node) * size); // create array
	h->table = hashList; //insert in Array to the hash table
	
	int i = 0;
	dataFile * temp = createFile("");
	
	//Sets the list with empty values, to avoid seg faults!
	for (i = 0; i < size; i ++) {
		h -> table [i] = createNode(i, temp);
	}
	h->printNode= printNode;
	h->destroyData=destroyData;
	h->hashFunction=hashFunction;
	return h;
}

/**Function for creating a node for the hash table.
*@pre Node must be cast to void pointer before being added.
*@post Node is valid and able to be added to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data is a generic pointer to any data type.
*@return returns a node for the hash table
**/
Node *createNode(int key, void *data) {
	Node * n = malloc(sizeof(Node));
	
	n->key = key;
	n->data = data;
	n->next = NULL;
	
	return n;

}

/** Deletes the entire hash table and frees memory of every element.
*@pre Hash Table must exist.
*@param hashTable pointer to hash table containing elements of data
**/
void destroyTable(HTable *hashTable) {
	//Destroy the entire list
}

/**Inserts a Node in the hash table.
*@pre hashTable type must exist and have data allocated to it
*@param hashTable pointer to the hash table
*@param key integer that represents the data (eg 35->"hello")
*@param data pointer to generic data that is to be inserted into the list
**/
void insertData(HTable *hashTable, int key, void *data) {
	
	dataFile * test = malloc(sizeof(dataFile));
	test = hashTable -> table [key] -> data;
	if (strcmp(test->word, "") == 0) { hashTable -> table [key] = createNode(key, data); }
	
	else {
		
		if (hashTable->table[key]->next == NULL) {
			hashTable->table[key]->next = createNode(key, data);
		}
		else {
			Node * temp = hashTable->table[key]->next;
			while (temp->next != NULL) {
				temp = temp -> next;
			}
			temp->next = createNode(key,data);
		}
		
	}

	
}

/**Function to remove a node from the hash table 
 *@pre Hash table must exist and have memory allocated to it
 *@post Node at key will be removed from the hash table if it exists.
 *@param hashTable pointer to the hash table struct
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 **/
void removeData(HTable *hashTable, char * value) {
	int key = returnRealkey(value);
	Node * temp = hashTable->table[key % 10];
	Node * prev = malloc(sizeof(Node));
	int counter = 0;
	
	
	
	while (temp != NULL) {
		dataFile * checkData = temp->data;
		if (strcmp(checkData->word, value) == 0) {
			
			if (counter >= 1) {

				prev->next = temp->next;
				free(temp->data);
				free(temp);

			}
			else if (counter == 0) {
				Node * delete = hashTable->table[key % 10];
				if (hashTable->table[key % 10]->next != NULL) {
					hashTable->table[key % 10] = hashTable->table[key % 10]->next;
					free(delete->data);
					free(delete);
					printf("Deleted\n");
				}
				else {
				    hashTable->table[key % 10] = createNode(key % 10, createFile(""));
				}
			}
			break;
		}
		prev = temp;
		temp = temp->next;
		counter++;
	}
}

/**Function to return the data from the key given.
 *@pre The hash table exists and has memory allocated to it
 *@param hashTable pointer to the hash table containing data nodes
 *@param key integer that represents a piece of data in the table (eg 35->"hello")
 *@return returns a pointer to the data in the hash table. Returns NULL if no match is found.
 **/
void *lookupData(HTable *hashTable, char * value) {
	
	int key = returnRealkey(value);
	
	Node * temp = hashTable->table[key % 10];

	
	
	while (temp != NULL) {
		dataFile * checkData = temp->data;
		if (strcmp(checkData->word, value) == 0) {
			return temp->data;
		}
		temp = temp->next;
	}
	
	return NULL;
}

int returnKey (char * value, size_t tableSize) {
	int sum = 0;
	int i = 0;
	
	for (i = 0; i < strlen(value); i ++) {
		sum += (int)value[i] * (i + 1);
	}
	
	return sum % tableSize; 
}

int returnRealkey (char * value) {
	int sum = 0;
	int i = 0;
	
	for (i = 0; i < strlen(value); i ++) {
		sum += ((int)value[i] * (i + 1));
	}
	
	return sum;
}

dataFile * createFile(char * value) {
	dataFile * d = malloc(sizeof(dataFile));
	strcpy(d->word, value);
	return d;
}

void getLower(char * string) {
	int i = 0;
	
	for (i = 0; i < strlen(string);i++) {
		string[i] = tolower(string[i]);
	}
	
}

int hashNode(size_t tableSize, int key) {
	return 0;
}

void destroyNodeData(void *data) {
	
}

void printNodeData(void *toBePrinted) {
	
}
