/*5 - Faça um programa que altere o cadastro de clientes do Exercício 1. O
usuário deve informar o código do cliente que será alterado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente{
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

int main(){
    FILE *arq = fopen("Clientes.dat", "rb+");  
    struct Cliente cli;
    int codigo;
    int achou = 0;

    if (arq == NULL){
        printf("Erro ao abrir arquivo Clientes.dat\n");
        return 1;
    }

    printf("Digite o código do cliente que deseja alterar: ");
    scanf("%d", &codigo);

    while (fread(&cli, sizeof(struct Cliente), 1, arq) == 1){
        if (cli.Cod_Cli == codigo){
            achou = 1;

            printf("Cliente encontrado!\n");
            printf("Nome atual: %s\n", cli.Nome);
            printf("Endereco atual: %s\n", cli.Endereco);
            printf("Fone atual: %s\n", cli.Fone);

            printf("\nDigite os novos dados:\n");
            printf("Novo nome: ");
            scanf("%s", cli.Nome);

            printf("Novo endereco: ");
            scanf("%s", cli.Endereco);

            printf("Novo fone: ");
            scanf("%s", cli.Fone);

            fseek(arq, -sizeof(struct Cliente), SEEK_CUR);

            fwrite(&cli, sizeof(struct Cliente), 1, arq);

            printf("\n Cadastro alterado com sucesso! \n");
            break;
        }
    }

    if (!achou)
        printf("\nCliente não encontrado.\n");

    fclose(arq);
    return 0;
}
