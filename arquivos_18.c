/*18 – Faça um programa para alterar os preços de todos os produtos em 15%*/

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char descricao[50];
    float preco;
};

int main(){
    FILE *arq, *temp;
    struct Produto p;

    arq = fopen("PRODUTOS.txt", "r");
    if (arq == NULL){
        printf("Arquivo PRODUTOS.txt nao encontrado.\n");
        return 1;
    }

    temp = fopen("TEMP.txt", "w");
    if (temp == NULL){
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arq);
        return 1;
    }

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){
        p.preco = p.preco * 1.15; 
        fprintf(temp, "%d %s %.2f\n", p.codigo
