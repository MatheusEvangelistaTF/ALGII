/*6) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve 
conter o número de matrícula do aluno, seu nome e as notas de três provas. Agora, escreva 
um programa que leia os dados de cinco alunos e os armazene nessa estrutura. Em 
seguida, exiba o nome e as notas do aluno que possui a maior média geral dentre os cinco.*/

#include <stdio.h>

struct Aluno{
    int matricula;
    char nome[50];
    float notas[3];
};

int main(){
    struct Aluno alunos[5];
    float maiorMedia = -1;
    int indiceMaior = 0;
    
for (int i = 0; i < 5; i++){
        printf("Aluno %d\n", i + 1);

        printf("Matrícula: \n");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: \n");
        scanf("%s", alunos[i].nome);

        for (int j = 0; j < 3; j++){
            printf("Nota da prova %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        float soma = 0;
        for (int j = 0; j < 3; j++){
            soma += alunos[i].notas[j];
        }
        float media = soma / 3;

        if (media > maiorMedia){
            maiorMedia = media;
            indiceMaior = i;
        }
    }

    printf("Aluno com maior média\n");
    printf("Nome: %s\n", alunos[indiceMaior].nome);
    printf("Matrícula: %d\n", alunos[indiceMaior].matricula);
    printf("Notas: ");
    for (int j = 0; j < 3; j++){
        printf("%.2f ", alunos[indiceMaior].notas[j]);
    }
    printf("Média: %.2f\n", maiorMedia);


    return 0;
}