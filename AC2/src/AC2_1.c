#include <stdio.h>

#define TAMANHO 255

int main() {
	char caracter;
	int i;

	for (i = 0; i < TAMANHO; i++) {
		caracter = i;

		switch (caracter) {
		case 'a': case 'A':
		case 'c': case 'C':
		case 'f': case 'F':
		case 'w': case 'W':
			printf("\nFoi encontrado o caracter %c\n", caracter);
			break;
		}

		if (i > 0 && i % 15 == 0) {
			printf("\nAperte qualquer tecla para continuar.\n");
			getchar();
		}

		printf("%d: %c \n", i, caracter);
	}

	return 0;
}
