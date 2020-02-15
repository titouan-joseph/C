all: main

main: hello.o
	ar -crs libhello.a hello.o

hello.o: hello.c
	gcc -Wall hello.c -c -o hello.o

cleanMS:
	del -f hello *.o *.a

cleanUNIX:
	rm -f hello *.o *.a