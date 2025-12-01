/* 5 - Faça um procedimento que recebe por parâmetro o tempo de duração de
uma fábrica expressa em segundos e imprima esse tempo em horas, minutos
e segundos. */

#include <stdio.h>

void converterTempo(int totalSegundos){
    int horas = totalSegundos / 3600;
    int segundosRestantes = totalSegundos % 3600;
    int minutos = segundosRestantes / 60;
    int segundos = segundosRestantes % 60;
    printf("O tempo e: %d horas, %d minutos e %d\n segundos", horas, minutos, segundos);
}

int main(){
    int duracaoFabrica; 
    printf("Insira o tempo em segundos \n");
    scanf("%d", &duracaoFabrica);
    converterTempo(duracaoFabrica);
    return 0;
}