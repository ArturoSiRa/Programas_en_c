#include <stdio.h>

int main() {
    int fila = 3;
    int columna = 6;
    float num[fila][columna];

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Ingresa el valor [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &num[i][j]);
        }

        num[i][2] = num[i][0] + num[i][1];
        num[i][3] = num[i][0] - num[i][1];
        num[i][4] = num[i][0] * num[i][1];
        num[i][5] = num[i][0] / num[i][1];
    }

    printf("\n%-17s|%-17s|%-17s|%-17s|%-17s|%-17s\n", "Valor 1", "Valor 2", "Suma", "Resta", "Multiplicación", "División");

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna; j++) {
            printf("%-18.2f", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}

