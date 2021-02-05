#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIMPA_TELA system("clear||cls");

struct locatario {
    char nome[101];
    double valor;
    int codigo;
};

void menu(struct locatario locatarios[], int *counter);
void cadastro(struct locatario locatarios[], int *counter);
void pesquisa(struct locatario locatarios[], int *counter);
void valorTotal(struct locatario locatarios[], int *counter);

int main() {
    struct locatario locatarios[100];
    int counter = 0;

    menu(locatarios, &counter);

    return 0;
}

void menu(struct locatario locatarios[], int *counter) {
    int opcao;

    LIMPA_TELA;
    printf("Locatários com aluguel atrasado: \n\n");
    printf("1- Cadastrar locatário.\n");
    printf("2- Pesquisar locatário.\n");
    printf("3- Valor total dos locatários em atraso.\n");
    printf("0- Sair.\n\n");

    printf("Digite a opção: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            cadastro(locatarios, counter);
            break;
        case 2:
            pesquisa(locatarios, counter);
            break;
        case 3:
            valorTotal(locatarios, counter);
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Opção inválida.");
            getchar();

            menu(locatarios, counter);
            break;
    }
}

// A
void cadastro(struct locatario locatarios[], int *counter) {
    int i, validacao = 0;
    char continuar;

    LIMPA_TELA;
    printf("Cadastro de locatários: \n\n");

    do {
        printf("Nome do locatário: ");
        fgets(locatarios[*counter].nome, 101, stdin);

        int last = strlen(locatarios[*counter].nome) - 1;
        if (locatarios[*counter].nome[last] == '\n') {
            locatarios[*counter].nome[last] = '\0';
        } else {
            getchar();
        }

        validacao = strlen(locatarios[*counter].nome) > 0;

        if (!validacao) {
            printf("Nome do locatário não pode ser vazio.\n\n");
        }
    } while (!validacao);

    do {
        printf("Valor do aluguel: ");
        scanf("%lf", &locatarios[*counter].valor);
        getchar();

        validacao = locatarios[*counter].valor > 0;

        if (!validacao) {
            printf("Valor do aluguel não pode ser negativo.\n\n");
        }
    } while (!validacao);

    do {
        printf("Digite o código de registro: ");
        scanf("%d", &locatarios[*counter].codigo);
        getchar();

        validacao = locatarios[*counter].codigo > 0;

        if (validacao) {
            for (i = 0; i < *counter; i++) {
                if (locatarios[*counter].codigo == locatarios[i].codigo) {
                    printf("Código de registro já existente.\n\n");
                    validacao = 0;
                    break;
                }
            }
        } else {
            printf("Código de registro não pode ser negativo.\n\n");
        }
    } while (!validacao);

    *counter += 1;

    printf("\nPara incluir mais um cadastro digite 'S'.");
    continuar = toupper(getchar());
    getchar();

    if (continuar == 'S') {
        cadastro(locatarios, counter);
    } else {
        menu(locatarios, counter);
    }
}

// B
void pesquisa(struct locatario locatarios[], int *counter) {
    int i, codigoPesquisado, validacao = 0, encontrou = 0;
    char continuar;

    if (*counter == 0) {
        printf("\nNenhum cadastro foi incluido.\n");
        printf("Pressione <ENTER> para continuar...");
        getchar();

        menu(locatarios, counter);
    } else {
        LIMPA_TELA;

        do {
            printf("Digite o código de registro que deseja pesquisar: ");
            scanf("%d", &codigoPesquisado);
            getchar();

            validacao = codigoPesquisado > 0;

            if (validacao) {
                for (i = 0; i < *counter; i++) {
                    if (codigoPesquisado == locatarios[i].codigo) {
                        LIMPA_TELA;

                        printf("Código de registro encontrado:\n\n");
                        printf("Nome do locatário: %s\n", locatarios[i].nome);
                        printf("Valor do aluguel: %.2lf\n", locatarios[i].valor);
                        printf("Código de registro: %d\n", locatarios[i].codigo);

                        encontrou = 1;
                        break;
                    }
                }

                if (!encontrou) {
                    printf("Código de registro não encontrado.\n\n");
                }
            } else {
                printf("Código de registro não pode ser negativo.\n\n");
            }
        } while (!validacao || !encontrou);

        printf("\nPara fazer mais uma pesquisa digite 'S'.");
        continuar = toupper(getchar());
        getchar();

        if (continuar == 'S') {
            pesquisa(locatarios, counter);
        } else {
            menu(locatarios, counter);
        }
    }
}

// C
void valorTotal(struct locatario locatarios[], int *counter) {
    double valor = 0;
    int i;

    if (*counter == 0) {
        printf("\nNenhum cadastro foi incluido.\n");
        printf("Pressione <ENTER> para continuar...");
        getchar();

        menu(locatarios, counter);
    } else {
        for (i = 0; i < *counter; i++) {
            valor += locatarios[i].valor;
        }

        LIMPA_TELA;
        printf("Valor total dos locatários em atraso: %.2lf\n", valor);
        printf("Pressione <ENTER> para continuar...");
        getchar();

        menu(locatarios, counter);
    }
}
