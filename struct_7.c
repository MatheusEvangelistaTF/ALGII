/*7) Crie uma estrutura representando uma hora. Essa estrutura deve conter os campos hora,
minuto e segundo. Agora, escreva um programa que leia um vetor de cinco posições dessa
estrutura e imprima a maior hora.*/

#include <stdio.h>

struct Hora{
    int hora;
    int minuto;
    int segundo;
};

int main(){
    struct Hora vetorHoras[5];

    printf("Digite 5 horarios (HH MM SS):\n");
    for (int i = 0; i < 5; i++){
        scanf("%d %d %d", &vetorHoras[i].hora, &vetorHoras[i].minuto, &vetorHoras[i].segundo);
    }

    int maiorHora = 0; 
    for (int i = 1; i < 5; i++){
        if (vetorHoras[i].hora > vetorHoras[maiorHora].hora){
            maiorHora = i;
        } else if (vetorHoras[i].hora == vetorHoras[maiorHora].hora){
            if (vetorHoras[i].minuto > vetorHoras[maiorHora].minuto){
                maiorHora = i;
            } else if (vetorHoras[i].minuto == vetorHoras[maiorHora].minuto){
                if (vetorHoras[i].segundo > vetorHoras[maiorHora].segundo){
                    maiorHora = i;
                }
            }
        }
    }

    printf("\n A maior hora e: %d:%d:%d\n", vetorHoras[maiorHora].hora, vetorHoras[maiorHora].minuto, vetorHoras[maiorHora].segundo);

    return 0;
}
