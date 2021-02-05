#include <stdio.h>
#include <string.h>

int main() {
    char dna[] = {'A', 'T', 'C', 'C', 'G', 'T', 'T', 'A', 'A', '\0'};
    int i;

    printf("Sequência de DNA: ");
    for (i = 0; i < strlen(dna); i++) {
        printf("%c ", dna[i]);
    }

    printf("\nSequência de RNA: ");
    for (i = 0; i < strlen(dna); i++) {
        switch (dna[i]) {
            case 'A':
                printf("U ");
                break;
            case 'G':
                printf("C ");
                break;
            case 'C':
                printf("G ");
                break;
            case 'T':
                printf("A ");
                break;
        }
    }

    return 0;
}
