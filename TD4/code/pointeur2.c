#include <stdio.h>

int main()
{
  int i = 3, j = 6;
  int *p1, *p2;

  p1 = &i;
  p2 = &j;
  *p1 = *p2;

  printf("i = %d \n", i);
  printf("@i = 0x%p \n",&i);
  printf("j = %d \n", j);
  printf("@j = 0x%p \n",&j);
  printf("p1 = %lx \n", (long unsigned int)p1);
  printf("@p1 = 0x%p \n",&p1);
  printf("*p1 = %d \n", *p1);
  printf("@*p1 = 0x%p \n",&*p1);
  printf("p2 = %lx \n", (long unsigned int)p2);
  printf("@p2 = 0x%p \n",&p2);
  printf("*p2 = %d \n", *p2);
  printf("@*p2 = 0x%p \n",&*p2);


}
