all: main

main: main.o
	gcc -Wall -L ../libhello main.o -o main -lhello

main.o: main.c
	gcc -Wall main.c -c -o main.o

cleanMS:
	del -f *.o

cleanUNIX:
	rm -f *.o