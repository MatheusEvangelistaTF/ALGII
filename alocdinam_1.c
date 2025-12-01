/*Escreva um programa que mostre o tamanho em byte que cada tipo de dados ocupa na
memória: char, int, float, double.*/

#include <stdio.h>
#include <stdlib.h>

struct Tamanho{
int a;
double b;
float c;
char d;
};

int main(){
    printf("Tamanho de char: %zu byte\n", sizeof(char));
    printf("Tamanho de int: %zu byte\n", sizeof(int));
    printf("Tamanho de float: %zu byte\n", sizeof(float));
    printf("Tamanho de double: %zu byte\n", sizeof(double));


    return 0;
}
