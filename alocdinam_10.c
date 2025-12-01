#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int N, int valor){
    if (N <= 0)
        return NULL; 
        
    int *vetor = malloc(N * sizeof(int));

    if (vetor == NULL)
        return NULL;

    for (int i = 0; i < N; i++){
        vetor[i] = valor;
    }

    return vetor;
}

int main(){
    int N, valor;

    printf("Digite N: ");
    scanf("%d", &N);

    printf("Digite o valor para preencher o vetor: ");
    scanf("%d", &valor);

    int *v = criarVetor(N, valor);

    if (v == NULL){
        printf("N inválido ou erro de alocação.\n");
        return 1;
    }

    printf("Vetor criado:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}
