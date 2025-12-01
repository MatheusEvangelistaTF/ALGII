/*8) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou igual
a zero, um ponteiro nulo deverá ser retornado*/

#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int N){
    if (N <= 0){
        return NULL;  
    }

    int *vetor = malloc(N * sizeof(int));

    if (vetor == NULL){
        printf("Erro ao alocar memória!\n");
        return NULL;  
    }
    return vetor;
}

int main(){
    int N;

    printf("Digite o valor de N: \n");
    scanf("%d", &N);
    
    int *v = criarVetor(N);

    if (v == NULL){
        printf("N inválido ou memória não alocada!\n");
    }
    else{
        printf("Vetor de tamanho %d alocado com sucesso!\n", N);
        free(v);  
    }
    return 0;
}
