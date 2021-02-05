#include <stdio.h>

int main() {
	int i, n, numerador = 480, denominador = 10;
	double soma = 0;

	do {
		printf("Digite o número: ");
		scanf("%d", &n);

		if (n < 1) {
			printf("Digite somente valores positivo.\n\n");
		}
	} while(n < 1);

	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			soma += numerador / denominador;
		} else {
			soma -= numerador / denominador;
		}

		numerador -= 5;
		denominador += 1;
	}

	printf("Soma final: %.2lf", soma);

	return 0;
}
