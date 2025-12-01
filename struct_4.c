/*4) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto superior 
esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido por uma estrutura 
Ponto, a qual contém as posições X e Y. Faça um programa que declare e leia uma 
estrutura Retângulo e exiba a área e o comprimento da diagonal e o perímetro desse 
retângulo.*/

#include <stdio.h>
#include <math.h>

struct Ponto{
    float x;
    float y;
};

struct Retangulo{
    struct Ponto sup_esq;
    struct Ponto inf_dir;
};

int main(){
    struct Retangulo r;
    float largura, altura, area, perimetro, diagonal;

    printf("Insira as coordenadas do ponto superior esquerdo \n");
    scanf("%f %f", &r.sup_esq.x, &r.sup_esq.y);
    printf("Insira as coordenadas do ponto inferior direito \n");
    scanf("%f %f", &r.inf_dir.x, &r.inf_dir.y);

    largura = r.inf_dir.x - r.sup_esq.x;
    altura = r.sup_esq.y - r.inf_dir.y;
    area = largura * altura;
    perimetro = 2 * (largura + altura);
    diagonal = sqrt(largura * largura + altura * altura);

    printf("Área: %.2f\n", area);
    printf("Perímetro: %.2f\n", perimetro);
    printf("Diagonal: %.2f\n", diagonal);
    
    return 0;
}



