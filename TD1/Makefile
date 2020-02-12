all: main

main: main.o hello.o
	gcc main.o hello.o -o main -Wall

hello.o: hello.c hello.h
	gcc -c hello.c -o hello.o -Wall

main.o: main.c hello.h
	gcc -c main.c -o main.o -Wall

cleanMS:
	del -f hello *.o

cleanUNIX:
	rm -f hello *.o