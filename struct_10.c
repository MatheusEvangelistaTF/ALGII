/*10) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os
dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.*/

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

int verificado[5] = {0};
struct Atleta atletas[5];

void ImprimirAtletas(){
    for(int i = 0; i < 5; i++){
        int menor = -1;
        for(int j = 0; j < 5; j++){
            if(verificado[j] == 0){
                if(menor == -1 || atletas[j].idade > atletas[menor].idade){
                    menor = j;
                }
            }
        }
        verificado[menor] = 1;
        printf("%d ", atletas[menor].idade);
    }
}

int main(){

    int i;
    int idx_velho = 0;
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
    
    ImprimirAtletas();
    return 0;
}
