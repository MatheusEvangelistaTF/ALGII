/*8 - Faça um procedimento que recebe a idade de um nadador por parâmetro
e retorna, também por parâmetro, a categoria desse nadador de acordo com
a tabela abaixo: */

#include <stdio.h>
void categoriaNadador(int idade){
    if(idade <= 4){
       printf("Muito jovem para entrar na natacao \n");
    }
    else if(idade <= 7){
        printf("Categoria Infantil A \n");
    }
    else if(idade <= 10){
        printf("Categoria Infantil B \n");
    }
    else if(idade <= 13){
        printf("Categoria Juvenil A \n");
    }
    else if(idade <= 17){
        printf("Categoria Juvenil B \n");
    }
    else{
        printf("Categoria Adulto \n"); 
    }
}

int main(){
    int idade;
    
    printf("Qual a sua idade \n");
    scanf("%d", &idade);
    
    categoriaNadador(idade);
    return 0;
}