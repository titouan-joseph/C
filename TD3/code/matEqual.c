#include <stdio.h>
#include "matrice.h"

int matEqual(int A[N][N], int B[N][N])
{
    for(int i = 0; i<N; i++)
        for(int j =0; j<N; j++)
            if(A[i][j] != B[i][j])
                return 1;

    return 0;
}