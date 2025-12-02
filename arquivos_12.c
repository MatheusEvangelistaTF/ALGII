/*12 - Faça um programa para criar os arquivos a seguir:
-Estilista (código do estilista, nome do estilista, salário)
-Roupa (código da roupa, descrição da roupa, código do estilista,
código da estação, ano)
-Estação (código da estação, nome da estação)*/

#include <stdio.h>
#include <stdlib.h>

struct Estilista{
    int cod;
    char nome[50];
    float salario;
};

struct Roupa{
    int codRoupa;
    char desc[50];
    int codEstilista;
    int codEstacao;
    int ano;
};

struct Estacao{
    int codEstacao;
    char nomeEstacao[30];
};

int main(){
    FILE *arqE, *arqR, *arqEs;

    arqE = fopen("Estilistas.dat", "wb");
    arqR = fopen("Roupas.dat", "wb");
    arqEs = fopen("Estacoes.dat", "wb");

    if(arqE == NULL || arqR == NULL || arqEs == NULL){
        printf("Nao foi possivel criar os arquivos.\n");
        return 0;
    }

    printf("Arquivos criados com sucesso.\n");

    fclose(arqE);
    fclose(arqR);
    fclose(arqEs);

    return 0;
}
