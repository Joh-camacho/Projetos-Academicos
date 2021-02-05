#include <stdio.h>

#define TAMANHO 10

int main() {
	int i, num[TAMANHO], posMaior = 0, posMenor = 0;

	for (i = 0; i < TAMANHO; i++) {
		printf("Digite o número: ");
		scanf("%d", &num[i]);
	}

	for (i = 0; i < TAMANHO; i++) {
		if (num[i] > num[posMaior]) {
			posMaior = i;
		} else if (num[i] < num[posMenor]) {
			posMenor = i;
		}
	}

	printf("O maior elemento do vetor é %d e se encontra na posição %d\n", num[posMaior], posMaior);
	printf("O menor elemento do vetor é %d e se encontra na posição %d", num[posMenor], posMenor);

	return 0;
}
