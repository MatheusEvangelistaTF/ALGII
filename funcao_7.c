/*7 - Faça uma função que verifique se um valor é perfeito ou não. Um valor
é dito perfeito quando ele é igual a soma dos seus divisores excetuando ele
próprio. (Ex: 6 é perfeito, 6 = 1 + 2 + 3, que são seus divisores). A função
deve retornar o valor inteiro 1 para verdadeiro e 0 caso contrário. */

#include <stdio.h>
int valorPerfeito(int num){
    int somador = 0;
    for(int i=1; i < num; i++){
    
        if(num % i == 0){
            
            somador += i;
        }
    }
   if(somador == num){
        return 1;
    }
    else{
        return 0;    
    }
}
int main(){
    int num;
    
    printf("Insira um valor \n");
    scanf("%d", &num);
    
    int resultado =  valorPerfeito(num);
    printf("%d", resultado);

        
}