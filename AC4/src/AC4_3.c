#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char firstString[51], secondString[51], thirdString[51], fourthString[51], fifthString[51], concatenacao[255];
    char continuar;
    int i;

    printf("Digite a primeira string: ");
    scanf("%[^\n]", firstString);
    getchar();

    printf("Digite a segunda string: ");
    scanf("%[^\n]", secondString);
    getchar();

    printf("Digite a terceira string: ");
    scanf("%[^\n]", thirdString);
    getchar();

    printf("Para adicionar a quarta string digite 'S'.");
    continuar = toupper(getchar());
    getchar();

    if (continuar == 'S') {
        printf("Digite a quarta string: ");
        scanf("%[^\n]", fourthString);
        getchar();

        printf("Para adicionar a quinta string digite 'S'.");
        continuar = toupper(getchar());
        getchar();

        if (continuar == 'S') {
            printf("Digite a quinta string: ");
            scanf("%[^\n]", fifthString);
            getchar();
        } else {
            fifthString[0] = '\0';
        }
    } else {
        fourthString[0] = '\0';
        fifthString[0] = '\0';
    }

    strcpy(concatenacao, firstString);
    strcat(concatenacao, " ");
    strcat(concatenacao, secondString);
    strcat(concatenacao, " ");
    strcat(concatenacao, thirdString);

    printf("\nPrimeira string: %s\n", firstString);
    printf("Segunda string: %s\n", secondString);
    printf("Terceira string: %s\n", thirdString);

    if (fourthString[0] != '\0') {
        printf("Quarta string: %s\n", fourthString);

        strcat(concatenacao, " ");
        strcat(concatenacao, fourthString);

        if (fifthString[0] != '\0') {
            printf("Quinta string: %s\n", fifthString);

            strcat(concatenacao, " ");
            strcat(concatenacao, fifthString);
        }
    }

    for (i = 0; i < strlen(concatenacao); i++) {
        if (concatenacao[i - 1] == ' ') {
            concatenacao[i] = toupper(concatenacao[i]);
        }
    }

    concatenacao[0] = toupper(concatenacao[0]);

    printf("\nConcatenação: %s", concatenacao);

    return 0;
}
