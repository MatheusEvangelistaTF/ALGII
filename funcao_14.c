/*14 - Faça uma função que leia um número não determinado de valores
positivos e retorna a média aritmética dos mesmos. */

#include <stdio.h>

float calcularMediaPositivos(){
    float soma = 0;
    int contador = 0;
    float numero;

    printf("Digite os numeros positivos. Digite 0 para finalizar:\n");

    do{
        scanf("%f", &numero);

        if (numero > 0){
            soma += numero;
            contador++;
        } else if (numero < 0){
            printf("Apenas numeros positivos sao aceitos. Tente novamente.\n");
        }
    } while (numero != 0);

    if (contador == 0){
        return 0;
    }

    return soma / contador;
}

int main(){
    float media = calcularMediaPositivos();

printf("A media dos numeros positivos e: %.2f\n", media);

    return 0;
}

