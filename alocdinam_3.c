/*3) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade e o
endereço de uma pessoa. Agora, escreva uma função que receba um inteiro positivo N e
retorne o ponteiro para um vetor de tamanho N, alocado dinamicamente, dessa estrutura.
Solicite também que o usuário digite os dados desse vetor dentro da função.*/

#include <stdio.h>
#include <stdlib.h>

struct Cadastro{
    char nome[50];
    int idade;
    char endereco[50];
};

struct Cadastro* criarCadastro(int N){
    struct Cadastro *vetor = malloc(N * sizeof(struct Cadastro));

    if (vetor == NULL){
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    for (int i = 0; i < N; i++){
        printf("\n--- Pessoa %d ---\n", i+1);

        printf("Nome: ");
        getchar(); 
        fgets(vetor[i].nome, 50, stdin);

        printf("Idade: ");
        scanf("%d", &vetor[i].idade);
        getchar(); 

        printf("Endereco: ");
        fgets(vetor[i].endereco, 50, stdin);
    }

    return vetor;
}

int main(){
    int N;

    printf("Quantas pessoas deseja cadastrar? \n");
    scanf("%d", &N);

    struct Cadastro *pessoas = criarCadastro(N);

    printf("\n--- Dados cadastrados ---\n");
    for (int i = 0; i < N; i++){
        printf("\nPessoa %d:\n", i+1);
        printf("Nome: %s", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Endereco: %s", pessoas[i].endereco);
    }
    free(pessoas);  
    return 0;
}
