CC=gcc
CFLAGS=-Wall -ansi -std=c99 

BIN = ./bin/
SRC = ./src/
INC = ./include/

program :
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)patientList.c $(SRC)linkedList.c $(SRC)priorityQueue.c -Iinclude -o $(BIN)program
	
test :
	$(CC) $(CFLAGS) $(SRC)testMain.c $(SRC)patientList.c $(SRC)linkedList.c $(SRC)priorityQueue.c -Iinclude -o $(BIN)test
	
clean : 
	rm $(BIN)/*
	

