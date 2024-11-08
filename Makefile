
CC := gcc
build: main.c symboltable.c token.c token.h symboltable.h
	$(CC) main.c symboltable.c token.c -o test


clean:
	rm -rf test