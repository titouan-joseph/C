#ifndef C_ARBRE_TYPE_H
#define C_ARBRE_TYPE_H

struct model_noeud
{
	int val;
	struct model_noeud *filsGauche ;
	struct model_noeud *filsDroit ;
} ;

typedef struct model_noeud NOEUD;
typedef NOEUD *ARBRE;

#endif //C_ARBRE_TYPE_H