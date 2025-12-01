/*15 - Escreva uma função que recebe, por parâmetro, dois valores X e Z e
calcula e retorna Xz. (sem utilizar funções ou operadores de potência prontos)*/

#include <stdio.h>

int elevado(int x, int z){
    int resultado = 1;
    
    for (int i = 0; i < z; i++){ 
        resultado = resultado*x;
    }
    return resultado;
}

int main(){
    int x;
    int z;
    int resultado_final;
    printf("Insira um valor inteiro \n");
    scanf("%d", &x);
    
    printf("Insira quantas vezes x vai ser elevado \n");
    scanf("%d", &z);
    
    resultado_final = elevado(x,z);
    
    printf("%d elevado a %d e igual a %d \n", x, z, resultado_final);

    return 0;
}