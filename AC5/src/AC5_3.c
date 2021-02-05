#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[51];
    double nota[4];
};

int main() {
    struct aluno aluno;
    double media = 0;
    int i;

    printf("Digite seu nome completo: ");
    fgets(aluno.nome, 51, stdin);

    int last = strlen(aluno.nome) - 1;
    if (aluno.nome[last] == '\n') {
        aluno.nome[last] = '\0';
    } else {
        getchar();
    }

    for (i = 0; i < 4; i++) {
        printf("Digite sua %d nota parcial: ", i + 1);
        scanf("%lf", &aluno.nota[i]);

        media += aluno.nota[i];
    }

    printf("\nNome completo: %s\n", aluno.nome);
    printf("Nota parcial 1: %.2lf\n", aluno.nota[0]);
    printf("Nota parcial 2: %.2lf\n", aluno.nota[1]);
    printf("Nota parcial 3: %.2lf\n", aluno.nota[2]);
    printf("Nota parcial 4: %.2lf\n", aluno.nota[3]);
    printf("Média aritmética: %.2lf\n", (media / 4));
    return 0;
}
