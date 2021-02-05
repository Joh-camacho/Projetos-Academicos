#include <stdio.h>

int fib_iter(int n);
int fib_rec(int n);

int main() {
    int n;

    printf("Digite o número: ");
    scanf("%d", &n);

    printf("\nFibonacci recursivo: %d\n", fib_rec(n));
    printf("Fibonacci iterativo: %d", fib_iter(n));

    return 0;
}

int fib_iter(int n) {
    int i, atual = 1, ant = 0;

    if (n > 0) {
        for (i = 1; i < n; i++) {
            atual += ant;
            ant = atual - ant;
        }

        return atual;
    } else {
        return 0;
    }
}

int fib_rec(int n) {
    if (n < 2) {
        return n;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}