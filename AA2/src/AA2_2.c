#include <stdio.h>

#define TAMANHO 10

int main() {
	int i, num[TAMANHO], posMaior = 0, posMenor = 0;

	for (i = 0; i < TAMANHO; i++) {
		printf("Digite o n�mero: ");
		scanf("%d", &num[i]);
	}

	for (i = 0; i < TAMANHO; i++) {
		if (num[i] > num[posMaior]) {
			posMaior = i;
		} else if (num[i] < num[posMenor]) {
			posMenor = i;
		}
	}

	printf("O maior elemento do vetor � %d e se encontra na posi��o %d\n", num[posMaior], posMaior);
	printf("O menor elemento do vetor � %d e se encontra na posi��o %d", num[posMenor], posMenor);

	return 0;
}
