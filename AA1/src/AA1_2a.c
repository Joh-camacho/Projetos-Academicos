#include <stdio.h>

int main() {
	int i, j;

	printf("Digite o valor de i: ");
	scanf("%d", &i);

	printf("Digite o valor de j: ");
	scanf("%d", &j);

	for (int y = 0; y < i; y++) {
		for (int x = 0; x < j; x++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
