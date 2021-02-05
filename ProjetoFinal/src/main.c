#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"
#include "main.h"
#include "ui.h"

int main() {
    Empresa *empresas = NULL;
    Funcionario *funcionarios = NULL;
    int qtdEmpresas = 0, qtdFuncionarios = 0;

    qtdEmpresas = carregarEmpresas(&empresas);
    qtdFuncionarios = carregarFuncionarios(&funcionarios, empresas, qtdEmpresas);

    areaPrincipal(&funcionarios, &qtdFuncionarios, &empresas, &qtdEmpresas);
    return 0;
}

/**
 * Menu inicial do programa.
 * Redireciona o usuario para a area do admin, do funcionario ou da empresa.
 *
 * @param funcionarios Ponteiro do vetor de funcionarios contratados.
 * @param qtdFuncionarios Ponteiro da quantidade de funcionarios contratados.
 * @param empresas Ponteiro do vetor de empresas cadastradas.
 * @param qtdEmpresas Ponteiro da quantidade de empresas cadastradas.
*/
void areaPrincipal(Funcionario **funcionarios, int *qtdFuncionarios, Empresa **empresas, int *qtdEmpresas) {
	int opcao;

    do {
        LIMPA_TELA;
        printf(LINHAS);
        printf("         DEPARTAMENTO ADMINISTRATIVO\n");
        printf(LINHAS);
        printf("1) Area do admin\n");
        printf("2) Area do funcionario\n");
        printf("3) Area da empresa\n");
        printf("\n");
        printf("0) Sair\n");
        printf(LINHAS);
        printf("Digite a opcao desejada: ");
        leInt(&opcao);

        switch (opcao) {
            case OPCAO_AREA_ADMIN:
                areaAdmin(*funcionarios, *qtdFuncionarios, *empresas, *qtdEmpresas);
                break;
            case OPCAO_AREA_FUNCIO:
            	loginFuncionario(*funcionarios, *qtdFuncionarios);
                break;
            case OPCAO_AREA_EMPRESA:
                areaEmpresa(funcionarios, qtdFuncionarios, empresas, qtdEmpresas);
                break;
            case OPCAO_SAIDA:
                printf("Bye!\n");
                break;
            default:
            	printf("Opcao invalida! Escolha um numero entre 0 e 3.");
                getchar();
        }
    } while (opcao != OPCAO_SAIDA);
}

/**
 * Menu de login da area do admin.
 * Usuario: admin
 * Senha: admin
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
*/
void areaAdmin(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresas[], int qtdEmpresas) {
	char usuario[50], senha[50];

	cabecalhoAreaAdmin();
	printf("Digite o usuario: ");
	leString(usuario, 50);
	printf("Digite a senha: ");
	leString(senha, 50);
	printf(LINHAS);

	if (strcmp(usuario, "admin") == 0 && strcmp(senha, "admin") == 0) {
		printf("Logado com sucesso.");
		getchar();

		loginAdmin(funcionarios, qtdFuncionarios, empresas, qtdEmpresas);
	} else {
		printf("Login ou senha incorreta!");
		getchar();
	}
}

/**
 * Menu da area do admin.
 * Opcao 1 lista todos os funcionarios contratados.
 * Opcao 2 lista todas as empresas cadastradas.
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
*/
void loginAdmin(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresas[], int qtdEmpresas) {
	int i, opcao;

	do {
		cabecalhoAreaAdmin();
		printf("1) Listar funcionarios\n");
		printf("2) Listar empresas\n");
		printf("\n");
		printf("0) Voltar\n");
		printf(LINHAS);
		printf("Digite a opcao desejada: ");
		leInt(&opcao);

		switch (opcao) {
		case OPCAO_LISTAR_FUNCIO:
			cabecalhoAreaAdmin();
			for (i = 0; i < qtdFuncionarios; i++) {
				printInfosFuncio(funcionarios[i]);
            }

			printf("Aperte ENTER para voltar.");
			getchar();
			break;
		case OPCAO_LISTAR_EMPRESAS:
			listarEmpresas(empresas, qtdEmpresas);
			break;
        case OPCAO_SAIDA:
            printf("Bye!\n");
            break;
		default:
			printf("Opcao invalida! Escolha um numero entre 0 e 2.");
			getchar();
		}
	} while (opcao != OPCAO_SAIDA);
}

/**
 * Le um inteiro e valida se e positivo.
 *
 * @param valor Ponteiro do inteiro a ser atribuido.
*/
void leInt(int *valor) {
    do {
    	scanf("%d", valor);
    	getchar();

        if (*valor < 0) {
            printf("O valor nao pode ser negativo! Digite novamente...\n\n");
        }
    } while (*valor < 0);
}

/**
 * Le um double e valida se e positivo.
 *
 * @param valor Ponteiro do double a ser atribuido.
*/
void leDouble(double *valor) {
    do {
    	scanf("%lf", valor);
    	getchar();

        if (*valor < 0) {
            printf("O valor nao pode ser negativo! Digite novamente...\n\n");
        }
    } while (*valor < 0);
}

/**
 * Le uma string e valida se nao e vazio.
 *
 * @param string Vetor de char a ser atribuido.
 * @param tamanho Tamanho da string.
*/
void leString(char string[], int tamanho) {
	int last;

    do {
        fgets(string, tamanho, stdin);

        last = strlen(string) - 1;
        if (string[last] == '\n') {
        	string[last] = '\0';
        } else {
            getchar();
        }

        if (strlen(string) == 0) {
            printf("O valor nao pode ser vazio! Digite novamente...\n\n");
        }
    } while (strlen(string) == 0);
}

/**
 * Abre o arquivo, caso o arquivo nao exista ele e criado.
 *
 * @param nomeArquivo Nome do arquivo que deseja abrir/criar.
 * @return Ponteiro do arquivo.
*/
FILE *carregarFile(char nomeArquivo[]) {
    FILE *file = fopen(nomeArquivo, "r+");

    if (file == NULL)
    	file = fopen(nomeArquivo, "w+");

    return file;
}
