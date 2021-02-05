#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"
#include "empresa.h"
#include "main.h"
#include "ui.h"

/**
 * Menu da area da empresa.
 * Redireciona o usuario para o login ou cadastro de uma empresa.
 *
 * @param funcionarios Ponteiro do vetor de funcionarios contratados.
 * @param qtdFuncionarios Ponteiro da quantidade de funcionarios contratados.
 * @param empresas Ponteiro do vetor de empresas cadastradas.
 * @param qtdEmpresas Ponteiro da quantidade de empresas cadastradas.
*/
void areaEmpresa(Funcionario **funcionarios, int *qtdFuncionarios, Empresa **empresas, int *qtdEmpresas) {
	Empresa *empresa;
	int opcao;

	do {
	    cabecalhoAreaEmpresa();
	    printf("1) Login\n");
	    printf("2) Cadastrar empresa\n");
	    printf("\n");
	    printf("0) Voltar\n");
	    printf(LINHAS);
	    printf("Digite a opcao desejada: ");
		leInt(&opcao);

		switch (opcao) {
		case OPCAO_LOGIN_EMPRESA:
			empresa = loginEmpresa(*empresas, *qtdEmpresas);

			if (empresa != NULL)
				areaEmpresaLogin(funcionarios, qtdFuncionarios, empresa);
			break;
		case OPCAO_CADASTRAR_EMPRESA:
			cadastrarEmpresa(empresas, qtdEmpresas);
			break;
		case OPCAO_SAIDA:
			// printf("Bye!\n");
			break;
		default:
			printf("Opcao invalida! Escolha um numero entre 0 e 2.");
			getchar();
		}
	} while (opcao != OPCAO_SAIDA);
}

/**
 * Menu da area da empresa que efetuou o login.
 * Redireciona o usuario para listar os funcionarios de sua empresa,
 * contratar um novo funcionario, demitir um funcionario e
 * atualizar as informacoes de um funcionario.
 *
 * @param funcionarios Ponteiro do vetor de funcionarios contratados.
 * @param qtdFuncionarios Ponteiro da quantidade de funcionarios contratados.
 * @param empresa Ponteiro da empresa que efetuou o login.
*/
void areaEmpresaLogin(Funcionario **funcionarios, int *qtdFuncionarios, Empresa *empresa) {
	int opcao;

	do {
	    cabecalhoEmpresa(empresa->nome);
	    printf("1) Listar funcionarios\n");
	    printf("2) Contratar funcionario\n");
	    printf("3) Demitir funcionario\n");
	    printf("4) Atualizar funcionario\n");
	    printf("\n");
	    printf("0) Voltar\n");
	    printf(LINHAS);
	    printf("Digite a opcao desejada: ");
		leInt(&opcao);

		switch (opcao) {
		case OPCAO_LISTAR_FUNCIO:
			listarFuncionarios(*funcionarios, *qtdFuncionarios, *empresa);
			break;
		case OPCAO_CONTRATAR_FUNCIO:
			contratarFuncionario(funcionarios, qtdFuncionarios, empresa);
			break;
		case OPCAO_DEMITIR_FUNCIO:
			demitirFuncionario(funcionarios, qtdFuncionarios, *empresa);
			break;
		case OPCAO_ATUALIZAR_FUNCIO:
			atualizarFuncionario(*funcionarios, *qtdFuncionarios, *empresa);
			break;
		case OPCAO_SAIDA:
			// printf("Bye!\n");
			break;
		default:
			printf("Opcao invalida! Escolha um numero entre 0 e 4.");
			getchar();
		}
	} while (opcao != OPCAO_SAIDA);
}

/**
 * Printa na tela as informacoes de cada funcionario contratado,
 * quantidade de funcionarios contratados, salario total e o salario medio da empresa.
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @param empresa Empresa a ser printada.
*/
void listarFuncionarios(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresa) {
	double salarioTotal = 0.0, salarioMedio = 0.0;
	int i, qtd = 0;

	cabecalhoEmpresa(empresa.nome);

	for (i = 0; i < qtdFuncionarios; i++) {
		if (funcionarios[i].idEmpresa == empresa.id) {
			printInfosFuncio(funcionarios[i]);

			salarioTotal += funcionarios[i].salario;
			qtd++;
		}
	}

	if (qtd > 0)
		salarioMedio = (salarioTotal / qtd);

	printf("Funcionarios: %d\n", qtd);
	printf("Salario total: R$%.2lf\n", salarioTotal);
	printf("Salario medio: R$%.2lf\n", salarioMedio);
	printf(LINHAS);
	printf("Aperte ENTER para voltar.");

	getchar();
}

