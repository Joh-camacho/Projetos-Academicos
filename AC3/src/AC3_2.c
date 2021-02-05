#include <stdio.h>
#include <stdlib.h>

#define MAXL 3
#define MAXC 10

int main() {
	int comportamento[MAXL][MAXC], merecimento[MAXC], receberao = 0, validacao, i, j;

	for (i = 0; i < MAXC; i++) {
		system("clear||cls");
		printf("Dados da %d° criança:\n\n", i + 1);

		for (j = 0; j < MAXL; j++) {
			switch (j) {
			case 0:
				do {
					printf("Digite a idade: ");
					scanf("%d", &comportamento[j][i]);

					if (comportamento[j][i] < 0) {
						printf("Idade não pode ser negativa.\n\n");
					}
				} while (comportamento[j][i] < 0);

				if (comportamento[j][i] < 12) {
					merecimento[i] = 1;
				} else {
					merecimento[i] = 0;
				}
				break;
			case 1:
				do {
					printf("Digite a nota: ");
					scanf("%d", &comportamento[j][i]);

					validacao = comportamento[j][i] <= 10 && comportamento[j][i] >= 0;

					if (!validacao) {
						printf("Digite a nota de 0 a 10.\n\n");
					}
				} while (!validacao);

				if (comportamento[j][i] < 8) {
					merecimento[i] = 0;
				}
				break;
			case 2:
				do {
					printf("Digite o rendimento: ");
					scanf("%d", &comportamento[j][i]);
					getchar();

					validacao = comportamento[j][i] <= 10 && comportamento[j][i] >= 0;

					if (!validacao) {
						printf("Digite o rendimento de 0 a 10.\n\n");
					}
				} while (!validacao);

				if (comportamento[j][i] < 6) {
					merecimento[i] = 0;
				}
				break;
			}
		}

		printf("Aperte qualquer tecla para continuar.");
		getchar();
	}

	for (i = 0; i < MAXC; i++) {
		system("clear||cls");
		printf("Dados da %d° criança:\n\n", i + 1);

		for (j = 0; j < MAXL; j++) {
			switch (j) {
			case 0:
				printf("Idade: %d\n", comportamento[j][i]);
				break;
			case 1:
				printf("Comportamento: %d\n", comportamento[j][i]);
				break;
			case 2:
				printf("Rendimento: %d\n", comportamento[j][i]);
				break;
			}
		}

		if (merecimento[i] == 1) {
			receberao++;
			printf("Receberá o presente.\n\n");
		} else {
			printf("Não receberá o presente.\n\n");
		}

		printf("Aperte qualquer tecla para continuar.");
		getchar();
	}

	system("clear||cls");
	printf("%d criança(s) receberá(ão) os presentes.\n\n", receberao);

	return 0;
}
