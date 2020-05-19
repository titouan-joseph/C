#ifndef C_TYPE_TREE_H
#define C_TYPE_TREE_H

struct model_node
{
    int value;
    struct model_node *left;
    struct model_node *right;
} ;
typedef struct model_node NODE;
typedef NODE *TREE;

#endif //C_TYPE_TREE_H