/**
 * Contrata um funcionario para a empresa.
 * E necessario informar o login, senha, nome, cargo, salario e comissao do funcionario.
 *
 * @param funcionarios Ponteiro do vetor de funcionarios contratados.
 * @param qtdFuncionarios Ponteiro da quantidade de funcionarios contratados.
 * @param empresa Ponteiro da empresa em que o funcionario esta sendo contratado.
*/
void contratarFuncionario(Funcionario **funcionarios, int *qtdFuncionarios, Empresa *empresa) {
	FILE *fileFuncionario = carregarFile("funcionarios.txt");
	char usuario[50], senha[50], nome[50], cargo[15];
	double salario, comissao;
	int i;

	cabecalhoEmpresa(empresa->nome);
	printf("Digite o login do funcionario: ");
	leString(usuario, 50);

	for (i = 0; i < *qtdFuncionarios; i++) {
		if (strcmp(usuario, (*funcionarios)[i].usuario.login) == 0 && (*funcionarios)[i].idEmpresa == empresa->id) {
			printf(LINHAS);
			printf("Login ja existente! Tente novamente...");
			getchar();
			return;
		}
	}

	printf("Digite a senha do funcionario: ");
	leString(senha, 50);
	printf("Digite o nome do funcionario: ");
	leString(nome, 50);
	printf("Digite o cargo: ");
	leString(cargo, 15);
	printf("Digite o salario: ");
	leDouble(&salario);
	printf("Digite a comissao: ");
	leDouble(&comissao);
	printf(LINHAS);

    *funcionarios = realloc(*funcionarios, (*qtdFuncionarios + 1) * sizeof(Funcionario));

    if (*funcionarios == NULL) {
		printf("Nao foi possivel alocar memoria.");
		exit(EXIT_FAILURE);
	}

    if (*qtdFuncionarios > 0) {
    	(*funcionarios)[*qtdFuncionarios].id = (*funcionarios)[*qtdFuncionarios - 1].id + 1;
    } else {
    	(*funcionarios)[*qtdFuncionarios].id = *qtdFuncionarios;
    }

	(*funcionarios)[*qtdFuncionarios].empresa = empresa;
	(*funcionarios)[*qtdFuncionarios].idEmpresa = empresa->id;

	(*funcionarios)[*qtdFuncionarios].salario = salario;
	(*funcionarios)[*qtdFuncionarios].comissao = comissao;

	strcpy((*funcionarios)[*qtdFuncionarios].nome, nome);
	strcpy((*funcionarios)[*qtdFuncionarios].cargo, cargo);
	strcpy((*funcionarios)[*qtdFuncionarios].usuario.login, usuario);
	strcpy((*funcionarios)[*qtdFuncionarios].usuario.senha, senha);

	fseek(fileFuncionario, 0, SEEK_END);
	fprintf(fileFuncionario, FORMAT_PRINT_FUNCIO,
			(*funcionarios)[*qtdFuncionarios].id,
			(*funcionarios)[*qtdFuncionarios].idEmpresa,
			(*funcionarios)[*qtdFuncionarios].nome,
			(*funcionarios)[*qtdFuncionarios].cargo,
			(*funcionarios)[*qtdFuncionarios].salario,
			(*funcionarios)[*qtdFuncionarios].comissao,
			(*funcionarios)[*qtdFuncionarios].usuario.login,
			(*funcionarios)[*qtdFuncionarios].usuario.senha);
	fclose(fileFuncionario);

	*qtdFuncionarios += 1;

	printf("Funcionario %s cadastrado com sucesso.", nome);
	getchar();
}

