#include <stdio.h>
#include <stdlib.h>


#include "../include/pile_type.h"

/************************************************
* \brief  affiche l'erreur et quitte le programme
* \param message une chaine de caractère à afficher avant de quitter
**************************************************/
int error1(char* message){
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);
}

/************************************************
* \brief  initialise une pile
**************************************************/
PILE InitPile(){
	return NULL;
}

/************************************************
* \brief     ajoute l'élément elem au sommet de la pile pointée par ppile
* \param ppile un pointeur vers la pile
* \param elem L'élément à rajouter au sommet de pile
* \pre Precondition: pile est une pile valide
* \post Postcondition: La pile pointée par ppile a été modifiée:
          un élément de valeur elem a été rajouté au sommet de pile.
* \result La fonction renvoie la pile modifiée
**************************************************/
PILE Empiler(PILE ppile, int elem){
	ELEMPILE* top = (ELEMPILE*) malloc(sizeof(ELEMPILE));
	top->elem = elem;
	/* Insertion de l'elem au debut de la liste */
	top->suivant = ppile;
	return(top);
}



/************************************************
* \brief    Retire l'element du sommet de la pile pointée par ppile et renvoie
   sa valeur.
* \param ppile un pointeur vers la pile
* \pre Precondition: ppile pointe sur une pile valide
* \post Postcondition: La pile pointée par ppile a été modifiée: son premier
          élément a été supprimé (le deuxième élément est donc devenu
	  le sommet de pile).
* \result Le résultat de la fonction est la
	  valeur de l'élément supprimé si aucune erreur n'est intervenue
* \remark    Si la pile pointé par ppile est vide, la fonction affiche une erreur et interrompt le programme.
**************************************************/
int Depiler(PILE* ppile){
	if(ppile == NULL){
		error1("La pile est vide, impossible de depilier");
	}
	ELEMPILE* top = *ppile;
	int elem = top->elem;
	*ppile = top->suivant;
	free(top);
	return(elem);
}

/************************************************
* \brief affiche une pile d'entier
* \param liste une liste d'entier
**************************************************/
void afficherPile (PILE pile){
	ELEMPILE* top;
	for(top = pile; top != NULL; top = top->suivant) {
		printf("%d ", top->elem);
	}
	printf("\n");
}
