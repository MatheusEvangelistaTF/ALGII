/*9 - Faça uma função que recebe um valor inteiro e verifica se o valor é
positivo ou negativo. A função deve retornar um valor inteiro. */

#include <stdio.h>

void funcao(int valor){
    if (valor >= 0){
     printf("Numero positivo \n"); 
    }
    else{
     printf("Numero negativo \n");
    }
}



int main(){
    int valor;
    
    printf("Insira um valor inteiro \n");
    scanf("%d", &valor);
    funcao(valor);

    return 0;
}