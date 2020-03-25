#ifndef C_ARBRE_H
#define C_ARBRE_H

#include "arbre_type.h"

ARBRE creerArbre(int val, ARBRE filsGauche, ARBRE filsDroit);
void afficheArbre(ARBRE a);
void afficherArbrePrefixe(ARBRE a, int offset);
int hauteurArbre(ARBRE a);

#endif //C_ARBRE_H
