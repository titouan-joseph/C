#include <stdlib.h>
#include <stdio.h>

#include"tree.h"

int main(){

    TREE a = newTree(3, NULL, NULL);
    TREE b = newTree(5, NULL, NULL);
    TREE c = newTree(2, a, b);
    TREE d = newTree(2, a, c);
    TREE abr = newTree(10, newTree(8, newTree(5,NULL,NULL), newTree(9,NULL,NULL)), newTree(20, newTree(15,NULL,NULL), newTree(21,NULL,NULL)));

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

    printf("-------------------------------\n");
    printf("Test ABR\n");
    printTree(abr);
    (isABRQ(a) == 1) ? printf("A est un ABR \n") : printf("A n'est pas un ABR \n");
    (isABRQ(c) ==1) ? printf("C est un ABR \n") : printf("C n'est pas un ABR\n");
    (isABRQ(abr) ==1) ? printf("abr est un ABR \n") : printf("abr n'est pas un ABR\n");

    return 0;
}