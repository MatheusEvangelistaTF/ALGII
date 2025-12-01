/*4) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em seguida,
faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o imprima*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int*) malloc(n * sizeof(int));

    if (vetor == NULL){
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    printf("\nVetor lido:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    
    free(vetor);

    return 0;
}