/**
 * Demite um funcionario da empresa.
 * E necessario informar o ID do funcionario.
 *
 * @param funcionarios Ponteiro do vetor de funcionarios contratados.
 * @param qtdFuncionarios Ponteiro da quantidade de funcionarios contratados.
 * @param empresa Empresa em que o funcionario esta contratado.
*/
void demitirFuncionario(Funcionario **funcionarios, int *qtdFuncionarios, Empresa empresa) {
	int i, j, idFuncionario;

	cabecalhoEmpresa(empresa.nome);
	printf("Digite o id do funcionario: ");
	leInt(&idFuncionario);
	printf(LINHAS);

	for (i = 0; i < *qtdFuncionarios; i++) {
		if ((*funcionarios)[i].empresa->id == empresa.id && (*funcionarios)[i].id == idFuncionario) {
			*qtdFuncionarios -= 1;

			// Copia o proximo elemento para o elemento atual.
			for (j = i; j < *qtdFuncionarios; j++) {
				(*funcionarios)[j] = (*funcionarios)[j + 1];
			}

			*funcionarios = realloc(*funcionarios, *qtdFuncionarios * sizeof(Funcionario));

		    if (*funcionarios == NULL) {
		    	printf("Nao foi possivel alocar memoria.");
		    	exit(EXIT_FAILURE);
		    }

		    salvarFuncionarios(*funcionarios, *qtdFuncionarios);

		    printf("Funcionario demitido com sucesso.");
		    getchar();
			return;
		}
	}

	printf("Funcionario inexistente.");
	getchar();
}

/**
 * Busca um funcionario que ira ser atualizado atraves do ID.
 * Caso o ID do funcionario exista, ira ser redirecionado para o menu de atualizar funcionario.
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @param empresa Empresa em que o funcionario esta contratado.
*/
void atualizarFuncionario(Funcionario funcionarios[], int qtdFuncionarios, Empresa empresa) {
	int i, idFuncionario;

	cabecalhoEmpresa(empresa.nome);
	printf("Digite o id do funcionario: ");
	leInt(&idFuncionario);
	printf(LINHAS);

	for (i = 0; i < qtdFuncionarios; i++) {
		if (funcionarios[i].empresa->id == empresa.id && funcionarios[i].id == idFuncionario) {
			menuAtualizarFuncio(funcionarios, qtdFuncionarios, &funcionarios[i]);
			return;
		}
	}

	printf("Funcionario inexistente.");
	getchar();
}

/**
 * Atualizar o cargo, salario ou comissao de um funcionario.
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @param funcionario Ponteiro do funcionario que ira ser atualizado.
*/
void menuAtualizarFuncio(Funcionario funcionarios[], int qtdFuncionarios, Funcionario *funcionario) {
	int opcao;

	do {
		cabecalhoEmpresa(funcionario->empresa->nome);
		printInfosFuncio(*funcionario);
		printf("1) Atualizar cargo\n");
		printf("2) Atualizar salario\n");
		printf("3) Atualizar comissao\n");
		printf("\n");
		printf("0) Voltar\n");
		printf(LINHAS);
		printf("Digite a opcao desejada: ");
		leInt(&opcao);

		switch (opcao) {
		case 1:
			cabecalhoEmpresa(funcionario->empresa->nome);
			printInfosFuncio(*funcionario);
			printf("Digite o novo cargo: ");
			leString(funcionario->cargo, 15);
			printf(LINHAS);
			printf("Cargo alterado com sucesso.");
			getchar();

			salvarFuncionarios(funcionarios, qtdFuncionarios);
			break;
		case 2:
			cabecalhoEmpresa(funcionario->empresa->nome);
			printInfosFuncio(*funcionario);
			printf("Digite o novo salario: ");
			leDouble(&funcionario->salario);
			printf(LINHAS);
			printf("Salario alterado com sucesso.");
			getchar();

			salvarFuncionarios(funcionarios, qtdFuncionarios);
			break;
		case 3:
			cabecalhoEmpresa(funcionario->empresa->nome);
			printInfosFuncio(*funcionario);
			printf("Digite a nova comissao: ");
			leDouble(&funcionario->comissao);
			printf(LINHAS);
			printf("Comissao alterada com sucesso.");
			getchar();

			salvarFuncionarios(funcionarios, qtdFuncionarios);
			break;
		case OPCAO_SAIDA:
			break;
		default:
			printf("Opcao invalida! Escolha um numero entre 0 e 3.");
			getchar();
		}
	} while (OPCAO_SAIDA != opcao);
}

