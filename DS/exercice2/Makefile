CFLAGS	+= -Wall   -g
LDFLAGS += -Wall

all: main

main.o: main.c
	gcc ${CFLAGS} -c main.c -o main.o

tab_entier.o: tab_entier.c tab_entier.c
	gcc ${CFLAGS} -c tab_entier.c -o tab_entier.o

main: main.o tab_entier.o
	gcc ${LDFLAGS} main.o tab_entier.o -o main

clean:
	-rm -rf *~ *.out  *.o main main.exe

cleanMS:
	del *.o main.exe main