#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_opcao(char text[], char opcao[], int max);

struct cadastro {
    char nome[51], endereco[101], nascimento[11], sexo[10];
    double salario;
    int rg;
};

int main() {
    struct cadastro cadastro;

    le_opcao("Digite o nome: " ,cadastro.nome, 51);
    le_opcao("Digite o endereço: ", cadastro.endereco, 101);
    le_opcao("Digite a data de nascimento: ", cadastro.nascimento, 11);
    le_opcao("Digite o sexo: ", cadastro.sexo, 10);

    do {
        printf("Digite o salário: ");
        scanf("%lf", &cadastro.salario);

        if (cadastro.salario < 0) {
            printf("O salário não pode ser menor que 0.\n\n");
        }
    } while(cadastro.salario < 0);

    do {
        printf("Digite o RG: ");
        scanf("%d", &cadastro.rg);

        if (cadastro.rg < 0) {
            printf("O RG não pode ser menor que 0.\n\n");
        }
    } while(cadastro.rg < 0);

    system("clear||cls");

    printf("Nome: %s\n", cadastro.nome);
    printf("Endereço: %s\n", cadastro.endereco);
    printf("Data de nascimento: %s\n", cadastro.nascimento);
    printf("Salario: %.2lf\n", cadastro.salario);
    printf("RG: %d\n", cadastro.rg);

    return 0;
}

void le_opcao(char text[], char opcao[], int max) {
    do {
        printf("%s", text);
        fgets(opcao, max, stdin);

        int last = strlen(opcao) - 1;
        if (opcao[last] == '\n') {
            opcao[last] = '\0';
        } else {
            getchar();
        }

        if (strlen(opcao) == 0) {
            printf("O item não pode ser vazio.\n\n");
        }
    } while(strlen(opcao) == 0);
}
