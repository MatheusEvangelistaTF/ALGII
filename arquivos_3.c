/*3 - Faça um programa que inclua recebimentos no arquivo criado no
Exercício 1, devendo verificar se o cliente já se encontra cadastrado.*/

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

int clienteExiste(int codigo){
    FILE *arqClientes = fopen("Clientes.dat", "rb");
    struct Cliente c;

    if (arqClientes == NULL){
        printf("Erro ao abrir Clientes.dat!\n");
        return 0;
    }

    while (fread(&c, sizeof(struct Cliente), 1, arqClientes) == 1){
        if (c.Cod_Cli == codigo){
            fclose(arqClientes);
            return 1; 
        }
    }

    fclose(arqClientes);
    return 0; 
}

int main(){
    FILE *arqRecebimentos;
    struct Recebimento r;
    int qtd, i;

    arqRecebimentos = fopen("Recebimentos.dat", "ab");

    if (arqRecebimentos == NULL){
        printf("Erro ao abrir Recebimentos.dat\n");
        return 1;
    }

    printf("Quantos recebimentos deseja cadastrar? ");
    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++){
        printf("\nRecebimento %d:\n", i + 1);

        printf("Código do Cliente: ");
        scanf("%d", &r.Cod_Cli);

        if (!clienteExiste(r.Cod_Cli)){
            printf("ERRO: Cliente %d não cadastrado. Recebimento ignorado.\n", r.Cod_Cli);
        }

        printf("Número do documento: ");
        scanf("%d", &r.Num_doc);

        printf("Valor do documento: ");
        scanf("%f", &r.Valor_doc);

        printf("Data de emissão (dd/mm/aaaa): ");
        scanf("%s", r.Data_Emissao);

        printf("Data de vencimento (dd/mm/aaaa): ");
        scanf("%s", r.Data_Vencimento);

        fwrite(&r, sizeof(struct Recebimento), 1, arqRecebimentos);
        printf("Recebimento cadastrado com sucesso!\n");
    }

    fclose(arqRecebimentos);
    return 0;
}
