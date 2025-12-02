#include <stdio.h>
#include <stdlib.h>

struct Cliente{
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

int main(){
    FILE *arqClientes;
    struct Cliente cliente;
    int qtd, i;

    arqClientes = fopen("Clientes.dat", "ab");

    if (arqClientes == NULL){
        printf("Erro ao abrir o arquivo Clientes.dat\n");
        return 1;
    }

    printf("Quantos clientes deseja cadastrar? ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++){
        printf("\nCadastro do cliente %d:\n", i + 1);

        printf("Código: ");
        scanf("%d", &cliente.Cod_Cli);

        printf("Nome: ");
        scanf("%s", cliente.Nome);

        printf("Endereço: ");
        scanf("%s", cliente.Endereco);

        printf("Fone: ");
        scanf("%s", cliente.Fone);

        fwrite(&cliente, sizeof(struct Cliente), 1, arqClientes);
    }

    printf("\n Clientes cadastrados com sucesso!\n");

    fclose(arqClientes);
    return 0;
}
