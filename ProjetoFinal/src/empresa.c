#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "main.h"
#include "ui.h"

/**
 * Cadastra uma empresa no banco de dados.
 * E necessario informar o nome da empresa, usuario e a senha para efetuar o login.
 *
 * @param empresas Ponteiro do vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
*/
void cadastrarEmpresa(Empresa **empresas, int *qtdEmpresas) {
    FILE *fileEmpresas = carregarFile("empresas.txt");
    char nome[50], usuario[50], senha[50];
    int i;

    cabecalhoAreaEmpresa();
    printf("Digite o nome da empresa: ");
    leString(nome, 50);
    printf("Digite o usuario: ");
    leString(usuario, 50);
    printf("Digite a senha: ");
    leString(senha, 50);
    printf(LINHAS);

    for (i = 0; i < *qtdEmpresas; i++) {
    	if (strcmp(nome, (*empresas)[i].nome) == 0) {
    	    printf("Nome da empresa ja existente! Tente novamente.");
    	    getchar();

    	    return;
    	}
        if (strcmp(usuario, (*empresas)[i].usuario.login) == 0) {
            printf("Usuario ja existente! Tente novamente.");
            getchar();
            return;
        }
    }

    *empresas = realloc(*empresas, (*qtdEmpresas + 1) * sizeof(Empresa));

    if (*empresas == NULL) {
    	printf("Nao foi possivel alocar memoria.");
    	exit(EXIT_FAILURE);
    }

    if (*qtdEmpresas > 0) {
    	(*empresas)[*qtdEmpresas].id = (*empresas)[*qtdEmpresas - 1].id + 1;
    } else {
    	(*empresas)[*qtdEmpresas].id = *qtdEmpresas;
    }

    strcpy((*empresas)[*qtdEmpresas].nome, nome);
    strcpy((*empresas)[*qtdEmpresas].usuario.login, usuario);
    strcpy((*empresas)[*qtdEmpresas].usuario.senha, senha);

	fseek(fileEmpresas, 0, SEEK_END);
	fprintf(fileEmpresas, FORMAT_PRINT_EMPRESA, (*empresas)[*qtdEmpresas].id,
			(*empresas)[*qtdEmpresas].nome,
			(*empresas)[*qtdEmpresas].usuario.login,
			(*empresas)[*qtdEmpresas].usuario.senha);
	fclose(fileEmpresas);

    *qtdEmpresas += 1;

    printf("Empresa %s cadastrada com sucesso.", nome);
    getchar();
}

/**
 * Printa na tela as seguintes informacoes da empresa:
 * ID, nome da empresa, usuario e senha para login.
 *
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
*/
void listarEmpresas(Empresa empresas[], int qtdEmpresas) {
    int i;

    cabecalhoAreaEmpresa();

    for (i = 0; i < qtdEmpresas; i++) {
        printf("ID: %d\n", empresas[i].id);
        printf("Nome: %s\n", empresas[i].nome);
        printf("Usuario: %s\n", empresas[i].usuario.login);
        printf("Senha: %s\n", empresas[i].usuario.senha);
        printf(LINHAS);
    }

    printf("Aperte ENTER para voltar.");
    getchar();
}

/**
 * Busca uma empresa cadastrada atraves de seu ID.
 *
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
 * @param idEmpresa ID da empresa que deseja procurar.
 * @return Ponteiro da empresa buscada ou NULL caso a empresa n�o seja encontrada.
*/
Empresa *getEmpresa(Empresa empresas[], int qtdEmpresas, int idEmpresa) {
    int i;

    for (i = 0; i < qtdEmpresas; i++) {
        if (empresas[i].id == idEmpresa) {
            return &empresas[i];
        }
    }

    return NULL;
}

/**
 * Efetua o login da empresa para ser redirecionado a area da empresa.
 *
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
 * @return Ponteiro da empresa que efetuou o login ou NULL caso usuario ou senha esteja incorreta.
*/
Empresa *loginEmpresa(Empresa empresas[], int qtdEmpresas) {
    char usuario[50], senha[50];
    int i;

    cabecalhoAreaEmpresa();
    printf("Digite o usuario: ");
    leString(usuario, 50);
    printf("Digite a senha: ");
    leString(senha, 50);
    printf(LINHAS);

    for (i = 0; i < qtdEmpresas; i++) {
        if (strcmp(usuario, empresas[i].usuario.login) == 0 && strcmp(senha, empresas[i].usuario.senha) == 0) {
            printf("Logado com sucesso!");
            getchar();

            return &empresas[i];
        }
    }

    printf("Empresa inexistente. Tente novamente.");
    getchar();

    return NULL;
}

/**
 * Carrega as empresas cadastradas atraves do arquivo "empresas.txt".
 *
 * @param empresas Ponteiro do vetor de empresas.
 * @return Quantidade de empresas cadastradas.
*/
int carregarEmpresas(Empresa **empresas) {
    FILE *fileEmpresas = carregarFile("empresas.txt");
    int qtd = 0;

    if (fgetc(fileEmpresas) == EOF) {
        fclose(fileEmpresas);
        return qtd;
    }

    fseek(fileEmpresas, 0, SEEK_SET);

    while (!feof(fileEmpresas)) {
        *empresas = realloc(*empresas, (qtd + 1) * sizeof(Empresa));

        if (*empresas == NULL) {
        	printf("Nao foi possivel alocar memoria.");
        	exit(EXIT_FAILURE);
        }

		fscanf(fileEmpresas, FORMAT_SCAN_EMPRESA, &(*empresas)[qtd].id,
				(*empresas)[qtd].nome, (*empresas)[qtd].usuario.login,
				(*empresas)[qtd].usuario.senha);

        qtd++;
    }

    fclose(fileEmpresas);

    return qtd;
}
