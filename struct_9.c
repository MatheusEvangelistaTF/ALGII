/*9) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do
atleta, seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco
atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.*/

#include <stdio.h>

struct Atleta{
    char nome[50];
    char esporte[10];
    int idade;
    float altura;
};

int mais_velho(struct Atleta a, struct Atleta b){
    return a.idade > b.idade;   
}

int mais_alto(struct Atleta a, struct Atleta b){
    return a.altura > b.altura;
}

int main(){
    struct Atleta atletas[5];
    int i;
    int idx_velho = 0, idx_alto = 0;

    printf("Digite nome, esporte, idade e altura para 5 atletas:\n");

    for (i = 0; i < 5; i++){
        printf("\nAtleta %d:\n", i + 1);

        printf("Nome: \n");
        scanf("%s", atletas[i].nome);

        printf("Esporte: \n");
        scanf("%s", atletas[i].esporte);

        printf("Idade: \n");
        scanf("%d", &atletas[i].idade);

        printf("Altura: \n");
        scanf("%f", &atletas[i].altura);
    }

    for (i = 1; i < 5; i++){

        if (mais_velho(atletas[i], atletas[idx_velho]))
            idx_velho = i;

        if (mais_alto(atletas[i], atletas[idx_alto]))
            idx_alto = i;
    }

    printf("Atleta mais velho: %s\n", atletas[idx_velho].nome);
    printf("Atleta mais alto: %s\n", atletas[idx_alto].nome);

    return 0;
}
