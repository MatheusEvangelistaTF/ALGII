/*9) Crie uma função que receba uma string e retorne o ponteiro para essa string invertida.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverterString(const char *str){
    int tamanho = strlen(str);
    char *invertida = malloc((tamanho + 1) * sizeof(char));

    if (invertida == NULL)
        return NULL;
    for (int i = 0; i < tamanho; i++){
        invertida[i] = str[tamanho - 1 - i];
    }

    invertida[tamanho] = '\0'; 
    return invertida;
}

int main(){
    char texto[100];

    printf("Digite uma string: \n");
    fgets(texto, 100, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    char *inv = inverterString(texto);

    if (inv != NULL){
        printf("String invertida: %s\n", inv);
        free(inv);
    }
    return 0;
}