/*12 - Faça um procedimento que recebe 3 valores inteiros por parâmetro e
imprima-os ordenados em ordem crescente.*/

#include <stdio.h>

void ordenar_e_imprimir(int a, int b, int c){
    int temp;

    if (a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c){
        temp = b;
        b = c;
        c = temp;
    }
    
    printf("Os valores em ordem crescente sao: %d, %d, %d\n", a, b, c);
}

int main(){
    int num1, num2, num3;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    printf("Digite o terceiro número: ");
    scanf("%d", &num3);

    ordenar_e_imprimir(num1, num2, num3);

    return 0;
}
