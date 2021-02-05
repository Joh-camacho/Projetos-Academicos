#include <stdio.h>

void bubble_sort(int vetor[], int size) {
    int i, j, aux;

    for (i = 1; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j]; // Atribuir o valor atual no aux
                vetor[j] = vetor[j + 1]; // Inverter as posi��es
                vetor[j + 1] = aux; // Inverter as posi��es com o valor salvo em aux
            }
        }
    }
}

int main() {
    int i, size, vetor[100];

    printf("Digite a quantia de n�meros que deseja preencher o vetor: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("Digite o %d n�mero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor, size);

    printf("\nLista ordenada: ");
    for (i = 0; i < size; i++) {
        printf("[%d] ", vetor[i]);
    }

    return 0;
}
