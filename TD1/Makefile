all: main

main: main.o hello.o
	gcc main.o hello.o -o main -Wall

hello.o: hello.c includes/hello.h
	gcc -c hello.c -o hello.o -Wall -I includes

main.o: main.c includes/hello.h
	gcc -c main.c -o main.o -Wall -I includes

cleanMS:
	del -f hello *.o

cleanUNIX:
	rm -f hello *.o