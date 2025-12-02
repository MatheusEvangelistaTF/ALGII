/*23 – Faça um programa para consultar todos os produtos com nomes
começados por uma letra digitada pelo usuário e com preços entre dois
valores também fornecidos pelo usuário.*/

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
    char letra;
    float v1, v2;
    int achou = 0;

    arq = fopen("PRODUTOS.txt", "r");
    if (arq == NULL){
        printf("Arquivo nao encontrado.\n");
        return 1;
    }

    printf("Digite a letra inicial do produto: ");
    scanf(" %c", &letra);

    printf("Digite o valor minimo: ");
    scanf("%f", &v1);

    printf("Digite o valor maximo: ");
    scanf("%f", &v2);

    printf("\nProdutos encontrados:\n\n");

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){
        if ((p.descricao[0] == letra || p.descricao[0] == letra + 32 || p.descricao[0] == letra - 32)
            && p.preco >= v1 && p.preco <= v2){

            printf("Codigo: %d\n", p.codigo);
            printf("Descricao: %s\n", p.descricao);
            printf("Preco: %.2f\n\n", p.preco);
            achou = 1;
        }
    }

    if (!achou){
        printf("Nenhum produto encontrado.\n");
    }

    fclose
