// 3 - Faça uma função que receba um texto por parâmetro e escreva-o na tela (print), em seguida retorne “Ok”

#include <stdio.h>

void parametro(char texto[10]){
    printf("O texto digitado foi: %s \n", texto);
    printf("Ok");
}

int main(){
    char texto[10];
    
    scanf("%s", &texto);
    parametro(texto);

    return 0;
}
