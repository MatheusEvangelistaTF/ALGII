/*11) Escreva uma função que receba como parâmetro um valor N e retorne o ponteiro para
uma matriz alocada dinamicamente contendo N linhas e N colunas. Essa matriz deve
conter o valor 1 na diagonal principal e 0 nas demais posições.*/

#include <stdio.h>
#include <stdlib.h>

int** criarMatrizIdentidade(int N){
    if (N <= 0)
        return NULL;  
    
    int **matriz = malloc(N * sizeof(int*));

    if (matriz == NULL)
        return NULL;

    for (int i = 0; i < N; i++){
        matriz[i] = malloc(N * sizeof(int));
        if (matriz[i] == NULL)
            return NULL; 
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
    return matriz;
}

int main(){
    int N;

    printf("Digite o valor N: \n");
    scanf("%d", &N);

    int **mat = criarMatrizIdentidade(N);

    if (mat == NULL){
        printf("Erro ao criar matriz.\n");
        return 1;
    }

    printf("\n Matriz identidade %dx%d:\n", N, N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++)
        free(mat[i]);

    free(mat);
    return 0;
}
