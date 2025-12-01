/*16) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas, e um vetor B de tamanho N. A função deve retornar o ponteiro para um vetor
C de tamanho N alocado dinamicamente, em que C é o produto da matriz A pelo vetor B.*/

#include <stdio.h>
#include <stdlib.h>

int* produtoMatrizVetor(int **A, int *B, int N){
    if (N <= 0) return NULL;

    int *C = (int*) malloc(N * sizeof(int));
    if (C == NULL) return NULL;

    for (int i = 0; i < N; i++){
        C[i] = 0;
        for (int j = 0; j < N; j++){
            C[i] += A[i][j] * B[j];
        }
    }

    return C;
}

int main(){
    int N;

    printf("Digite N: ");
    scanf("%d", &N);

    int **A = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        A[i] = malloc(N * sizeof(int));
    int *B = malloc(N * sizeof(int));

    printf("Digite os valores da matriz A (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
    printf("Digite os valores do vetor B:\n");
    
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    int *C = produtoMatrizVetor(A, B, N);
    printf("\n Vetor C (resultado):\n");
    
    for (int i = 0; i < N; i++)
        printf("%d ", C[i]);
    printf("\n");
    
    for (int i = 0; i < N; i++)
        free(A[i]);
    free(A);
    free(B);
    free(C);

    return 0;
}

