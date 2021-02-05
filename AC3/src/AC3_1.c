#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

int main() {
    int matriz[TAMANHO][TAMANHO], i, j;

    srand(time(NULL));

    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            matriz[i][j] = rand() % 10;
        }

        printf("    %d", i);
    }

	printf("\n\n");

	for (i = 0; i < TAMANHO; i++) {
		printf("%d", i);

		for (j = 0; j < TAMANHO; j++) {
			printf("   %d ", matriz[i][j]);
		}

		printf("\n");
	}

    printf("\nDiagonal principal: ");

	for (i = 0; i < TAMANHO; i++) {
		for (j = 0; j < TAMANHO; j++) {
            if (i == j) {
                printf("%d, ", matriz[i][j]);
            }
		}
	}

    return 0;
}
