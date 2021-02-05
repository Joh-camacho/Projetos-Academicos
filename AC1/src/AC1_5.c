#include <stdio.h>
#include <math.h>

int main() {
	double valor;
	int nota100 = 0, nota50 = 0, nota20 = 0, nota10 = 0, nota5 = 0, nota2 = 0;
	int moeda100 = 0, moeda50 = 0, moeda25 = 0, moeda10 = 0, moeda05 = 0, moeda01 = 0;

	printf("Digite o valor: ");
	scanf("%lf", &valor);

	// NOTAS:
	nota100 = valor / 100;
	valor = fmod(valor, 100);

	nota50 = valor / 50;
	valor = fmod(valor, 50);

	nota20 = valor / 20;
	valor = fmod(valor, 20);

	nota10 = valor / 10;
	valor = fmod(valor, 10);

	nota5 = valor / 5;
	valor = fmod(valor, 5);

	nota2 = valor / 2;
	valor = fmod(valor, 2);

	// MOEDAS:
	moeda100 = valor / 1;
	valor = fmod(valor, 1);

	moeda50 = valor / 0.50;
	valor = fmod(valor, 0.50);

	moeda25 = valor / 0.25;
	valor = fmod(valor, 0.25);

	moeda10 = valor / 0.10;
	valor = fmod(valor, 0.10);

	moeda05 = valor / 0.05;
	valor = fmod(valor, 0.05);

	moeda01 = valor / 0.01;
	valor = fmod(valor, 0.01);

	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", nota100);
	printf("%d nota(s) de R$ 50.00\n", nota50);
	printf("%d nota(s) de R$ 20.00\n", nota20);
	printf("%d nota(s) de R$ 10.00\n", nota10);
	printf("%d nota(s) de R$ 5.00\n", nota5);
	printf("%d nota(s) de R$ 2.00\n\n", nota2);

	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", moeda100);
	printf("%d moeda(s) de R$ 0.50\n", moeda50);
	printf("%d moeda(s) de R$ 0.25\n", moeda25);
	printf("%d moeda(s) de R$ 0.10\n", moeda10);
	printf("%d moeda(s) de R$ 0.05\n", moeda05);
	printf("%d moeda(s) de R$ 0.01\n", moeda01);

	return 0;
}
