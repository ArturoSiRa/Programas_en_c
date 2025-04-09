#include <stdio.h>

void llenarMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(char *nombre, int filas, int columnas, int matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void copiarMatriz(int filas, int columnas, int origen[filas][columnas], int destino[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

void multMat(int filasA, int columnasA, int columnasB, 
    int matrizA[filasA][columnasA], int matrizB[columnasA][columnasB], 
    int matrizR[filasA][columnasB]) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            matrizR[i][j] = 0;
        }
    }
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                matrizR[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void elevarMatriz(int n, int exponente, int matriz[n][n], int resultado[n][n]) {
    int tem[n][n];
    int sum[n][n];

    copiarMatriz(n, n, matriz, sum); 

    for (int i = 1; i < exponente; i++) {
        multMat(n, n, n, sum, matriz, tem); 
        copiarMatriz(n, n, tem, sum); 
    }

    copiarMatriz(n, n, sum, resultado);
}

int main() {
    int n, exponente;

    printf("Ingrese el tamaño de la matriz: ");
    scanf("%d", &n);

    printf("Ingrese el exponente al que se elevará la matriz: ");
    scanf("%d", &exponente);

    if (exponente < 1) {
        printf("El exponente debe ser mayor o igual a 1.\n");
        return 1;
    }

    int matriz[n][n];
    int resultado[n][n];

    llenarMatriz("Matriz", n, n, matriz);

    imprimirMatriz("Matriz Original", n, n, matriz);

    if (exponente == 1) {
        copiarMatriz(n, n, matriz, resultado);
    } else {
        elevarMatriz(n, exponente, matriz, resultado);
    }

    imprimirMatriz("Matriz Elevada", n, n, resultado);

    return 0;
}
