#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int acertos = 0, caudas;
	double kgs;
	char nomeVila;

	printf("1. Quantas caudas a Kyūbi tem ? ");
	scanf("%d", &caudas);

	if (caudas == 9)
		acertos++;

	getchar();

	printf("2. Qual a primeira letra do nome da vila onde Naruto nasceu ? ");
	nomeVila = toupper(getchar());

	if (nomeVila == 'K')
		acertos++;

	printf("3. Quantos kg o Naruto tinha no Shippūden ? ");
	scanf("%lf", &kgs);

	if (kgs == 50.9)
		acertos++;

	printf("Você acertou %d perguntas!\n", acertos);

	if (acertos > 1) {
		printf("Você é raiz.");
	} else {
		printf("Você é nutella.");
	}

	return 0;
}
