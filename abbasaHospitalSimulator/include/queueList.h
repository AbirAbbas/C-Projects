#ifndef _QUEUELIST_H_
#define _QUEUELIST_H_

#include "LinkedListAPI.h"

void insert (List * list, void * toBeAdded);

void pop(List *list, void *toBeRemoved);

void destroy (List * destroy);

void create (char * userID, int userPriority, char * userCode, double exitTime);

void peek (List * list);

int isEmpty(List * list);



#endif
