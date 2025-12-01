/*2) Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do
teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço*/

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
        printf("\n O PA é maior %d", *pa);
    }
    else{
        printf("\n O PA2 é maior %d", *pa2);
    }
 
    return 0;
}