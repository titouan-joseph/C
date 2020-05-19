#ifndef C_TREE_H
#define C_TREE_H

#include"type_tree.h"

TREE newTree(int value, TREE left_son, TREE right_son);
void printTree(TREE tree);
TREE insertionABR(TREE root,int value);

#endif //C_TREE_H
