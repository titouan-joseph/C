#include <stdio.h>

int main()
{
  int i = 3;
  int *p;

  p = &i;

  printf("*p = %d \n",*p);
  printf("p = 0x%lX \n",(long unsigned int)p);
  printf("@p = 0x%p \n",&p);
}
