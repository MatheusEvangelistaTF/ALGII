/*1) Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e
exiba o maior endereço.*/

#include <stdio.h>

int main(){
int variavel1;
int variavel2;
int *pa;
int *pa2;
pa = &variavel1;
pa2 = &variavel2;

printf("\n Insira 2 valores inteiros \n");
scanf("\n %d", &variavel1);
scanf("\n %d", &variavel2);

    if(pa > pa2){
        printf("\n O PA é maior %p", pa);
    }
    else{
        printf("\n O PA2 é maior %p", pa2);
    }
 
    return 0;
}