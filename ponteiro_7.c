/*7) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres
das strings.*/

#include <stdio.h>
#include <string.h>


int main(){
    char string[10], string2[10];
    char *pa = string;
    char *pa2 = string2;
    int ret;

    fgets(string, 10, stdin);
    fgets(string2, 10, stdin);

    ret = strncmp(pa, pa2, 10);
    if(ret < 0){
    printf("A segunda string nao ocorre dentro da primeira \n");
    }
    else if(ret > 0){
    printf("A segunda string ocorre dentro da primeira \n");  
    }
}