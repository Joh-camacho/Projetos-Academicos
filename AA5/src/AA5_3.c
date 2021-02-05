#include <stdio.h>

int tempo(float diametro, float braco);

int main() {
    float diametro, braco;

    printf("Digite o tamanho do lago em cm: ");
    scanf("%f", &diametro);

    printf("Digite o tamanho do braço da perereca: ");
    scanf("%f", &braco);

    printf("Demorou %d horas", tempo(diametro, braco));

    return 0;
}

int tempo(float diametro, float braco) {
    if (braco >= diametro) {
        return 0;
    } else {
        return 1 + tempo(diametro / 2.0f, braco);
    }
}

// int tempo(float diametro, float braco) {
//     int horas = 0;
//
//     if (braco < diametro) {
//         horas = 1 + tempo(diametro / 2.0f, braco);
//     }
//
//     return horas;
// }

// int tempo(float diametro, float braco) {
//     if (braco < diametro) {
//         return 1 + tempo(diametro / 2.0f, braco);
//     } else {
//         return 0;
//     }
// }
