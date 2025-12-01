/*5) Usando a estrutura Retângulo do exercício anterior, faça um programa que declare e 
leia uma estrutura Retângulo e um Ponto, e informe se esse ponto está ou não dentro do 
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

int PontoDentro(struct Retangulo r, struct Ponto p){
    if(p.x >= r.sup_esq.x && p.x <= r.inf_dir.x && p.y <= r.sup_esq.y && p.y >= r.inf_dir.y){
        return 1; 
    } else{
        return 0; 
    }
}

int main(){
    struct Retangulo r;
    struct Ponto p;

    printf("Insira as coordenadas do ponto superior esquerdo \n");
    scanf("%f %f", &r.sup_esq.x, &r.sup_esq.y);
    printf("Insira as coordenadas do ponto inferior direito \n");
    scanf("%f %f", &r.inf_dir.x, &r.inf_dir.y);
    printf("Insira as coordenadas do ponto a ser verificado \n");
    scanf("%f %f", &p.x, &p.y);

    if(PontoDentro(r, p)){
        printf("O ponto está dentro do retângulo.\n");
    } else {
        printf("O ponto está fora do retângulo.\n");
    }

    
    return 0;
}