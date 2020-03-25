#include "arbre_type.h"
#include <stdlib.h>
#include <stdio.h>

ARBRE creerArbre(int val, ARBRE filsGauche, ARBRE filsDroit){
	ARBRE a = (ARBRE) malloc(sizeof(NOEUD));
	a->val = val;
	a->filsGauche = filsGauche;
	a->filsDroit = filsDroit;
	return a;
}

void afficheArbre(ARBRE a){
	if(a->filsDroit) afficheArbre(a->filsDroit);
	printf("|");
	printf("%d", a->val);
	printf("|");
	if(a->filsGauche) afficheArbre(a->filsGauche);
}

void afficherArbrePrefixe(ARBRE a, int offset) {
	if (a != NULL) {
		for (int i = 0; i < offset; i++)
			printf("-");
		printf("%d\n", a->val);
		afficherArbrePrefixe(a->filsGauche, offset+2);
		afficherArbrePrefixe(a->filsDroit, offset+2);
	}
}

int hauteurArbre(ARBRE a){
	if (a != NULL) return (1 + max(hauteurArbre(a->filsGauche), hauteurArbre(a->filsDroit)));
	return 0;
}

int max(int a, int b){
	if (a>b) return a;
	return b;
}