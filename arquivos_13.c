/*13 - Faça um programa para:
-Cadastrar as estações climáticas, por exemplo, primavera-verão e
outono-inverno;
-Cadastrar os estilistas;
-Cadastrar as roupas. Lembre-se de que estilista e estação devem ter
sido previamente cadastrados;
-Mostrar um relatório de todas as roupas de uma determinada estação,
informando, inclusive, o nome do estilista que a desenhou.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estacao{
    int cod;
    char nome[30];
};

struct Estilista{
    int cod;
    char nome[50];
    float salario;
};

struct Roupa{
    int cod;
    char desc[50];
    int codEstilista;
    int codEstacao;
    int ano;
};

int existeEstacao(int cod){
    FILE *arq = fopen("Estacoes.dat", "rb");
    struct Estacao e;

    if(arq == NULL) return 0;

    while(fread(&e, sizeof(e), 1, arq) == 1){
        if(e.cod == cod){
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

int existeEstilista(int cod){
    FILE *arq = fopen("Estilistas.dat", "rb");
    struct Estilista e;

    if(arq == NULL) return 0;

    while(fread(&e, sizeof(e), 1, arq) == 1){
        if(e.cod == cod){
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}

void cadastrarEstacao(){
    FILE *arq = fopen("Estacoes.dat", "ab");
    struct Estacao e;

    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Codigo da estacao: ");
    scanf("%d", &e.cod);

    printf("Nome da estacao: ");
    scanf("%s", e.nome);

    fwrite(&e, sizeof(e), 1, arq);

    printf("Estacao cadastrada.\n\n");

    fclose(arq);
}

void cadastrarEstilista(){
    FILE *arq = fopen("Estilistas.dat", "ab");
    struct Estilista e;

    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Codigo do estilista: ");
    scanf("%d", &e.cod);

    printf("Nome do estilista: ");
    scanf("%s", e.nome);

    printf("Salario: ");
    scanf("%f", &e.salario);

    fwrite(&e, sizeof(e), 1, arq);

    printf("Estilista cadastrado.\n\n");

    fclose(arq);
}

void cadastrarRoupa(){
    FILE *arq = fopen("Roupas.dat", "ab");
    struct Roupa r;

    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    printf("Codigo da roupa: ");
    scanf("%d", &r.cod);

    printf("Descricao: ");
    scanf("%s", r.desc);

    printf("Codigo do estilista: ");
    scanf("%d", &r.codEstilista);

    if(!existeEstilista(r.codEstilista)){
        printf("Estilista nao cadastrado.\n\n");
        fclose(arq);
        return;
    }

    printf("Codigo da estacao: ");
    scanf("%d", &r.codEstacao);

    if(!existeEstacao(r.codEstacao)){
        printf("Estacao nao cadastrada.\n\n");
        fclose(arq);
        return;
    }

    printf("Ano da colecao: ");
    scanf("%d", &r.ano);

    fwrite(&r, sizeof(r), 1, arq);

    printf("Roupa cadastrada.\n
