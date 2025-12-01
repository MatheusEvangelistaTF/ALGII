/*1) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
estrutura lida.*/

#include <stdio.h>
#include <string.h>

struct Pessoas{
    char nome[10];
    int idade;
    char endereco[30];
};



int main(){
    struct Pessoas pessoa;
    int idade;
    char nome[10], endereco[30];
    
    printf("nome do usuario \n");
    scanf("%s", nome);
    printf("idade do usuario \n");
    scanf("%d", &idade);
    printf("endereco do usuario \n");
    scanf("%s", endereco);
    
    strcpy(pessoa.nome, nome);
    pessoa.idade = idade;
    strcpy(pessoa.endereco, endereco);
    
    printf("Nome: %s \n", pessoa.nome);
    printf("Idade: %d \n", pessoa.idade);
    printf("Endereco: %s \n", pessoa.endereco);

    return 0;
}