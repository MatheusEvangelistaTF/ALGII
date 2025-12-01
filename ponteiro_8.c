/*8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo tipo do
vetor. A função deverá preencher os elementos de vetor com esse valor. Não utilize
índices para percorrer o vetor, apenas aritmética de ponteiros.*/

#include <stdio.h>

void preencher(int *vetor, int tamanho, int valor){
    int *p = vetor;
    int *fim = vetor + tamanho;

    while (p < fim){
        *p = valor;   
        p++;         
    }
}

int main(){
    int n, valor;

    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    printf("Valor para preencher: ");
    scanf("%d", &valor);

    preencher(vetor, n, valor);

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    return 0;
}
