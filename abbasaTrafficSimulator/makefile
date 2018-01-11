CC=gcc
CFLAGS=-Wall -ansi -std=c99 

BIN = ./bin/
SRC = ./src/
INC = ./include/

program :
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)carList.c -Iinclude -o $(BIN)program
	
test :
	$(CC) $(CFLAGS) $(SRC)testMain.c $(SRC)carList.c -Iinclude -o $(BIN)test
	
clean : 
	rm $(BIN)/*
	

