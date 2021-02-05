#ifndef _MAIN_H_
#define _MAIN_H_

#include "funcionario.h"
#include "empresa.h"

void areaPrincipal(Funcionario **funcionarios, int *qtdFuncionarios, Empresa **empresas, int *qtdEmpresas);
void areaAdmin(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresas[], int qtdEmpresas);
void loginAdmin(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresas[], int qtdEmpresas);
void leInt(int *valor);
void leDouble(double *valor);
void leString(char string[], int tamanho);
FILE* carregarFile(char nomeArquivo[]);

#endif
