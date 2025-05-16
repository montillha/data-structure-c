CC = gcc
CFLAGS = -Wall -Wextra

all: main_program

main_program: main.o fila.o
	$(CC) $(CFLAGS) -o main_program main.o fila.o

main.o: main.c fila.h
	$(CC) $(CFLAGS) -c -o main.o main.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c -o fila.o fila.c

clean:
	rm -f main_program main.o fila.o
