#include <stdio.h>

#define TAMANHO 10

int main() {
	double vet1[TAMANHO], vet2[TAMANHO], resultado[TAMANHO];
	int i;

	for (i = 0; i < TAMANHO; i++) {
		printf("Digite o %dº valor do primeiro vetor: ", i + 1);
		scanf("%lf", &vet1[i]);

		printf("Digite o %dº valor do segundo vetor: ", i + 1);
		scanf("%lf", &vet2[i]);

		resultado[i] = vet1[i] * vet2[i];

        printf("\n");
	}

	printf("Resultados das multiplicações: \n");
	for (i = 0; i < TAMANHO; i++) {
		printf("%dº: %.2lf\n", i + 1, resultado[i]);
	}

	return 0;
}
