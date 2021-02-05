#include <stdio.h>

int main() {
	double a, b, c, media;

	do {
		printf("Digite a nota A: ");
		scanf("%lf", &a);
	} while(a < 0.0 || a > 10.0);

	do {
		printf("Digite a nota B: ");
		scanf("%lf", &b);
	} while(b < 0.0 || b > 10.0);

	do {
		printf("Digite a nota C: ");
		scanf("%lf", &c);
	} while(c < 0.0 || c > 10.0);

	media = ((a * 2.0) + (b * 3.0) + (c * 5.0)) / (2.0 + 3.0 + 5.0);

	printf("A média ponderada é: %.1lf", media);

	return 0;
}
