#include <stdio.h>
#define N 5

int produit_scalaire(int A[N], int B [N])
{
    int res;
    for(int i=0; i < N; i++)
    {
        res += A[i]*B[i];
    }

    return res;
}

int main()
{
    int A[5] = {1,2,3,4,5};
    int B[5] = {5,4,3,2,1};
    printf("%d", produit_scalaire(A, B));

    return 0;
}