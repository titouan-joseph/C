all: produit_scalaire

charPlusInt: charPlusInt.o
	gcc charPlusInt.o -o charPlusInt -Wall

charPlusInt.o: charPlusInt.c
	gcc -c charPlusInt.c -o charPlusInt.o -Wall

myWhile: myWhile.o
	gcc myWhile.o -o myWhile -Wall

myWhile.o: myWhile.c
	gcc -c myWhile.c -o myWhile.o -Wall

produit_scalaire: produit_scalaire.o
	gcc produit_scalaire.o -o produit_scalaire -Wall

produit_scalaire.o: produit_scalaire.c
	gcc -c produit_scalaire.c -o produit_scalaire.o -Wall

cleanMS:
	del -f charPlusInt.exe myWhile.exeproduit_scalaire.exe *.o

cleanUNIX:
	rm -f charPlusInt myWhileproduit_scalaire *.o