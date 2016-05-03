// g++ Lista2-atv3.cpp -o Lista2-atv3

#include <iostream>

int[] ordenacao_selecao(int[] A)
{
    int j = sizeof(A)/sizeof(A[0]);
    int max;
    int chave;

    while(j != 1)
    {
        max = j;
        chave = A[j];

        for(int i = 1; i <= j-1; j++)
            if(A[i] > A[max])
                max = i;

        A[j] = A[max];
        A[max] = chave;
        j--;
    }

    return A;
}

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}
