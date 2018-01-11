#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "BinarySearchTreeAPI.h"


/**************************************
Interface for a Binary Tree ADT

Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
**************************************/


/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data, int height) {
	TreeNode * n = malloc(sizeof(TreeNode));
	n->left = NULL;
	n->right = NULL;
	n->data = data;
	n->height = height;
	
	return n;
}

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del, PrintFunc printFunction) {
	Tree * n = malloc(sizeof(Tree));
	n->compareFunc = compare;
	n->deleteFunc = del;
	n->printFunction = printFunction;
	n->root = NULL;
	
	return n;
}

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy) {
	deleteAll(toDestroy->root, toDestroy->deleteFunc); //deletes individual nodes
	free(toDestroy); //Frees pointer for the tree
	toDestroy = NULL; // makes pointer point to NULL incase memory contains something
}

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data) {
	
	theTree->root = insertSorted(theTree->root, data, theTree->compareFunc, 0);
	
}

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data) {
	theTree->root = deleteFunction(theTree->root, data, theTree->compareFunc);
}


/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ) {
	TreeNode * temp = searchFunction(theTree->root, data, theTree->compareFunc);
	
	if (temp != NULL) return temp->data;
	else return NULL;
}

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree) {
	return theTree->root->data;
}

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData) {
	printAll(0, theTree->root, printData);
}

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData) {
	printAll(2, theTree->root, printData);
}

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData) {
	printAll(1, theTree->root, printData);
}

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTree) {
	if (theTree->root == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode) {
	if (treeNode->left == NULL && treeNode->right == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode) {
	
	if (treeNode->left != NULL && treeNode->right!= NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode ) {
	return treeNode->height;
}


/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */
 
TreeNode * insertSorted (TreeNode * root, TreeDataPtr data, CompareFunc compareData, int height) {
	
	if (root == NULL) {
		root = createTreeNode(data, height);
		return root;
	}
	if (compareData(root->data, data) >= 0) {
		root->left = insertSorted(root->left,data,compareData, height + 1);
	}
	else {
		root->right = insertSorted(root->right,data,compareData, height + 1);
	}
	
	return root;
}

TreeNode * searchFunction (TreeNode * root, TreeDataPtr data, CompareFunc compareData) {
	if (root == NULL) { // returns NULL if root is NULL
		return NULL;
	}
	else if (compareData(root->data, data) == 0) { //Returns root if data matches
		return root;
	}
	else if (compareData(root->data, data) > 0) { //Recurses left if data is less than
		return searchFunction(root->left, data, compareData);
	}
	else { //Recurses right if data is greater than
		return searchFunction(root->right, data, compareData);
	}
}

TreeNode * deleteFunction (TreeNode * root, TreeDataPtr data, CompareFunc compareData) {
	TreeNode * temp = root;
	
	if (root == NULL) {
		return root;
	}
	if (compareData(root->data, data) == 0) {
		if (isLeaf(root) == 1) { //Case 1, if it has no left/right just free it directly
			free(root);
			root = NULL;
		}
		else if (root->left == NULL) { //Case 2, if left is null make right the new parent
			root = root -> right; 
			free(temp);
			temp = NULL;
		}
		else if (root->right == NULL) { //Case 3, if right is null make left new parent
			root = root -> left;
			free(temp);
			temp = NULL;
		}
		else { //Case 4, if both aren't NULL swap with Root and delete the extra copy
			TreeNode * temp = findMin(root->right, compareData);
			root->data = temp->data;
			root->right = deleteFunction(root->right, temp->data, compareData);
		}
		
	}
	else if (compareData(root->data, data) > 0) {
		root->left = deleteFunction(root->left, data, compareData);
	}
	else {
		root->right = deleteFunction(root->right, data, compareData);
	}
	
	return root;
}

TreeNode * findMin (TreeNode * root, CompareFunc compareFunc) {
	TreeNode * temp = root;
	TreeNode * min = temp;
	
	while (temp!=NULL) {
		if (compareFunc(temp->data, min->data) < 0) {
			min = temp;
		}
		
		temp = temp->right;
	}
	return min;
}

void printAll (int Type, TreeNode * root, PrintFunc printFunc) {
	if (root == NULL) {
		return;
	}
	
	if (Type == 0)  { // 0 Denotes Print in Order
		printAll(0, root->left, printFunc);
		printFunc(root->data);
		printAll(0,	root->right, printFunc);
		
	}
	else if (Type == 1)  { // 0 Denotes Print in Order
		printAll(1, root->left, printFunc);
		printAll(1,	root->right, printFunc);
		printFunc(root->data);
		
	}
	else if (Type == 2)  { // 0 Denotes Print in Order
		printFunc(root->data);
		printAll(2, root->left, printFunc);
		printAll(2,	root->right, printFunc);
		
	}
}

void deleteAll (TreeNode * root, DeleteFunc deleteFunction) {
	
	if (root == NULL) {
		return;
	}
	
	deleteAll(root->left, deleteFunction);
	deleteAll(root->right, deleteFunction);
	deleteFunction(root->data);
	root = NULL;
	free(root);
	
}


