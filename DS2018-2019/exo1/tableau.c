#include <stdio.h>
#include <stdlib.h>

#include"tableau.h"

int * CreerTabEntier(int N){
    int *tab;

    tab = (int *)malloc(N*sizeof(int));
    if(tab == 0) printf("Error malloc\n");

    for(int i = 0; i < N; i++){
        tab[i] =0;
    }
    return tab;
}

int nullTabEntierQ(int *tab, int N){

    for(int i = 0; i < N; i++){
        if(tab[i] != 0) return 0;
    }
    return 1;
}

int main(){
    int *tab;
    tab = CreerTabEntier(10);
    if(nullTabEntierQ(tab, 10) == 1) printf("Empty tab");
    else printf("Not empty tab");
    return 0;
}