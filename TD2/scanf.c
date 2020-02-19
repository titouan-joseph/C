#include <stdio.h>

int main()
{
    int nb;
    printf("Saisir un entier ");
    scanf("%d", &nb);
    for(int i=0; i<nb; i++)
    {
        printf("Square of %d is %10d \n",i, i^2);
    }

    return (0);
}
