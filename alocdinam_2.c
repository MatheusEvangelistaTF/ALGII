/*2) Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve
conter o número de matrícula do aluno, seu nome e as notas de três provas. Escreva um
programa que mostre o tamanho em byte dessa estrutura.*/

#include <stdio.h>

struct aluno{
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

int main(){
    struct aluno Alunos;
    
    printf("Tamanho da estrutura em byte %zu \n", sizeof(Alunos));

    return 0;
}