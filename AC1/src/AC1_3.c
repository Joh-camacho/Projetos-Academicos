#include <stdio.h>

int main() {
	int ddd;

	printf("Digite o DDD: ");
	scanf("%d", &ddd);

	switch (ddd) {
	case 61:
		printf("Bras�lia");
		break;
	case 71:
		printf("Salvador");
		break;
	case 11:
		printf("S�o Paulo");
		break;
	case 21:
		printf("Rio de Janeiro");
		break;
	case 32:
		printf("Juiz de Fora");
		break;
	case 19:
		printf("Campinas");
		break;
	case 27:
		printf("Vit�ria");
		break;
	case 31:
		printf("Belo Horizonte");
		break;
	default:
		printf("DDD n�o cadastrado");
		break;
	}

	return 0;
}
