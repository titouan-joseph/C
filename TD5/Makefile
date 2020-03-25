#CFLAGS = -g -Wall -DDEBUG
#LDLAGS = -g -Wall -DDEBUG
#SOURCE = arbre.c main.c
#OBJECT = $(SOURCE:.c=.o)
#TARGET = $(SOURCE:.c=)
#
#all: $(TARGET)
#
#%: %.o
#	gcc $< -o $@
#
#%.o: %.c
#	gcc -c $< -o $@
#
# $^ signifie toutes les dependances

all: arbre.o main

clean:
	rm -rf *.o main

cleanMS:
	del *.o main.exe

arbre.o: arbre.c arbre.h
	gcc -Wall -c -g $< -o $@

main.o: main.c
	gcc -Wall -c -g $< -o $@

main: main.o arbre.o
	gcc -Wall $^ -o main