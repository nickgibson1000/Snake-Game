CC = gcc
CFLAGS = -Wall -g -pedantic -Werror

all: main

main: main.c
	$(CC) $(CFLAGS) main.c snake.c -lncurses -o snake

clean: 
	rm -f *.o snake
