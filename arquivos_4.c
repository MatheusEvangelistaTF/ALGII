/*4 - Faça um programa que exclua clientes e, consequentemente, todos os seus
recebimentos, dos arquivos criados no Exercício l.*/

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
    char Data_Emissao[6];     
    char Data_Vencimento[6];
    int Cod_Cli;
};

int main(){
    int codigoExcluir;
    FILE *arqCli, *arqTempCli;
    FILE *arqRec, *arqTempRec;
    struct Cliente c;
    struct Recebimento r;
    int encontrado = 0;

    printf("Digite o código do cliente a ser excluído: ");
    scanf("%d", &codigoExcluir);

    arqCli = fopen("Clientes.dat", "rb");
    arqTempCli = fopen("temp.dat", "wb");

    if (arqCli == NULL || arqTempCli == NULL) {
        printf("Erro ao abrir arquivos de cliente!\n");
        return 1;
    }

    while (fread(&c, sizeof(struct Cliente), 1, arqCli) == 1) {
        if (c.Cod_Cli == codigoExcluir) {
            encontrado = 1;  
            continue;      
        }
        fwrite(&c, sizeof(struct Cliente), 1, arqTempCli);
    }

    fclose(arqCli);
    fclose(arqTempCli);

    if (!encontrado) {
        printf("Cliente %d não encontrado. Nada foi excluído.\n", codigoExcluir);
        remove("temp.dat");
        return 0;
    }

    remove("Clientes.dat");
    rename("temp.dat", "Clientes.dat");

    printf("Cliente %d excluído com sucesso!\n", codigoExcluir);

    arqRec = fopen("Recebimentos.dat", "rb");
    arqTempRec = fopen("temp_rec.dat", "wb");

    if (arqRec == NULL || arqTempRec == NULL) {
        printf("Erro ao abrir arquivos de recebimentos!\n");
        return 1;
    }

    while (fread(&r, sizeof(struct Recebimento), 1, arqRec) == 1) {
        if (r.Cod_Cli == codigoExcluir) {
            continue; 
        }
        fwrite(&r, sizeof(struct Recebimento), 1, arqTempRec);
    }

    fclose(arqRec);
    fclose(arqTempRec);

    remove("Recebimentos.dat");
    rename("temp_rec.dat", "Recebimentos.dat");

    printf("Todos os recebimentos do cliente %d foram excluídos.\n", codigoExcluir);

    return 0;
}
