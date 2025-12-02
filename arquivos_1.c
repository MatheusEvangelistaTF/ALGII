/*1 - Faça um programa para criar os arquivos a seguir:
Clientes: Cod_Cli, Nome, Endereco, Fone
Recebimentos: Num_doc, Valor_doc, Data_Emissao, Data_Vencimento,
Cod_Cli.*/

#include <stdio.h>
#include <stdlib.h>

struct Cliente{
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

struct Recebimento{
    int Num_doc;
    float Valor_doc;
    char Data_Emissao[11];
    char Data_Vencimento[11];
    int Cod_Cli;
};

int main(){

    FILE *arqClientes = fopen("Clientes.dat", "ab");
    FILE *arqRecebimentos = fopen("Recebimentos.dat", "ab");

    if (arqClientes == NULL || arqRecebimentos == NULL){
        printf("Erro ao criar os arquivos.\n");
        return 1;
    }

    printf("Arquivos criados com sucesso!\n");

    fclose(arqClientes);
    fclose(arqRecebimentos);

    return 0;
}
