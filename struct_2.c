/*2) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a origem
das coordenadas, isto é, a posição (0,0).*/

#include <stdio.h>
struct Coordenadas{
    int x;
    int y;
};

int main(){
    struct Coordenadas ponto;
    int x;
    int y;
    
    printf("Insira a coordenada x \n");
    scanf("%d", &x);
    printf("Insira a coordenada y \n");
    scanf("%d", &y);
    printf("A distância do ponto até a origem é (%d,%d)", x, y);

    return 0;
}