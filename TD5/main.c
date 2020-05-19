#include <stdlib.h>
#include "arbre.h"
#include <stdio.h>

int main() {

	ARBRE a = creerArbre(1, NULL, NULL);
	ARBRE b = creerArbre(3, NULL, NULL);
	ARBRE c = creerArbre(2, a, b);
	ARBRE d = creerArbre(2, NULL, c);

	printf("Affiche\n");
	afficheArbre(c);

	printf("Hauteur \n");
	printf("%d\n", hauteurArbre(NULL));
	printf("%d\n", hauteurArbre(a));
	printf("%d\n", hauteurArbre(d));

    afficherArbrePrefixe(d,3);

	return 0;
}