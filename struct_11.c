/*11) Escreva um programa que contenha uma estrutura representando uma data válida.
Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia duas datas e
armazene nessa estrutura. Calcule e exiba o número de dias que decorreram entre as duas
datas.*/

#include <stdio.h>

struct Data{
    int dia;
    int mes;
    int ano;
};

int bissexto(int ano){
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

int dias_totais(struct Data d){
    int dias_por_mes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i, total = d.ano * 365 + d.dia;

    for (i = 1; i < d.mes; i++){
        total += dias_por_mes[i];
    }

    total += (d.ano / 4) - (d.ano / 100) + (d.ano / 400);

    if (bissexto(d.ano) && d.mes > 2)
        total++;

    return total;
}

int main(){
    struct Data d1, d2;
    int total1, total2, diferenca;

    printf("Digite a primeira data (dia mes ano): \n");
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);

    printf("Digite a segunda data (dia mes ano): \n");
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);

    total1 = dias_totais(d1);
    total2 = dias_totais(d2);

    diferenca = total1 - total2;
    if (diferenca < 0) diferenca = -diferenca;

    printf("Dias decorridos entre as duas datas: %d\n", diferenca);

    return 0;
}
