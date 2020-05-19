#include<stdlib.h>
#include<stdio.h>

int *creerTabEntier(int N){
    int *tab = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        tab[i] = 0;
    }
    return tab;
}

void afficherTabEntier(int *tab,int N){
    for(int i = 0; i < N; i++){
        printf("| %d ", tab[i]);
    }
    printf("\n");
}

void remplirTabEntier(int *tab,int N){

    int val;

    for(int i = 0; i < N; i++){
        printf("Saisir la %d ieme valuer du tableau \n", i+1);
        scanf("%d", &val);
        tab[i] = val;
    }
}