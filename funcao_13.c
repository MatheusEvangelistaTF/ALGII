/*13 - Escreva um procedimento que recebes 3 valores reais X, Y e Z e que
verifique se esses valores podem ser os comprimentos dos lados de um
triângulo e, neste caso, retornar qual o tipo de triângulo formado. 
Para que
X, Y e Z formem um triângulo é necessário que a seguinte propriedade seja
satisfeita: 
o comprimento de cada lado de um triângulo é menor do que a
soma do comprimento dos outros dois lados. 
O procedimento deve
identificar o tipo de triângulo formado observando as seguintes definições: */

#include <stdio.h>

int procedimento(float X, float Y, float Z){
    
    if((X + Y < Z) || (Y + Z < X) || (X + Z < Y)){
    printf("Nao eh um triangulo \n");
    return 1;
    }
    else{
    printf("Eh um triangulo \n");
    }
    
    if((X == Y) && (X == Z) && (Y == Z)){
    printf("Triangulo Equilatero \n");        
    }
    else if((Y != Z) && (Z != X) && (X != Y)){
    printf("Triangulo Escaleno \n");
    }
    else{
    printf("Triangulo Isoceles \n");
    }

    return 0;
}

int main(){
    float X, Y, Z;
    
    printf("Insira X: \n");
    scanf("%f",&X);
    printf("Insira Y: \n");
    scanf("%f",&Y);
    printf("Insira Z: \n");
    scanf("%f",&Z);

    procedimento(X,Y,Z);
    return 0;
}