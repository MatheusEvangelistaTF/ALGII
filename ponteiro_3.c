/*3) Crie um programa que contenha um array de float com 10 elementos. Imprima o
endereço de cada posição desse array.*/

#include <stdio.h>

int main(){
    
float array[10];
void *pa;
pa = &array;

int i;
for(i=0; i<10; i++){
    printf("\n %p", pa+i);
    
    }
}