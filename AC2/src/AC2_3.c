#include <stdio.h>
#include <math.h>

int main() {
	double x, resultado;
	int n;

	do {
		printf("Digite o valor de X: ");
		scanf("%lf", &x);

		if (x < 0) {
			printf("Digite somente valores positivos\n\n");
		}
	} while(x < 0);

	do {
		printf("Digite o valor de N: ");
		scanf("%d", &n);

		if (n < 0) {
			printf("Digite somente valores positivos\n\n");
		}
	} while(n < 0);

	resultado = pow(x, n);

	printf("Resultado: %.2lf", resultado);

	return 0;
}
