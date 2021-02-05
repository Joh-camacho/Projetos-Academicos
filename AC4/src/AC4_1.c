#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[101], destino[101];
    int i;

    printf("Digite um texto de até %d caracteres: ", 101 - 1);
    fgets(texto, 101, stdin);

    i = strlen(texto) - 1;
    if (texto[i] == '\n') {
        texto[i] = '\0';
    }

    strcpy(destino, texto);

    for (i = 0; i < strlen(destino); i++) {
        destino[i] = toupper(destino[i]);
    }

    printf("\nTexto original: %s\n", texto);
    printf("Texto final: %s\n", destino);

    return 0;
}
