#ifndef _CARLIST_H_
#define _CARLIST_H_

/**carList struct to hold the information
 *@pre NA
 *@param NA
 *@return NA
 **/
typedef struct carList {
	char firstDir;
	char secondDir;
	double entryTime;
	double exitTime;
} Cars;


/**Creates the car list
 *@pre NA
 *@param information to put into the list
 *@return pointer to the list
 **/
Cars * createCars(char firstDir, char secondDir, int entryTime, int exitTime);

/**Prints the function
 *@pre Data must be of Car format and valid
 *@param void pointer to the data
 *@return output
 **/
void printFunction(void * data);

/**Simulates the traffic
 *@pre North,East,South,West must exist
 *@param all directional list headers
 *@return output
 **/
void simulateFunction(List * north, List * south, List * east, List * west);


#endif
