/*14) Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho N
cada. A função deve retornar o ponteiro para um vetor C de tamanho N alocado
dinamicamente, em que C[i] = A[i] + B[i]*/

#include <stdio.h>
#include <stdlib.h>

int* somaVetores(int *A, int *B, int N){
    if (N <= 0) return NULL;

    int *C = (int*) malloc(N * sizeof(int));
    if (C == NULL) return NULL;

    for (int i = 0; i < N; i++){
        C[i] = A[i] + B[i];
    }

    return C;
}

int main(){
    int N;

    printf("Digite o tamanho dos vetores: \n");
    scanf("%d", &N);

    if (N <= 0){
        printf("Tamanho invalido.\n");
        return 1;
    }

    int *A = malloc(N * sizeof(int));
    int *B = malloc(N * sizeof(int));

    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < N; i++)
        scanf("%d", &B[i]);

    int *C = somaVetores(A, B, N);

    printf("\nVetor C (soma):\n");
    for (int i = 0; i < N; i++)
        printf("%d ", C[i]);

    free(A);
    free(B);
    free(C);

    return 0;
}
