#include <stdlib.h>
#include <stdio.h>

#include"type_tree.h"


TREE newTree(int val, TREE left_son, TREE right_son){
    TREE a = (TREE) malloc(sizeof(NODE));
    a->value = val;
    a->left = left_son;
    a->right = right_son;
    return a;
}

//void printTree(TREE tree){
//    if(tree->right) printTree(tree->right);
//    printf("|");
//    printf("%d", tree->value);
//    printf("|");
//    if(tree->left) printTree(tree->left);
//}

void printTreeHauteur(TREE tree, int hauteur){
    if(tree == NULL) return;
    printTreeHauteur(tree->right, hauteur+5);
    printf("\n");
    for(int i = 0; i < hauteur; i++)
        printf(" ");
    printf("%d\n", tree->value);
    printTreeHauteur(tree->left, hauteur+5);
}

void printTree(TREE tree){
    printTreeHauteur(tree, 0);
}
