/*6 - Faça um programa que altere um recebimento de um cliente, ou seja, o
usuário informa o número do documento e o número do cliente e faz as
alterações desejadas.*/

#include <stdio.h>
#include <stdlib.h>

struct Recebimento{
    int Num_doc;
    float Valor_doc;
    char Data_Emissao[11];
    char Data_Vencimento[11];
    int Cod_Cli;
};

int main(){
    FILE *arq;
    struct Recebimento r;
    int doc, cod;
    int achei = 0;

    arq = fopen("Recebimentos.dat", "rb+");

    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    printf("Numero do documento: ");
    scanf("%d", &doc);

    printf("Codigo do cliente: ");
    scanf("%d", &cod);

    while(fread(&r, sizeof(struct Recebimento), 1, arq) == 1){
        if(r.Num_doc == doc && r.Cod_Cli == cod){
            achei = 1;

            printf("\n--- Recebimento encontrado ---\n");
            printf("Valor atual: %.2f\n", r.Valor_doc);
            printf("Emissao: %s\n", r.Data_Emissao);
            printf("Vencimento: %s\n", r.Data_Vencimento);

            printf("\nDigite os novos dados:\n");

            printf("Novo valor: ");
            scanf("%f", &r.Valor_doc);

            printf("Nova emissao: ");
            scanf("%s", r.Data_Emissao);

            printf("Novo vencimento: ");
            scanf("%s", r.Data_Vencimento);

            fseek(arq, -sizeof(struct Recebimento), SEEK_CUR);
            fwrite(&r, sizeof(struct Recebimento), 1, arq);

            printf("\nAlterado com sucesso.\n");
            break;
        }
    }

    if(!achei){
        printf("Recebimento nao encontrado.\n");
    }

    fclose(arq);
    return 0;
}

