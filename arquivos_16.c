/*16 - Faça um programa para incluir produtos no arquivo criado no Exercício
15 lembrando que não podem existir dois produtos com o mesmo código.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    int codigo;
    char descricao[50];
    float preco;
};

int codigoExiste(int cod){
    struct Produto p;
    FILE *arq = fopen("PRODUTOS.txt", "r");

    if (arq == NULL) return 0;

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){
        if (p.codigo == cod){
            fclose(arq);
            return 1; 
        }
    }

    fclose(arq);
    return 0;
}

int main(){
    struct Produto p;
    FILE *arq;

    arq = fopen("PRODUTOS.txt", "a");
    if (arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o codigo do produto: ");
    scanf("%d", &p.codigo);

    if (codigoExiste(p.codigo)){
        printf("Codigo ja cadastrado! Operacao cancelada.\n");
        fclose(arq);
        return 0;
    }

    printf("Descricao: ");
    scanf("%s", p.descricao);

    printf("Preco: ");
    scanf("%f", &p.preco);

    fprintf(arq, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);

    printf("Produto cadastrado com sucesso!\n");

    fclose(arq);
    return 0;
}
