/*13) Escreva um programa que leia um inteiro N e crie uma matriz alocada dinamicamente
contendo N linhas e N colunas. Essa matriz deve conter o valor 0 na diagonal principal,
o valor 1 nos elementos acima da diagonal principal e o valor −1 nos elementos abaixo
da diagonal principal.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    printf("Digite o valor de N:\n");
    scanf("%d", &N);

    if (N <= 0){
        printf("Valor invalido!\n");
        return 1;
    }

    int **mat = malloc(N * sizeof(int *));
    if (mat == NULL){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < N; i++){
        mat[i] = malloc(N * sizeof(int));
        if (mat[i] == NULL){
            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            printf("Erro ao alocar memória!\n");
            return 1;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j)
                mat[i][j] = 0;     
            else if (j > i)
                mat[i][j] = 1;     
            else
                mat[i][j] = -1;   
        }
    }

    printf("\n Matriz resultante:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%2d ", mat[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
        free(mat[i]);
    free(mat);

    return 0;
}
