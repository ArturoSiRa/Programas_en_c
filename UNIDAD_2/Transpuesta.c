#include <stdio.h>

void llenarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
 for (int i = 0; i < filas; i++) {
 for (int j = 0; j < columnas; j++) {
 printf("Ingrese el valor para la posición [%d][%d]: ", i+1, j+1);
 scanf("%d", &matriz[i][j]);
 }}
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
 printf("Matriz ingresada:\n");
 for (int i = 0; i < filas; i++) {
 for (int j = 0; j < columnas; j++) {
 printf("%4d ", matriz[i][j]);}
 printf("\n");  }
}

void tran(int filas, int columnas, 
 int matriz1[filas][columnas], int matrizr[filas][columnas]){
 for (int i = 0 ; i < filas; i++){
 for (int j = 0 ; j < columnas; j++){
 matrizr[j][i] = matriz1[i][j];
 } }
}

int main() {
    int filas, columnas;
    printf("Para calcular el determinante la matriz debe ser 3x3.\n");
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);
    
    int matriz_a[filas][columnas];
    int matriz_r[filas][columnas];
    
   
    llenarMatriz(filas, columnas, matriz_a);
    imprimirMatriz(filas, columnas, matriz_a);
    tran(filas, columnas, matriz_a, matriz_r);
    imprimirMatriz(filas, columnas, matriz_r);


    return 0;
   }