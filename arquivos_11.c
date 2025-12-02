/*11 - Faça um programa que mostre todos os recebimentos com valor entre
dois valores dados pelo usuário.*/

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
    float min, max;
    int achei = 0;

    arq = fopen("Recebimentos.dat", "rb");

    if(arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    printf("Valor minimo: ");
    scanf("%f", &min);

    printf("Valor maximo: ");
    scanf("%f", &max);

    printf("\n--- Recebimentos entre %.2f e %.2f ---\n\n", min, max);

    while(fread(&r, sizeof(struct Recebimento), 1, arq) == 1){
        if(r.Valor_doc >= min && r.Valor_doc <= max){
            achei = 1;
            printf("Doc: %d\n", r.Num_doc);
            printf("Valor: %.2f\n", r.Valor_doc);
            printf("Emissao: %s\n", r.Data_Emissao);
            printf("Vencimento: %s\n\n", r.Data_Vencimento);
        }
    }

    if(!achei){
        printf("Nenhum recebimento nesse intervalo.\n");
    }

    fclose(arq);
    return 0;
}
