#include <stdio.h>

#define TAMANHO 20

int main() {
	double vet1[TAMANHO], vet2[TAMANHO];
	int i;

	for (i = 0; i < TAMANHO; i++) {
		printf("Digite o número: ");
		scanf("%lf", &vet1[i]);
	}

	for (i = 0; i < TAMANHO; i++) {
		if (i % 2 == 0) {
            vet2[i] = vet1[i] / 2;
		} else {
            vet2[i] = vet1[i] * 3;
		}
	}

	printf("\nConjunto do vetor 1: \n");
	for (i = 0; i < TAMANHO; i++) {
		printf("%d: %lf\n", i, vet1[i]);
	}

	printf("\nConjunto do vetor 2: \n");
	for (i = 0; i < TAMANHO; i++) {
		printf("%d: %lf\n", i, vet2[i]);
	}

	return 0;
}
