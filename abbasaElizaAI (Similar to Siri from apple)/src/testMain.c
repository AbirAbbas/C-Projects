#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "BinarySearchTreeAPI.h"
#include "integerAPI.h"


int main(int argc, char ** argv )
{

	Tree * treeContainer = createBinTree(compare, deleteAllFunction, printFunction);
	
	addToTree(treeContainer, createStorage(5));
	addToTree(treeContainer, createStorage(2));
	addToTree(treeContainer, createStorage(3));
	addToTree(treeContainer, createStorage(1));
	addToTree(treeContainer, createStorage(7));
	
	printf("Printed in Order : \n");
	printInOrder(treeContainer, printFunction);
	printf("Printed in Post Order : \n");
	printPostOrder(treeContainer, printFunction);
	printf("Printed in Pre Order : \n");
	printPreOrder(treeContainer, printFunction);
	
	removeFromTree(treeContainer, createStorage(7));
	removeFromTree(treeContainer, createStorage(7));
	removeFromTree(treeContainer, createStorage(7));
	
	printf("\n");
	
	if (findInTree(treeContainer, createStorage(1)) == NULL) {
		printf("1 was not found \n");
	}
	else {
		printf("1 was found \n");
	}
	
	if (findInTree(treeContainer, createStorage(7)) == NULL) {
		printf("7 was not found \n");
	}
	else {
		printf("7 was found \n");
	}
	
	if (findInTree(treeContainer, createStorage(3)) == NULL) {
		printf("3 was not found \n");
	}
	else {
		printf("3 was found \n");
	}
	
	if (findInTree(treeContainer, createStorage(8)) == NULL) {
		printf("8 was not found \n");
	}
	else {
		printf("8 was found \n");
	}
	
	printf("\n");
	
	printf("Printed in Order : \n");
	printInOrder(treeContainer, printFunction);
	printf("Printed in Post Order : \n");
	printPostOrder(treeContainer, printFunction);
	printf("Printed in Pre Order : \n");
	printPreOrder(treeContainer, printFunction);
	
	destroyBinTree(treeContainer);
	printf("Binary tree was deleted\n");

	return 0;
}

