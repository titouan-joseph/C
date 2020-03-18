#include <stdio.h>

#include "../include/pile_type.h"
#include "../include/pile.h"

/************************************************
* \brief     déplace le sommet de pile d'une pile source (*psource) vers une pile destination (*pdest)
* \param psource un pointeur vers la pile source
* \param pdest un pointeur vers la pile destination
* \pre Les deux piles pointées par psource et pdest sont
        des piles de Hanoi valides (chaque élément est plus petit
	que le suivant dans la pile). La pile pointée par psource
	est non-vide. ppile pointe sur une pile valide
* \post Si le sommet de la pile pointée par psource
est de plus petite taille que le sommet de la pile pointée par
pdest les deux piles sont modifiées: le sommet de pile de *psource
est enlevé et rajouté à *pdest, Sinon la fonction affiche une
erreur et  interrompt le programme.
* \result La fonction renvoie 0 si aucune erreur n'est intervenue
**************************************************/
int isValid(PILE pile){
	ELEMPILE* top;
	for(top = pile; top != NULL; top = top->suivant) {
		if(top->elem > top->suivant->elem){
			return(1);
		}
	}
	return(0);
}

int deplacer(PILE* psource, PILE* pdest){

	if(isValid(*psource) && isValid(*pdest) ){
		ELEMPILE* top = *psource;
		if(*pdest == NULL || top->elem < (*pdest)->elem) {
			*psource = top->suivant;
			top->suivant = *pdest;
			*pdest = top;
			return(0);
		}
		else {
			error1("Mouvement invalid");
		}
	}
	else{
		error1("les plies sont invalids");
	}

}

/************************************************
* \brief resoud le problème de Hanoi de taille N de la pile *pdépart vers la pile *parrive en utilisant la pile de passage *ppassage.
* \param pdepart un pointeur vers la pile de départ
* \param parrive un pointeur vers la pile d'arrivée
* \param ppassage un pointeur vers la pile de passage
* \pre Les trois piles pointées par pdepart, ppassage et
        parrive sont des piles de Hanoi valides (chaque élément est plus
	petit que le suivant dans la pile). Les piles pointées par ppassage
	et parrive sont telles qu'elle peuvent empiler les N premiers
	éléments de la pile pointée par pdepart.
* \post  Une tour de Hanoi de taille N a été déplacée de la pile
	pointée par pdepart vers la pile pointée par parrive uniquement en
	utilisant des déplacements valides. Si La tour de départ contient moins
	de N éléments ou si le déplacement est impossible, une erreur
	doit interompre le programme
* \result La fonction renvoie 0 si aucune erreur n'est intervenue
**************************************************/
int hanoi(PILE *depart,PILE *passage, PILE *arrive,int N){
   if(N > 0){
   	hanoi(depart, arrive, passage, N -1);
   	deplacer(depart, arrive);
   	hanoi(passage, depart, arrive, N - 1);

   }
}