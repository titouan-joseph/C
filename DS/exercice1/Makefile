CFLAGS	+= -Wall   -g
LDFLAGS += -Wall

all: main

main.o: main.c
	gcc ${CFLAGS} -c main.c -o main.o

main: main.o
	gcc ${LDFLAGS} main.o -o main

clean:
	-rm -rf *~ *.out  *.o main main.exe

cleanMS:
	del *.o main main.exe