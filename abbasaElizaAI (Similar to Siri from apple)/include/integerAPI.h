#ifndef INTEGER_API
#define INTEGER_API

typedef struct dataStorage {
	int number;
} storeData;

void printFunction (void * data);

int compare(const void * first, const void * second);

void * createStorage (int Data);

void deleteAllFunction (void * data);

#endif
