CFLAGS	+= -Wall   -g
LDFLAGS += -Wall

all: main

main.o: main.c
	gcc ${CFLAGS} -c main.c -o main.o

tree.o: tree.c tree.c
	gcc ${CFLAGS} -c tree.c -o tree.o

main: main.o tree.o
	gcc ${LDFLAGS} main.o tree.o -o main

clean:
	-rm -rf *~ *.out  *.o main main.exe

cleanMS:
	del *.o main.exe main