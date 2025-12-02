/*21 – Faça um programa para excluir produtos do arquivo criado no Exercício 15.*/

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
    int codDel, achou = 0;

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

    printf("Digite o codigo do produto que deseja excluir: ");
    scanf("%d", &codDel);

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){
        if (p.codigo == codDel){
            achou = 1;  
        } else{
            fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
        }
    }

    fclose(arq);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    if (achou)
        printf("Produto excluido com sucesso!\n");
    else
        printf("Produto nao encontrado.\n");

    return 0;
}
