#ifndef _FUNCIONARIO_H_
#define _FUNCIONARIO_H_

#include "usuario.h"
#include "empresa.h"

// ID_FUNCIONARIO | ID_EMPRESA | NOME | CARGO | SALARIO | COMISSAO | USUARIO | SENHA
#define FORMAT_SCAN_FUNCIO "%d|%d|%[^|]|%[^|]|%lf|%lf|%[^|]|%[^\n]\n"
#define FORMAT_PRINT_FUNCIO "%d|%d|%s|%s|%.2lf|%.2lf|%s|%s\n"

typedef struct Funcionario {
    int id;
    int idEmpresa;
    char nome[50];
    char cargo[15];
    double salario;
    double comissao;
    Empresa *empresa;
    Usuario usuario;
} Funcionario;

void areaEmpresa(Funcionario **funcionarios, int *qtdFuncionarios, Empresa **empresas, int *qtdEmpresas);
void areaEmpresaLogin(Funcionario **funcionarios, int *qtdFuncionarios, Empresa *empresa);
void listarFuncionarios(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresa);
void contratarFuncionario(Funcionario **funcionarios, int *qtdFuncionarios, Empresa *empresa);
void demitirFuncionario(Funcionario **funcionarios, int *qtdFuncionarios, Empresa empresa);
void atualizarFuncionario(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresa);
void menuAtualizarFuncio(Funcionario funcionarios[], int qtdFuncionarios, Funcionario *funcionario);
Funcionario *loginFuncionario(Funcionario funcionarios[], int qtdFuncionarios);
void salvarFuncionarios(Funcionario funcionarios[], int qtdFuncionarios);
int carregarFuncionarios(Funcionario **funcionarios, Empresa empresas[], int qtdEmpresas);

#endif
