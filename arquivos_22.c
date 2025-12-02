/*22 – Faça um programa para consultar os produtos com preços inferiores a
R$ 15,00.*/

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char descricao[50];
    float preco;
};

int main(){
    FILE *arq;
    struct Produto p;
    int achou = 0;

    arq = fopen("PRODUTOS.txt", "r");
    if (arq == NULL){
        printf("Arquivo nao encontrado.\n");
        return 1;
    }

    printf("Produtos com preco inferior a R$ 15,00:\n\n");

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3) {
        if (p.preco < 15.0){
            printf("Codigo: %d\n", p.codigo);
            printf("Descricao: %s\n", p.descricao);
            printf("Preco: %.2f\n\n", p.preco);
            achou = 1;
        }
    }

    if (!achou){
        printf("Nenhum produto encontrado.\n");
    }

    fclose(arq);
    return 0;
}
