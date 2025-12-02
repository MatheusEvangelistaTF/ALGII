/*24 – Faça um programa para excluir todos os produtos com preço superior a
R$ 200,00.*/

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
    int excluiu = 0;

    arq = fopen("PRODUTOS.txt", "r");
    if (arq == NULL){
        printf("Arquivo nao encontrado.\n");
        return 1;
    }

    temp = fopen("TEMP.txt", "w");
    if (temp == NULL){
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arq);
        return 1;
    }

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3) {
        if (p.preco > 200.0) {
            excluiu = 1;  
        } else {
            fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        }
    }

    fclose(arq);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    if (excluiu)
        printf("Produtos com preco superior a R$ 200,00 foram excluidos.\n");
    else
        printf("Nenhum produto foi excluido.\n");

    return 0;
}
