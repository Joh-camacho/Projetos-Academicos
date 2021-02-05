#include <stdio.h>

#define TAMANHO 6

int main() {
	float matriz[TAMANHO][TAMANHO], sl[TAMANHO], sc[TAMANHO];
	int i, j;

	for (i = 0; i < TAMANHO; i++) {
		sl[i] = 0;
		sc[i] = 0;
	}

	for (i = 0; i < TAMANHO; i++) { // Linha
		for (j = 0; j < TAMANHO; j++) { // Coluna
			printf("[%d, %d] Digite o número: ", i, j);
			scanf("%f", &matriz[i][j]);

			sl[i] += matriz[i][j];
			sc[j] += matriz[i][j];
		}
	}

	printf("\n");

	for (i = 0; i < TAMANHO; i++) {
		printf("    %d  ", i);
	}

	printf("\n");

	for (i = 0; i < TAMANHO; i++) {
		printf("%d", i);

		for (j = 0; j < TAMANHO; j++) {
			printf("  %.2f ", matriz[i][j]);
		}

		printf("= %.2f", sl[i]);
		printf("\n");
	}

	printf("\n");

	for (i = 0; i < TAMANHO; i++) {
		printf("   %.2f", sc[i]);
	}

	return 0;
}
