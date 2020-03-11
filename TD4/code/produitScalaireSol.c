#include <stdio.h>
#include <stdlib.h>

#define N 5

int produit_scalaire(int A[N], int B[N])
{
  int i, res;
  int *p1, *p2;

  p1 = A;
  p2 = B;

  res=0;
  for (i=0;i<N;i++)
    {
      res += (*p1++)* (*p2++);
    }
  return res;
}

int main()
{
//  int A[N]={1,1,1,1,1};
//  int B[N]={1,1,1,1,1};

    int *A,*B,i;
    A = (int *)malloc(N* sizeof(int));
    if (!A) fprintf(stderr,"Allocation error !");
    B = (int *)malloc(N* sizeof(int));
    if (!B) fprintf(stderr,"Allocation error !");

    for(i=0;i<N;i++)
    {
        A[i]=2;
        B[i]=1;
    }

    printf("le produit scalaire vaut %d\n", produit_scalaire(A,B));

    free(A);
    free(B);

  return 0;
}
	 
