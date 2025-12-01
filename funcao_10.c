/*10 - Faça uma função que recebe um valor inteiro e verifica se o valor é par
ou ímpar. A função deve retornar um valor inteiro*/

#include <stdio.h>

void funcao(int valor){
    if (valor %2 == 0){
     printf("Numero par \n"); 
    }
    else{
     printf("Numero impar \n");
    }
}



int main(){
    int valor;
    
    printf("Insira um valor inteiro \n");
    scanf("%d", &valor);
    
    funcao(valor);

    return 0;
}