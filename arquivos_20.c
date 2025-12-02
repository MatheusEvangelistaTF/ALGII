/*20 – Faça um programa para consultar todos os produtos cujos nomes
comecem pela letra M.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("Produtos que começam com a letra M:\n\n");

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){
        if (p.descricao[0] == 'M' || p.descricao[0] == 'm'){
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
