CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o stack.o
	$(CC) $(CFLAGS) -o main_program main.o stack.o

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c -o main.o main.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c -o stack.o stack.c

clean:
	rm -f main_program main.o stack.o
