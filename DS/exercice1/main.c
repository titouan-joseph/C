#include<stdio.h>

int maxTab(int tableau[5]){
    int max;
    for(int i = 0; i < 5; i++){
        max = (tableau[i] > max) ? tableau[i] : max;
    }
    return max;
}

int main(){
    int tab[5] = {2, 44, 5, 7, 12};
    int max = maxTab(tab);
    printf("la valeur max est : %d", max);
    return 0;
}