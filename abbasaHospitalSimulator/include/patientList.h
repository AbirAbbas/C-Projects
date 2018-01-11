#ifndef _PATIENTLIST_H_
#define _PATIENTLIST_H_

/**carList struct to hold the information
 *@pre NA
 *@param NA
 *@return NA
 **/
typedef struct patientList {
	char userID[100];
	int userPriority;
	char userCode[100];
	double exitTime;
} Patient;


/**Creates the car list
 *@pre NA
 *@param information to put into the list
 *@return pointer to the list
 **/
Patient * createPatient(char * userID, int userPriority, char * userCode, double exitTime);

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

void simulateFunction(List * hospital);

int returnTime (char * userCode);

#endif
