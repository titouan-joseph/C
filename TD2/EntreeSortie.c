#include <stdio.h>

int main()
{
    float f;
    char c;

    printf("Saisir un float");
    scanf("%f", &f);
    printf("Vous avez saisi : %f\n", f);

    printf("Saisir un char");
    while( getchar() != '\n');
    scanf("%c", &c);
    printf("Vous avez saisi : %c\n", c);

    printf("Saisir un char\n");
    c = getc(stdin);
    printf("Vous avez saisi : %d\n", c);


}