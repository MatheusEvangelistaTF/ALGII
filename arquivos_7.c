/*7 - Faça um programa que mostre todos os recebimentos com data de
vencimento dentro de um período qualquer. Não esqueça de mostrar também
o nome do cliente e o total de dias em atraso. Quando não houver atraso,
mostrar zero.*/

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

int transformarData(char d[]){
    int dia, mes, ano;
    sscanf(d, "%d/%d/%d", &dia, &mes, &ano);
    return ano*10000 + mes*100 + dia;
}

int main(){
    FILE *arqR, *arqC;
    struct Recebimento r;
    struct Cliente c;
    char dataIni[11], dataFim[11];
    int ini, fim;
    int dataRec;
    int acheiCli;

    arqR = fopen("Recebimentos.dat", "rb");
    arqC = fopen("Clientes.dat", "rb");

    if(arqR == NULL || arqC == NULL){
        printf("Erro ao abrir arquivos.\n");
        return 0;
    }

    printf("Data inicial (DD/MM/AAAA): ");
    scanf("%s", dataIni);

    printf("Data final (DD/MM/AAAA): ");
    scanf("%s", dataFim);

    ini = transformarData(dataIni);
    fim = transformarData(dataFim);

    printf("\n--- Recebimentos no periodo ---\n\n");

    while(fread(&r, sizeof(struct Recebimento), 1, arqR) == 1){
        dataRec = transformarData(r.Data_Vencimento);

        if(dataRec >= ini && dataRec <= fim){

            rewind(arqC);
            acheiCli = 0;

            while(fread(&c, sizeof(struct Cliente), 1, arqC) == 1){
                if(c.Cod_Cli == r.Cod_Cli){
                    acheiCli = 1;
                    break;
                }
            }

            printf("Documento: %d\n", r.Num_doc);
            printf("Valor: %.2f\n", r.Valor_doc);
            printf("Vencimento: %s\n", r.Data_Vencimento);

            if(acheiCli)
                printf("Cliente: %s\n", c.Nome);
            else
                printf("Cliente: (nao encontrado)\n");

            int atraso = transformarData("01/01/2024"); 
            atraso = 0;

            if(dataRec < ini)
                atraso = ini - dataRec;
            else
                atraso = 0;

            printf("Dias em atraso: %d\n\n", atraso);
        }
    }

    fclose(arqR);
    fclose(arqC);
    return 0;
}
