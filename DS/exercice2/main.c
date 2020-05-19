#include"tab_entier.h"

int main(){
    int *tab = creerTabEntier(5);
    afficherTabEntier(tab, 5);
    remplirTabEntier(tab, 5);
    afficherTabEntier(tab, 5);

    return 0;
}