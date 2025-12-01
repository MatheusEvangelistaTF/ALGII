/*6 - Faça uma função que recebe a idade de uma pessoa em anos, meses e dias
e retorna essa idade expressa em dias. */

#include <stdio.h>

int recebaIdade(int anos, int meses, int dias){
    int total;
    
    total = (meses * 30) + (anos * 365) + dias;
    return total;
}

int main(){
    int anos, meses, dias;
    
    printf("Quantos anos voce tem? \n");
    scanf("%d", &anos);
    printf("Quantos meses voce tem? \n");
    scanf("%d", &meses);
    printf("Quantos dias voce tem? \n");
    scanf("%d", &dias);
    
    int resultado = recebaIdade(anos, meses, dias);
    printf("A idade expressa em dias e %d \n", resultado);

    return 0;
}