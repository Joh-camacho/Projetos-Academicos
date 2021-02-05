#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct aluno {
    int idade, comportamento, rendimento, merecimento;
};

int main() {
    struct aluno alunos[MAX];
    int validacao, i;

    for (i = 0; i < MAX; i++) {
        system("clear||cls");
		printf("Dados da %d° criança:\n\n", i + 1);

        do {
			printf("Digite a idade: ");
			scanf("%d", &alunos[i].idade);
            getchar();

			if (&alunos[i].idade < 0) {
				printf("Idade não pode ser negativa.\n\n");
		    }
		} while (&alunos[i].idade < 0);
		do {
			printf("Digite a nota do comportamento: ");
			scanf("%d", &alunos[i].comportamento);
            getchar();

			validacao = alunos[i].comportamento <= 10 && alunos[i].comportamento >= 0;

			if (!validacao) {
				printf("Digite a nota do comportamento de 0 a 10.\n\n");
			}
		} while (!validacao);
        do {
			printf("Digite a nota do rendimento: ");
			scanf("%d", &alunos[i].rendimento);
            getchar();

			validacao = alunos[i].rendimento <= 10 && alunos[i].rendimento >= 0;

			if (!validacao) {
				printf("Digite a nota do rendimento de 0 a 10.\n\n");
			}
		} while (!validacao);

        if (alunos[i].idade < 12 && alunos[i].rendimento > 8 && alunos[i].comportamento > 6) {
            alunos[i].merecimento = 1;

            printf("Receberá o presente.\n\n");
        } else {
            alunos[i].merecimento = 0;

            printf("Não receberá o presente.\n\n");
        }

        printf("Aperte qualquer tecla para continuar.");
		getchar();
    }

    system("clear||cls");
    printf("As criança(s) que receberá(ão) os presentes são: ");
    for (i = 0; i < MAX; i++) {
        if (alunos[i].merecimento == 1) {
	        printf("%d ", i);
        }
    }

    return 0;
}
