#include <stdio.h>

/**
* Procura um elemento em um vetor de inteiros positivos ordenado em
* ordem crescente usando o m�todo da pesquisa bin�ria.
*
* @param chave O elemento a ser pesquisado.
* @param numeros Um vetor de inteiros positivos em ordem crescente.
* @param inicio O �ndice do primeiro elemento do vetor.
* @param fim O �ndice do �ltimo elemento do vetor.
* @return O �ndice da primeira ocorr�ncia de \p chave em \p vet ou
* -1, caso o elemento n�o seja encontrado.
*/
int pesquisa_binaria(int chave, int numeros[], int inicio, int fim);

int main() {
    int numeros[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int resultado, chave;

    printf("Digite o elemento a ser pesquisado: ");
    scanf("%d", &chave);

    resultado = pesquisa_binaria(chave, numeros, 0, 14);

    if (resultado == -1) {
        printf("O elemento %d n�o foi encontrado.", chave);
    } else {
        printf("O elemento %d foi encontrado no �ndice %d.", chave, resultado);
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
