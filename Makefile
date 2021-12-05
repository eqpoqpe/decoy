CC=gcc
CFLAG=-Wall -g
BIN_FILE=decoy_dome

run:
	$(CC) -o $(BIN_FILE) ./example/demo.c -I ./include
	./$(BIN_FILE)
