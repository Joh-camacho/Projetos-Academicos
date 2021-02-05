#include <stdio.h>

#define TAMANHO 5

int main() {
	int i, n[TAMANHO];

	for (i = 0; i < TAMANHO; i++) {
		printf("Digite o %dº valor de N: ", i + 1);
		scanf("%d", &n[i]);
	}

	for (i = TAMANHO - 1; i >= 0; i--) {
		printf("%d, ", n[i]);
	}

	return 0;
}
