#ifndef C_LIST_STRUCT_H
#define C_LIST_STRUCT_H

typedef struct cell{
    int val;
    struct cell *suivant;
} CELL;
typedef CELL *LIST;

#endif //C_LIST_STRUCT_H
