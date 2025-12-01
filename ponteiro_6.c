/*6) Crie um programa que contenha um array com cinco elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares..*/

#include <stdio.h>

int main(){
int array[5];
int *pa = array;
int i;

for(i=0; i<5; i++){
    scanf("\n %d", (pa+i));
    }

for(i=0; i<5; i++){
        if(array[i] %2 == 0){
        printf("%p\n", (pa + i));
        }
    }
    return 0;
}