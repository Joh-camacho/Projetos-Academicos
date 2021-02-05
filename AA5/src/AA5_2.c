#include <stdio.h>

double maior_iter(double numeros[], int n);
double maior_rec(double numeros[], int n);

int main() {
    double numeros[100];
    int n, i;

    printf("Digite a quantia de elementos na função: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o %d número: ", i + 1);
        scanf("%lf", &numeros[i]);
    }

    printf("\nMaior iterativo: %.2lf", maior_rec(numeros, n));
    printf("\nMaior recursivo: %.2lf", maior_rec(numeros, n));

    return 0;
}

double maior_iter(double numeros[], int n) {
    double maior = numeros[0];
	int i;

    for (i = 0; i < n; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
    }

    return maior;
}

double maior_rec(double numeros[], int n) {
    double maior;

    if (n == 1) {
        maior = numeros[0];
    } else {
        maior = maior_rec(numeros, n - 1); 

        if (maior < numeros[n - 1]) {
            maior = numeros[n - 1];
        }
    }

    return maior;
}