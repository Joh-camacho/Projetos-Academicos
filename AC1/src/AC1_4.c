#include <stdio.h>

int main() {
	int senha;

	do {
		printf("Digite a senha: ");
		scanf("%d", &senha);

		if (senha != 2002) {
			printf("Senha Invalida\n");
		}
	} while (senha != 2002);

	printf("Acesso Permitido");

	return 0;
}
