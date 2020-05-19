#include<stdio.h>
#include<stdlib.h>

#include"list_struct.h"
#include"liste1.h"

void afficherList(LIST liste1){
    CELL *visitor;

    visitor=liste1;
    while(visitor!=0)
    {
        fprintf(stdout,"|%d|",visitor->val);
        visitor=visitor->suivant;
    }
    fprintf(stdout,"|--\n");
}

LIST insertionListeTriee (LIST liste1, int val)
{
    if(liste1 == NULL){
        LIST new = (CELL*) malloc(sizeof(CELL));
        new->suivant = NULL;
        new->val = val;
        return new;
    } else if(liste1->val > val){
        LIST newliste = (CELL*) malloc(sizeof(CELL));
        newliste->val = val;
        newliste->suivant = liste1;
        return newliste;
    } else {
        LIST newliste = insertionListeTriee(liste1->suivant, val);
        liste1->suivant = newliste;
        return liste1;
    }

}

int main(){
    LIST list = NULL;
    list=insertionListeTriee(list,10);
    list=insertionListeTriee(list,-10);
    list=insertionListeTriee(list,11);
    list=insertionListeTriee(list,0);
    list=insertionListeTriee(list,-10);
    list=insertionListeTriee(list,40);
    afficherList(list);

    return 0;
}