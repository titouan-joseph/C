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

TREE insertionABR(TREE root,int value){

    TREE new;

    if (root==NULL)
    {
        new=newTree(value, NULL,NULL);
        return(new);
    }
    else
    {
        if (root->value > value)
        {
            root->left=insertionABR(root->left,value);
            return root;
        }
        else
        {
            root->right=insertionABR(root->right,value);
            return root;
        }
    }
}