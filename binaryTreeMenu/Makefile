CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o binary_tree.o
	$(CC) $(CFLAGS) -o main_program main.o binary_tree.o

main.o: main.c binary_tree.h
	$(CC) $(CFLAGS) -c -o main.o main.c

binary_tree.o: binary_tree.c binary_tree.h
	$(CC) $(CFLAGS) -c -o binary_tree.o binary_tree.c

clean:
	rm -f main_program main.o binary_tree.o
