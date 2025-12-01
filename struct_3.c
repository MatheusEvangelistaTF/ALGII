/*3) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles*/

#include <stdio.h>

struct Coordenadas{
    int xa;
    int ya;
};

int main(){
    int xb, yb;
    int pa, pb;
    struct Coordenadas ponto;
    int xa;
    int ya;
    
    printf("Insira as coordenadas Xa e Ya \n");
    scanf("%d", &xa);
    scanf("%d", &ya);
    printf("Insira as coordenadas Xb e Yb \n");
    scanf("%d", &xb);
    scanf("%d", &yb);

    pa=xb-xa;
    pb=yb-ya;
    printf("A distancia entre os dois pontos e: (%d,%d)\n", pa,pb);

    return 0;
}