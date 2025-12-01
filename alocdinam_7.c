/*7) Faça uma função que retorne o ponteiro para um vetor de N elementos inteiros alocados
dinamicamente. O array deve ser preenchido com valores de 0 a N − 1.*/

#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int N){
    int *vetor = malloc(N * sizeof(int));

    if (vetor == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++){
        vetor[i] = i;
    }

    return vetor;
}

int main(){
    int N;
    
    printf("Digite o valor de N: \n");
    scanf("%d", &N);

    int *v = criarVetor(N);

    printf("Vetor criado: ");
    for (int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
