/*5- Crie um programa que contenha um array de inteiros com cinco elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor
lido.*/

#include <stdio.h>

int main(){
int array[5];
int *pa = array;
int i;

for(i=0; i<5; i++){
    scanf("\n %d", (pa+i));

    }

for(i=0; i<5; i++){
    printf("%d: %d \n", *(pa + i), (*(pa + i))*2);
    }
    return 0;
}