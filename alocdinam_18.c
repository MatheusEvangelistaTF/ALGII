/*18) Escreva uma função que receba como parâmetro duas matrizes, A e B, e seus
tamanhos. A função deve retornar o ponteiro para uma matriz C, em que C é o produto
da multiplicação da matriz A pela matriz B. Se a multiplicação das matrizes não for
possível, retorne um ponteiro nulo.*/

#include <stdio.h>
#include <stdlib.h>

int** multiplicaMatrizes(int **A, int **B, int m, int n, int p){

    if (n <= 0 || m <= 0 || p <= 0) return NULL;

    int **C = (int**) malloc(m * sizeof(int*));
    if (C == NULL) return NULL;

    for (int i = 0; i < m; i++){
        C[i] = (int*) malloc(p * sizeof(int));
        if (C[i] == NULL) return NULL;
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){

            C[i][j] = 0;

            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }

        }
    }
    return C;
}

int main(){
    int m, n, p;

    printf("Digite m (linhas de A): \n");
    scanf("%d", &m);
    printf("Digite n (colunas de A = linhas de B): \n");
    scanf("%d", &n);
    printf("Digite p (colunas de B): \n");
    scanf("%d", &p);

    int **A = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
        A[i] = malloc(n * sizeof(int));

    int **B = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        B[i] = malloc(p * sizeof(int));

    printf("\n Digite a matriz A (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("\n Digite a matriz B (%dx%d):\n", n, p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    int **C = multiplicaMatrizes(A, B, m, n, p);

    if (C == NULL){
        printf("Multiplicacao nao e possivel.\n");
        return 1;
    }

    printf("\n Matriz C = A x B:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            printf("%d ", C[i][j]);
        }
    }

    for (int i = 0; i < m; i++) free(A[i]);
    free(A);
    for (int i = 0; i < n; i++) free(B[i]);
    free(B);
    for (int i = 0; i < m; i++) free(C[i]);
    free(C);

    return 0;
}

