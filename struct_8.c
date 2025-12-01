/*8) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa.
Agora, escreva um programa que leia os dados de seis pessoas. Calcule e exiba os nomes
da pessoa mais nova e da mais velha.*/

#include <stdio.h>

struct Pessoa{
    char nome[50];
    int dia;
    int mes;
    int ano;
};

int mais_velho(struct Pessoa a, struct Pessoa b){
    if (a.ano != b.ano) return a.ano < b.ano;
    if (a.mes != b.mes) return a.mes < b.mes;
    return a.dia < b.dia;
}

int mais_novo(struct Pessoa a, struct Pessoa b){
    if (a.ano != b.ano) return a.ano > b.ano;
    if (a.mes != b.mes) return a.mes > b.mes;
    return a.dia > b.dia;
}

int main(){
    struct Pessoa pessoas[6];
    int i;
    int idx_velho = 0, idx_novo = 0;


    printf("Digite nome e data de nascimento (dia mes ano) para 6 pessoas:\n");

    for (i = 0; i < 6; i++){
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", pessoas[i].nome);
        printf("Data (dia mes ano): \n");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
    }

    for (i = 1; i < 6; i++){
        if (mais_velho(pessoas[i], pessoas[idx_velho]))
            idx_velho = i;

        if (mais_novo(pessoas[i], pessoas[idx_novo]))
            idx_novo = i;
    }

    printf("\nPessoa mais velha: %s\n", pessoas[idx_velho].nome);
    printf("Pessoa mais nova: %s\n", pessoas[idx_novo].nome);

    return 0;
}
