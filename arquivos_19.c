/*19 – Faça um programa para alterar os preços dos produtos em R$ 10,00,
mas apenas os produtos que já custam mais de R$ 100,00.*/

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
        if (p.preco > 100){
            p.preco = p.preco + 10.0;
        }
        fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(arq);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    printf("Atualizacao concluida!\n");

    return 0;
}
