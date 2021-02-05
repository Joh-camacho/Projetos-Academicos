#include <stdio.h>
#include <string.h>

int main() {
    char s[100], ch1;
    int v[100], i, counter;

    printf("Digite uma string: ");
    scanf("%[^\n]", s);
    getchar();

    printf("Digite o caractere: ");
    scanf("%c", &ch1);

    printf("Indices onde ocorrem o caractere '%c': ", ch1);

    counter = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ch1) {
            v[counter] = i;

            counter++;
        }
    }

    for (i = 0; i < counter; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
