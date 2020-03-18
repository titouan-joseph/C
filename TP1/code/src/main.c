#include <stdio.h>

#include "../include/pile.h"
#include "../include/hanoi.h"

#define N 9
 
/*!***********************************************
* \brief  Programme de test des fonction du module pile.c
**************************************************/    

//int main(int argc,char **argv)
//{
////	error1("Test Error");
//  PILE pile1;
//  int val,i;
//
//  fprintf(stdout,"/********** test de pile d'entier *************\n");
//
//  pile1=InitPile();
//  for (i=N;i>0;i--)
//    {
//      val=i;
//      pile1=Empiler(pile1,val);
//    }
//  fprintf(stdout,"après mise en place d'une pile de taille %d\n",N);
//  afficherPile(pile1);
//  fprintf(stdout,"/**** fin du programme de test de pile d'entier **\n");
//
//  return 0;
//
//}

//int main(int argc, char** argv){
//	PILE pile = InitPile();
//	for(int inc = 0; inc < 10; inc++){
//		pile = Empiler(pile, inc);
//		afficherPile(pile);
//	}
//	int haut =Depiler(&pile);
//	afficherPile(pile);
//}

//int main(int argc,char **argv){
//	PILE pile1 = InitPile();
//	pile1 = Empiler(pile1, 1);
//	pile1 = Empiler(pile1, 5);
//	pile1 = Empiler(pile1, 3);
//
//	PILE pile2 = InitPile();
//	pile2 = Empiler(pile2, 2);
//	pile2 = Empiler(pile2, 1);
//
//	printf("-----------------------\n\n");
//	if (isValid(pile1)) {printf("pile1 : OK \n");}	else {printf("pile1 : NOK \n");}
//	if (isValid(pile2)) {printf("pile2 : OK \n");}	else {printf("pile2 : NOK \n");}
//	printf("-----------------------\n\n");
//
//
//
//}

int main(int argc, char** argv) {
	PILE depart = InitPile();
	PILE passage = InitPile();
	PILE arrive = InitPile();

	for(int i = N; i >= 1; i--) {
		depart = Empiler(depart, i);
	}

	printf("-------- AVANT --------\n");
	printf("Pile de depart : \n");
	afficherPile(depart);
	printf("Pile de passage : \n");
	afficherPile(passage);
	printf("Pile de arrive : \n");
	afficherPile(arrive);
	printf("-------- APRES --------\n");

	hanoi(&depart, &passage, &arrive, N);

	printf("Pile de depart : \n");
	afficherPile(depart);
	printf("Pile de passage : \n");
	afficherPile(passage);
	printf("Pile de arrive : \n");
	afficherPile(arrive);
	printf("-----------------------\n\n");

}



