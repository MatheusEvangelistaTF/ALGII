/*6) Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões
da matriz deverão ser lidas do usuário. Em seguida, escreva uma função que receba um
valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no caso contrário.*/

#include <stdio.h>
#include <stdlib.h>

int buscarValor(int **matriz, int linhas, int colunas, int valor){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matriz[i][j] == valor)
                return 1;  
        }
    }
    return 0; 
}

int main(){
    int linhas, colunas;

    printf("Informe o número de linhas: ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas: ");
    scanf("%d", &colunas);

    int **matriz = malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }

    printf("\n Digite os valores da matriz:\n");
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("M[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int valor;
    printf("\nDigite um valor para procurar: ");
    scanf("%d", &valor);

    if (buscarValor(matriz, linhas, colunas, valor))
        printf("O valor %d está na matriz.\n", valor);
    else
        printf("O valor %d NÃO está na matriz.\n", valor);
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);

    free(matriz);

    return 0;
}
