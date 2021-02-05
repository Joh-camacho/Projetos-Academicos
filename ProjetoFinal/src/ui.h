#ifndef _UI_H_
#define _UI_H_

#include "funcionario.h"

#define OPCAO_LISTAR_EMPRESAS 2

#define OPCAO_AREA_ADMIN 1
#define OPCAO_AREA_FUNCIO 2
#define OPCAO_AREA_EMPRESA 3

#define OPCAO_LOGIN_EMPRESA 1
#define OPCAO_CADASTRAR_EMPRESA 2

#define OPCAO_LISTAR_FUNCIO 1
#define OPCAO_CONTRATAR_FUNCIO 2
#define OPCAO_DEMITIR_FUNCIO 3
#define OPCAO_ATUALIZAR_FUNCIO 4

#define OPCAO_SAIDA 0

#define LIMPA_TELA system("clear||cls")

#define LINHAS "----------------------------------------------\n"

void cabecalhoAreaAdmin();
void cabecalhoAreaFuncionario();
void cabecalhoAreaEmpresa();
void cabecalhoEmpresa(char nomeEmpresa[]);
void cabecalhoFuncio(char nomeFuncio[]);
void printInfosFuncio(Funcionario funcionario);

#endif
