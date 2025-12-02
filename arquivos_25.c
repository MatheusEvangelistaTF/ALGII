/*25 – Faça um programa para conceder um percentual de desconto dado pelo
usuário aos produtos cujos preços estão entre dois valores, também
fornecidos pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    int codigo;
    char descricao[50];
    float preco;
};

int main(){
    FILE *arq, *temp;
    struct Produto p;
    float v1, v2, desconto;
    int alterou = 0;

    arq = fopen("PRODUTOS.txt", "r");
    if (arq == NULL){
        printf("Arquivo nao encontrado.\n");
        return 1;
    }

    temp = fopen("TEMP.txt", "w");
    if (temp == NULL){
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arq);
        return 1;
    }

    printf("Digite o valor minimo: ");
    scanf("%f", &v1);

    printf("Digite o valor maximo: ");
    scanf("%f", &v2);

    printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
    scanf("%f", &desconto);

    desconto = desconto / 100.0; 

    while (fscanf(arq, "%d %s %f", &p.codigo, p.descricao, &p.preco) == 3){

        if (p.preco >= v1 && p.preco <= v2){
            p.preco = p.preco * (1 - desconto);
            alterou = 1;
        }

        fprintf(temp, "%d %s %.2f\n", p.codigo, p.descricao, p.preco);
    }

    fclose(arq);
    fclose(temp);

    remove("PRODUTOS.txt");
    rename("TEMP.txt", "PRODUTOS.txt");

    if (alterou)
        printf("Desconto aplicado com sucesso!\n");
    else
        printf("Nenhum produto na faixa informada.\n");

    return 0;
}
