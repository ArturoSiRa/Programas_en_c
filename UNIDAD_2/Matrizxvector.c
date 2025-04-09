#include <stdio.h>

void llenarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void llenarVector(int filas, int vector[filas]) {
    for (int i = 0; i < filas; i++) {
        printf("Ingrese el valor para la posición [%d]: ", i+1);
        scanf("%d", &vector[i]);
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirVector(int filas, int vector[filas]) {
    printf("Vector final:\n");
    for (int i = 0; i < filas; i++) {
        printf("%4d\n", vector[i]);
    }
}

void multvec(int filas, int columnas, int matriz[filas][columnas], int vector[columnas], int matrizr[filas]) {
    for (int i = 0; i < filas; i++) {
        matrizr[i] = 0;
    }
        for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizr[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    int filas, columnas;
    
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);
    
    int matriz_a[filas][columnas];
    int vect[columnas]; 
    int matriz_r[filas]; 
    
    printf("Ingresa la matriz\n");
    llenarMatriz(filas, columnas, matriz_a);
    printf("Ingresa el vector\n");
    llenarVector(columnas, vect);
    
    printf("\n");
    imprimirMatriz(filas, columnas, matriz_a);
    imprimirVector(filas, vect);
    
    multvec(filas, columnas, matriz_a, vect, matriz_r);
    
    printf("\n");
    imprimirVector(filas, matriz_r);
    
    return 0;
}