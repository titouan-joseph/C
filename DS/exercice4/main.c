#include <stdlib.h>
#include <stdio.h>

#include"tree.h"

int main(){

    TREE a = newTree(5, NULL, NULL);
    TREE b = newTree(3, NULL, NULL);
    TREE c = newTree(2, a, b);
    TREE d = newTree(2, a, c);

    printf("-------------------------------\n");

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

    printf("-------------------------------\n");

    printf("Insertion ABR\n");
    printf("Ajout d'une grande valeur \n");
    printTree(insertionABR(c, 10));
    printf("\n Ajout d'une petite valeur \n");
    printTree(insertionABR(c, 1));

    return 0;
}