/* 4 - Faça um procedimento que recebe por parâmetro os valores necessário
para o cálculo da fórmula de báskara e imprima as suas raízes, caso seja
possível calcular */

#include <stdio.h>
#include <math.h>

int chamarBhaskara(int valor){
    double x, a, b, c, delta;
    printf("Valor de a \n");
    scanf("%lf", &a);
    printf("Valor de b \n");
    scanf("%lf", &b);
    printf("Valor de c \n");
    scanf("%lf", &c);

    delta = b*b - 4*a*c;

    x = -b + sqrt(delta) / 2*a;
    printf("Valor de x %lf \n", x);
    x = -b - sqrt(delta) / 2*a;
    printf("Valor de x %lf \n", x);
    
    return 0;
}

int main(){
    int valor;
    chamarBhaskara(valor);

    return 0;
}
