all: EntreeSortie

affichage: affichage.o
	gcc affichage.o -o affichage -Wall

affichage.o: affichage.c
	gcc -c affichage.c -o affichage.o -Wall

scanf: scanf.o
	gcc scanf.o -o scanf -Wall

scanf.o: scanf.c
	gcc -c scanf.c -o scanf.o -Wall

fact: fact.o
	gcc fact.o -o fact -Wall

fact.o: fact.c
	gcc -c fact.c -o fact.o -Wall

portee: portee.o
	gcc portee.o -o portee -Wall

portee.o: portee.c
	gcc -c portee.c -o portee.o -Wall

EntreeSortie: EntreeSortie.o
	gcc EntreeSortie.o -o EntreeSortie -Wall

EntreeSortie.o: EntreeSortie.c
	gcc -c EntreeSortie.c -o EntreeSortie.o -Wall

cleanMS:
	del -f affichage.exe fact.exe scanf.exe portee.exe EntreeSortie.exe *.o

cleanUNIX:
	rm -f affichage fact scanf portee EntreeSortie *.o