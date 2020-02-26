#include <stdio.h>
#include "matrice.h"
#include "matProd.h"

int matProd(int A[N][N], int B[N][N], int C[N][N])
{
    for(int i =0; i<N; i++)
        for(int j=0; j<N; j++)
            C[i][j] = 0;

    for(int i = 0; i < N; i++)
    {
       for(int j = 0; j < N; j++)
       {
           for(int k = 0; k < N; k++)
           {
               C[i][j] += (A[i][k])*(B[k][j]);
           }
       }
    }
  return 0;
}
