#include <stdio.h>

/**
* Procura um elemento em um vetor de inteiros positivos ordenado em
* ordem crescente usando o método da pesquisa binária.
*
* @param chave O elemento a ser pesquisado.
* @param numeros Um vetor de inteiros positivos em ordem crescente.
* @param inicio O índice do primeiro elemento do vetor.
* @param fim O índice do último elemento do vetor.
* @return O índice da primeira ocorrência de \p chave em \p vet ou
* -1, caso o elemento não seja encontrado.
*/
int pesquisa_binaria(int chave, int numeros[], int inicio, int fim);

int main() {
    int numeros[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int resultado, chave;

    printf("Digite o elemento a ser pesquisado: ");
    scanf("%d", &chave);

    resultado = pesquisa_binaria(chave, numeros, 0, 14);

    if (resultado == -1) {
        printf("O elemento %d não foi encontrado.", chave);
    } else {
        printf("O elemento %d foi encontrado no índice %d.", chave, resultado);
    }

    return 0;
}

int pesquisa_binaria(int chave, int numeros[], int inicio, int fim) {
    int divisor, indice = -1;

	while (inicio <= fim) {
		divisor = (inicio + fim) / 2;

		if (numeros[divisor] == chave) {
            indice = divisor;
            break;
		} else if (numeros[divisor] < chave) {
            inicio = divisor + 1;
		} else {
			fim = divisor - 1;
		}
	}

    return indice;
}
