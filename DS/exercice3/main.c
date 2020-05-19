#include <stdlib.h>
#include <stdio.h>

#include"tree.h"

int main(){

    TREE a = newTree(1, NULL, NULL);
    TREE b = newTree(3, NULL, NULL);
    TREE c = newTree(2, a, b);
    TREE d = newTree(2, a, c);

    printf("Affichage\n");
    printf("Arbre avec une feuille\n");
    printf("Arbre a : \n");
    printTree(a);
    printf("\n Arbre b : \n");
    printTree(b);
    printf("\n Arbre avec fils droit et gauche : \n");
    printTree(c);
    printf("\n Arbre avec 5 noeuds : \n");
    printTree(d);

    return 0;
}