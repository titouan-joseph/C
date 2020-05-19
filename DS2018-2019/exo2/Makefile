CFLAGS	+= -Wall   -g
LDFLAGS += -Wall

all: main

list.o: liste1.c liste1.h
	gcc ${CFLAGS} -c liste1.c -o list.o

main: list.o
	gcc ${LDFLAGS} list.o -o main

clean:
	-rm -rf *~ *.out  *.o tab

cleanMS:
	del *.o tab