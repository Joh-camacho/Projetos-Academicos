#include <stdio.h>
#include <stdlib.h>

#define MAXL 4
#define MAXC 8

void menu(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]);
void disponiveis(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]);
void reservar(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]);

int main() {
	int poltronas[MAXL][MAXC], reservadas[MAXL * MAXC], i, j;

	for (i = 0; i < MAXL; i++) { // Linha
		for (j = 0; j < MAXC; j++) { // Coluna
            poltronas[i][j] = (4 - i) + (4 * j);

            reservadas[poltronas[i][j] - 1] = 0;
		}
	}

	menu(poltronas, reservadas);

	return 0;
}

void menu(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]) {
	int opcao;

	system("cls||clear");
	printf("Menu:\n");
	printf("1 - Poltronas disponíveis\n");
	printf("2 - Reservar poltrona\n");
	printf("0 - Sair\n\n");

	printf("Digite a opção: ");
	scanf("%d", &opcao);
	getchar();

	switch (opcao) {
	case 1:
		disponiveis(poltronas, reservadas);
		break;
	case 2:
		reservar(poltronas, reservadas);
		break;
	case 0:
		break;
	default:
		menu(poltronas, reservadas);
		break;
	}
}

void disponiveis(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]) {
	int i, j;

    system("cls||clear");
    printf("Poltronas disponíveis: \n\n");

	for (i = 0; i < MAXL; i++) {
		for (j = 0; j < MAXC; j++) {
			if (reservadas[poltronas[i][j] - 1]) {
				printf("x  ");
			} else {
				printf("%d  ", poltronas[i][j]);
			}
		}

		printf("\n");
	}

    printf("\nPara continuar aperte qualquer tecla.");
	getchar();

	menu(poltronas, reservadas);
}

void reservar(int poltronas[MAXL][MAXC], int reservadas[MAXL * MAXC]) {
	int poltrona, validacao;

    system("cls||clear");
    printf("Reserve sua poltrona \n\n");

	do {
		printf("Digite a poltrona que deseja: ");
		scanf("%d", &poltrona);
		getchar();

		validacao = poltrona <= 32 && poltrona >= 1;

		if (!validacao) {
			printf("Escolha a poltrona de 1 a 32.\n\n");
		} else if (reservadas[poltrona - 1] == 1) {
			printf("Poltrona já reservada.\n\n");
			validacao = 0;
		}
	} while (!validacao);

	printf("\nPoltrona %d reservada com sucesso.", poltrona);
    printf("\nPara continuar aperte qualquer tecla.");
	getchar();

	reservadas[poltrona - 1] = 1;

	menu(poltronas, reservadas);
}
