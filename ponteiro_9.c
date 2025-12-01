/*9) Crie uma função que receba como parâmetro um vetor e o imprima. Não utilize índices
para percorrer o vetor, apenas aritmética de ponteiros.*/

#include <stdio.h>

void imprimeVetor(int *p, int tamanho){
    int *fim = p + tamanho;   

    while (p < fim){
        printf("%d ", *p);    
        p++;                  
    }
    printf("\n");
}

int main(){
    int vetor[5] = {10, 20, 30, 40, 50};

    imprimeVetor(vetor, 5);

    return 0;
}

