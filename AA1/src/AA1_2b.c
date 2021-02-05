#include <stdio.h>

int main() {
	int k;

	printf("Digite o valor de k: ");
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
