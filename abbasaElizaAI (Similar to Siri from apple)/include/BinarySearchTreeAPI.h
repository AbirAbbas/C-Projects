#ifndef BST_GUARD
#define BST_GUARD

/**************************************
Interface for a Binary Tree ADT

Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
**************************************/

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
typedef struct binTreeNode TreeNode;

struct binTreeNode{
	TreeDataPtr data;
	int height;
	TreeNode * left;
	TreeNode * right;
	//TreeNode * parent; Optional but useful
    //Tree* parentTree;  Optional but gets you access to function pointers.
};

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;
	PrintFunc printFunction;
	
	// Additions must work with abstract data types.
	// Additional function pointers to generalize tree.
	// Additional properties can be added such as count.
} Tree;

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data, int height);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del, PrintFunc printFunction);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);


/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data );

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree);

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTee);


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode );

/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */

void printAll (int Type, TreeNode * root, PrintFunc printFunc);

/**
 * recursive insertSorted function 
 * @param  treeNode root of the tree
 * @param	TreeDataPtr data containing data to be inserted
 * @param	CompareFunc compare function required to perform sorted inserts
 * @return    Inserted List
 */
TreeNode * insertSorted (TreeNode * root, TreeDataPtr data, CompareFunc compareData, int height);

/**
 * recursive search function 
 * @param  treeNode root of the tree
 * @param	TreeDataPtr data containing data to be searched for
 * @param	CompareFunc compare function required iterated through sorted list
 * @return  Data at the specific Node, NULL if doesn't exist
 */
TreeNode * searchFunction (TreeNode * root, TreeDataPtr data, CompareFunc compareData);

/**
 * recursive deleteFunction 
 * @param  treeNode root of the tree
 * @param	TreeDataPtr data containing data to be deleted
 * @param	CompareFunc compare function required iterated through sorted list
 * @return  root with deleted Node
 */
TreeNode * deleteFunction (TreeNode * root, TreeDataPtr data, CompareFunc compareData);

/**
 * recursive helper to find the minimum node to swap with root for delete function
 * @param  treeNode root of the tree
 * @param	CompareFunc compare function required iterated through sorted list
 * @return    Minimum Node
 */

TreeNode * findMin (TreeNode * root, CompareFunc compareFunc);

/**
 * recursive delete function to delete everything
 * @param  treeNode root of the tree
 * @param	DeleteFunc function that free's invidiual Nodes to avoid memmory leaks
 */
void deleteAll (TreeNode * root, DeleteFunc deleteFunction);

#endif
