/*14 - Faça um programa que apresente o seguinte menu de opções:
1. Criar
2. Incluir
3. Sair
Digite a opção desejada
Na opcão 1: criar um arquivo com os campos: numero, nome, nota1 e nota2.
Na opção 2: incluir todos os dados digitados, podendo haver repetição. No
final da inclusão após pressionar ENTER o programa deve mostrar todos os
registros cadastrados, calcular e mostrar a média das notas de cada registro.*/

#include <stdio.h>
#include <stdlib.h>

struct Registro{
    int numero;
    char nome[50];
    float nota1;
    float nota2;
};

int main(){

    FILE *arq;
    struct Registro r;
    int opc;
    char cont;

    do{
        printf("\n1 - Criar arquivo");
        printf("\n2 - Incluir");
        printf("\n3 - Sair");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opc);

        if (opc == 1){
            arq = fopen("alunos.dat", "wb");
            if (arq == NULL){
                printf("Erro ao criar.\n");
                return 1;
            }
            printf("Arquivo criado com sucesso!\n");
            fclose(arq);
        }

        else if (opc == 2){
            arq = fopen("alunos.dat", "ab+");
            if (arq == NULL){
                printf("Arquivo nao existe. Crie primeiro.\n");
                continue;
            }

            do{
                printf("\nNumero: ");
                scanf("%d", &r.numero);

                printf("Nome: ");
                scanf(" %49[^\n]", r.nome);

                printf("Nota 1: ");
                scanf("%f", &r.nota1);

                printf("Nota 2: ");
                scanf("%f", &r.nota2);

                fwrite(&r, sizeof(struct Registro), 1, arq);

                printf("Deseja incluir outro? (s/n): ");
                scanf(" %c", &cont);

            } while (cont == 's' || cont == 'S');

            rewind(arq);

            printf("REGISTROS CADASTRADOS\n");

            while (fread(&r, sizeof(struct Registro), 1, arq) == 1) {
                float media = (r.nota1 + r.nota2) / 2;
                printf("\nNumero: %d\n", r.numero);
                printf("Nome: %s\n", r.nome);
                printf("Nota 1: %.2f  |  Nota 2: %.2f\n", r.nota1, r.nota2);
                printf("Media: %.2f\n", media);
            }

            fclose(arq);
        }

        else if (opc != 3){
            printf("Opcao invalida!\n");
        }

    } while (opc != 3);

    return 0;
}
