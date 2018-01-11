CC=gcc
CFLAGS=-Wall -ansi -std=c99 

BIN = ./bin/
SRC = ./src/
INC = ./include/

program :
	$(CC) $(CFLAGS) $(SRC)main.c $(SRC)binaryTreeFunctions.c $(SRC)elizaFunctions.c -Iinclude -o $(BIN)program

test :
	$(CC) $(CFLAGS) $(SRC)testMain.c $(SRC)binaryTreeFunctions.c $(SRC)integerFunctions.c -Iinclude -o $(BIN)testProgram
		
clean : 
	rm $(BIN)/*
	

