#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

/**
 * Imprime o cabecalho da area do admin
*/
void cabecalhoAreaAdmin() {
	LIMPA_TELA;
	printf(LINHAS);
	printf("                AREA ADMIN\n");
	printf(LINHAS);
}

/**
 * Imprime o cabecalho da area do funcionario
*/
void cabecalhoAreaFuncionario() {
    LIMPA_TELA;
    printf(LINHAS);
    printf("                AREA DO FUNCIONARIO\n");
    printf(LINHAS);
}

/**
 * Imprime o cabecalho da area da empresa
*/
void cabecalhoAreaEmpresa() {
    LIMPA_TELA;
    printf(LINHAS);
    printf("                AREA DA EMPRESA\n");
    printf(LINHAS);
}

/**
 * Imprime o cabecalho da area da empresa com o seu respectivo nome
 *
 * @param nomeEmpresa Nome da empresa
*/
void cabecalhoEmpresa(char nomeEmpresa[]) {
    LIMPA_TELA; 
    printf(LINHAS);
    printf("                EMPRESA %s\n", nomeEmpresa);
    printf(LINHAS);
}

/**
 * Imprime o cabecalho da area do funcionario com o seu respectivo nome
 *
 * @param nomeFuncio Nome do funcionario
*/
void cabecalhoFuncio(char nomeFuncio[]) {
    LIMPA_TELA;
    printf(LINHAS);
    printf("                FUNCIONARIO %s\n", nomeFuncio);
    printf(LINHAS);
}

/**
 * Printa todas as informacoes de um funcionario.
 *
 * @param funcionario Funcionario a ser printado
*/
void printInfosFuncio(Funcionario funcionario) {
    printf("ID: %d\n", funcionario.id);
    printf("Empresa: %s\n", funcionario.empresa->nome);
    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: R$%.2lf\n", funcionario.salario);
    printf("Comissao: %.2lf\n", funcionario.comissao);
	printf("Usuario: %s\n", funcionario.usuario.login);
	printf("Senha: %s\n", funcionario.usuario.senha);
    printf(LINHAS);
}
