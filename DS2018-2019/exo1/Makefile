CFLAGS	+= -Wall   -g
LDFLAGS += -Wall

all: tab

tab.o: tableau.c tableau.h
	gcc ${CFLAGS} -c tableau.c -o tab.o

tab: tab.o
	gcc ${LDFLAGS} tab.o -o tab

clean:
	-rm -rf *~ *.out  *.o tab

cleanMS:
	del *.o tab