/**
 * Efetua o login do funcionario e printa suas informacoes.
 * E necessario informar o nome da empresa, usuario e senha para efetuar o login.
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
 * @return Ponteiro do funcionario que efetuou o login ou
 * NULL caso o nome da empresa, usuario ou senha esteja incorreta.
*/
Funcionario *loginFuncionario(Funcionario funcionarios[], int qtdFuncionarios) {
	char empresa[50], usuario[50], senha[50];
	int i;

	cabecalhoAreaFuncionario();
	printf("Digite o nome da empresa: ");
	leString(empresa, 50);
	printf("Digite o usuario: ");
	leString(usuario, 50);
	printf("Digite a senha: ");
	leString(senha, 50);
	printf(LINHAS);

	for (i = 0; i < qtdFuncionarios; i++) {
		if (strcmp(empresa, funcionarios[i].empresa->nome) == 0
				&& strcmp(usuario, funcionarios[i].usuario.login) == 0
				&& strcmp(senha, funcionarios[i].usuario.senha) == 0) {
			printf("Logado com sucesso.");
			getchar();

		    cabecalhoFuncio(funcionarios[i].nome);
		    printInfosFuncio(funcionarios[i]);
		    printf("Aperte ENTER para voltar.");
		    getchar();

			return &funcionarios[i];
		}
	}

	printf("Usuario inexistente!");
	getchar();

	return NULL;
}

/**
 * Salva os funcionarios contratados no arquivo "funcionarios.txt".
 *
 * @param funcionarios Vetor de funcionarios contratados.
 * @param qtdFuncionarios Quantidade de funcionarios contratados.
*/
void salvarFuncionarios(Funcionario funcionarios[], int qtdFuncionarios) {
	FILE *fileFuncionarios = fopen("funcionarios.txt", "w");
	int i;

	for (i = 0; i < qtdFuncionarios; i++)
		fprintf(fileFuncionarios, FORMAT_PRINT_FUNCIO, funcionarios[i].id,
				funcionarios[i].idEmpresa, funcionarios[i].nome,
				funcionarios[i].cargo, funcionarios[i].salario,
				funcionarios[i].comissao, funcionarios[i].usuario.login,
				funcionarios[i].usuario.senha);

	fclose(fileFuncionarios);
}

/**
 * Carrega os funcionarios contratados atraves do arquivo "funcionarios.txt".
 *
 * @param funcionarios Ponteiro do vetor de funcionarios.
 * @param empresas Vetor de empresas cadastradas.
 * @param qtdEmpresas Quantidade de empresas cadastradas.
 * @return Quantidade de empresas cadastradas.
*/
int carregarFuncionarios(Funcionario **funcionarios, Empresa empresas[], int qtdEmpresas) {
	FILE *fileFuncionarios = carregarFile("funcionarios.txt");
	int qtd = 0;

	if (fgetc(fileFuncionarios) == EOF) {
		fclose(fileFuncionarios);
		return qtd;
	}

	fseek(fileFuncionarios, 0, SEEK_SET);

	while (!feof(fileFuncionarios)) {
		*funcionarios = realloc(*funcionarios, (qtd + 1) * sizeof(Funcionario));

		if (*funcionarios == NULL) {
			printf("Nao foi possivel alocar memoria.");
			exit(EXIT_FAILURE);
		}

		fscanf(fileFuncionarios, FORMAT_SCAN_FUNCIO, &(*funcionarios)[qtd].id,
				&(*funcionarios)[qtd].idEmpresa, (*funcionarios)[qtd].nome,
				(*funcionarios)[qtd].cargo, &(*funcionarios)[qtd].salario,
				&(*funcionarios)[qtd].comissao,
				(*funcionarios)[qtd].usuario.login,
				(*funcionarios)[qtd].usuario.senha);

		(*funcionarios)[qtd].empresa = getEmpresa(empresas, qtdEmpresas,
				(*funcionarios)[qtd].idEmpresa);

		qtd++;
	}

	fclose(fileFuncionarios);

	return qtd;
}
