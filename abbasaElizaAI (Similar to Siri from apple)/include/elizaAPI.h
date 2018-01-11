#ifndef ELIZA_API
#define ELIZA_API

typedef struct dataStorage {
	char keyWord[1000];
	char replyLine[1000];
	double userRating;
	double systemRating;
	double incrementValue;
	int views;
} storeData;

/**
 * prints the data
 * @param  pointer to the data which needs to be printed out
 */
void printFunction (void * data);

/**
 * compares 2 different data of similar type
 * @param  pointer to data A to be compared
 * @param pointer to data B to be compared
 * @return 1 if greater, -1 if less than, 0 if equals
 */
int compare(const void * first, const void * second);

/**
 * creates the pointer to data with given information
 * @param  keyWord of the data
 * @param	reply of the keyWord
 * @param	the priority user provides for the given word
 * @param pointer to data B to be compared
 * @return void pointer to created data
 */
void * createStorage (char * key, char * line, double userRating);


/**
 * deletes variables of a Node
 * @param  pointer to data that needs invidual variables free'd
 */
void deleteAllFunction (void * data);

#endif
