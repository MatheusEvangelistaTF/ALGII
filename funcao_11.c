/*11 - Faça uma função que recebe a média final de um aluno por parâmetro e
retorna o seu conceito, conforme a tabela abaixo*/

#include <stdio.h>
void funcao(float media){
    if(media <= 4.9){
       printf("Conceito D \n");
    }
    else if(media <= 6.9){
        printf("Conceito C \n");
    }
    else if(media <= 8.9) {
        printf("Conceito B \n");
    }
    else{
        printf("Conceito A \n");
    }
}

int main(){
    float media;
    
    printf("Qual a sua media final \n");
    scanf("%f", &media);
    
    funcao(media);
    
    return 0;
}