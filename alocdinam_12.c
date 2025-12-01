/*12) Escreva uma função que receba como parâmetro um valor N e retorne o ponteiro para
uma matriz alocada dinamicamente contendo N linhas e N colunas. Essa matriz deve
conter o valor 1 na diagonal secundária e 0 nas demais posições.*/

#include <stdio.h>
#include <stdlib.h>

int **criaMatrizDiagonalSecundaria(int N){
    if (N <= 0) return NULL;
    int **mat = malloc(N * sizeof(int *));
    if (mat == NULL) return NULL;

    for (int i = 0; i < N; i++){
        mat[i] = malloc(N * sizeof(int));
        if (mat[i] == NULL){
            for (int j = 0; j < i; j++){
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (j == N - 1 - i)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    return mat;
}

int main(){
    int N = 5;
    int **m = criaMatrizDiagonalSecundaria(N);

    if (m == NULL){
        printf("Erro ao alocar matriz!\n");
        return 1;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) free(m[i]);
    free(m);
    return 0;
}

