#include <stdio.h>
#include <stdlib.h>

void le_opcao(char text[], double *valor);

int main() {
    double precoAtual, precoReajustado, reajuste;

    le_opcao("Preço atual do produto: ", &precoAtual);
    le_opcao("Percentual de reajuste: ", &reajuste);

    precoReajustado = precoAtual * reajuste;

    system("clear||cls");
    printf("Valor original do produto: %.2lf\n", precoAtual);
    printf("Novo preço do produto: %.2lf\n", precoReajustado);
    printf("Percentual de reajuste: %.2lf%%\n", reajuste);

    return 0;
}

void le_opcao(char text[], double *valor) {
    do {
        printf("%s", text);
        scanf("%lf", valor);

        if (valor <= 0) {
            printf("O valor não pode ser menor ou igual a 0.");
        }
    } while (valor <= 0);
}
