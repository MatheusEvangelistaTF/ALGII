/*15 - Faça um programa para criar um arquivo chamado PRODUTOS.txt,
onde cada registro será composto pelos seguintes campos: codigo, descricao
e preco.*/

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char descricao[50];
    float preco;
};

int main(){
    FILE *arq;
    
    arq = fopen("PRODUTOS.txt", "w");
    if (arq == NULL){
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    printf("Arquivo PRODUTOS.txt criado com sucesso!\n");

    fclose(arq);
    return 0;
}
