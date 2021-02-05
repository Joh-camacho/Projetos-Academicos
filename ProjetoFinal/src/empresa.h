#ifndef _EMPRESA_H_
#define _EMPRESA_H_

#include "usuario.h"

//ID | NOME DA EMPRESA | USUARIO | SENHA
#define FORMAT_PRINT_EMPRESA "%d|%s|%s|%s\n"
#define FORMAT_SCAN_EMPRESA "%d|%[^|]|%[^|]|%[^\n]\n"

typedef struct Empresa {
    int id;
    char nome[50];
    Usuario usuario;
} Empresa;

void cadastrarEmpresa(Empresa **empresas, int *qtdEmpresas);
void listarEmpresas(Empresa empresas[], int qtdEmpresas);
Empresa *getEmpresa(Empresa empresas[], int qtdEmpresas, int idEmpresa);
Empresa *loginEmpresa(Empresa empresas[], int qtdEmpresas);
int carregarEmpresas(Empresa **empresas);

#endif
