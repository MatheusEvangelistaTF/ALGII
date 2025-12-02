/*8 - Faça um programa que mostre todos os recebimentos de um determinado
cliente.*/

#include <stdio.h>
#include <stdlib.h>

struct Recebimento{
    int Num_doc;
    float Valor_doc;
    char Data_Emissao[11];
    char Data_Vencimento[11];
    int Cod_Cli;
};

struct Cliente{
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

int main(){
    FILE *arqR, *arqC;
    struct Recebimento r;
    struct Cliente c;
    int codigo;
    int achei = 0, acheiCli = 0;

    arqR = fopen("Recebimentos.dat", "rb");
    arqC = fopen("Clientes.dat", "rb");

    if(arqR == NULL || arqC == NULL){
        printf("Erro ao abrir os arquivos.\n");
        return 0;
    }

    printf("Codigo do cliente: ");
    scanf("%d", &codigo);

    while(fread(&c, sizeof(struct Cliente), 1, arqC) == 1){
        if(c.Cod_Cli == codigo){
            acheiCli = 1;
            break;
        }
    }

    if(acheiCli){
        printf("\nCliente: %s\n\n", c.Nome);
    } else {
        printf("\nCliente nao encontrado.\n\n");
    }

    printf("---- Recebimentos ----\n");

    while(fread(&r, sizeof(struct Recebimento), 1, arqR) == 1){
        if(r.Cod_Cli == codigo){
            achei = 1;
            printf("Doc: %d\n", r.Num_doc);
            printf("Valor: %.2f\n", r.Valor_doc);
            printf("Emissao: %s\n", r.Data_Emissao);
            printf("Vencimento: %s\n\n", r.Data_Vencimento);
        }
    }

    if(!achei){
        printf("Nenhum recebimento encontrado para esse cliente.\n");
    }

    fclose(arqR);
    fclose(arqC);

    return 0;
}
