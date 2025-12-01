/*17) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas. A função deve retornar o ponteiro para um vetor B de tamanho N alocado
dinamicamente, em que cada posição de B é a soma dos números daquela coluna da
matriz.*/
#include <stdio.h>
#include <stdlib.h>

int* somaColunas(int **A, int N){
    if (N <= 0) return NULL;

    int *B = (int*) malloc(N * sizeof(int));
    if (B == NULL) return NULL;

    for (int j = 0; j < N; j++)
        B[j] = 0;

    for (int j = 0; j < N; j++){       
        for (int i = 0; i < N; i++){   
            B[j] += A[i][j];
        }
    }
    return B;
}

int main(){
    int N;

    printf("Digite N: \n");
    scanf("%d", &N);

    int **A = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        A[i] = malloc(N * sizeof(int));

    printf("Digite os elementos da matriz A (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    int *B = somaColunas(A, N);

    printf("\nVetor B (soma das colunas):\n");
    for (int j = 0; j < N; j++)
        printf("%d ", B[j]);
    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
    free(B);

    return 0;
}
