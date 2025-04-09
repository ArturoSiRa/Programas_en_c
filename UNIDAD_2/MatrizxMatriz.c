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

void multMat(int filasA, int columnasA, int columnasB, int matrizA[filasA][columnasA], int matrizB[columnasA][columnasB], int matrizR[filasA][columnasB]) {

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

int main() {
    int filasA, columnasA, filasB, columnasB;
    
    printf("Ingrese las dimensiones de la Matriz A:\n");
    printf("Número de filas: ");
    scanf("%d", &filasA);
    printf("Número de columnas: ");
    scanf("%d", &columnasA);
    
    printf("\nIngrese las dimensiones de la Matriz B:\n");
    printf("Número de filas: ");
    scanf("%d", &filasB);
    printf("Número de columnas: ");
    scanf("%d", &columnasB);

    if (columnasA != filasB) {
        printf("\nLa matriz dos debe tener el mismo número de columnas que filas de la uno.\n");
        return 1;
    }
    else{
    int matriz_a[filasA][columnasA];
    int matriz_b[filasB][columnasB];
    int matriz_r[filasA][columnasB];
    
    printf("\n");
    llenarMatriz("Matriz A", filasA, columnasA, matriz_a);
    printf("\n");
    llenarMatriz("Matriz B", filasB, columnasB, matriz_b);
    
    printf("\n");
    imprimirMatriz("Matriz A", filasA, columnasA, matriz_a);
    printf("\n");
    imprimirMatriz("Matriz B", filasB, columnasB, matriz_b);
    
    multMat(filasA, columnasA, columnasB, matriz_a, matriz_b, matriz_r);
    
    printf("\n");
    imprimirMatriz("Resultado A×B", filasA, columnasB, matriz_r);
    }
    return 0;
}