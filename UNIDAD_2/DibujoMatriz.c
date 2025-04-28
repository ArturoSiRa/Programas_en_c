#include <stdio.h>

 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
void setColor(const char* color) {
    printf("%s", color);
}
void limpiarPantalla(){
    printf("\033[2J");}

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

void sumarMatriz(int filas, int columnas, 
 int matriz1[filas][columnas], int matriz2[filas][columnas], 
 int matrizr[filas][columnas]){
 for (int i = 0 ; i < filas; i++){
 for (int j = 0 ; j < columnas; j++){
 matrizr[i][j] = matriz1[i][j] + matriz2[i][j];
 } }
}

void restaMatriz(int filas, int columnas, 
    int matriz1[filas][columnas], int matriz2[filas][columnas], 
    int matrizr[filas][columnas]){
    for (int i = 0 ; i < filas; i++){
    for (int j = 0 ; j < columnas; j++){
    matrizr[i][j] = matriz1[i][j] - matriz2[i][j];
    } }
   }

void escMatriz1(int filas, int columnas, int num,
    int matriz1[filas][columnas], 
    int matrizr[filas][columnas]){
    for (int i = 0 ; i < filas; i++){
    for (int j = 0 ; j < columnas; j++){
    matrizr[i][j] = matriz1[i][j] * num ;
    } }
   }
   
void escMatriz2(int filas, int columnas, int num,
    int matriz1[filas][columnas], 
    int matrizr[filas][columnas]){
    for (int i = 0 ; i < filas; i++){
    for (int j = 0 ; j < columnas; j++){
    matrizr[i][j] = matriz1[i][j] * num ;
    } }
   }

float cdet(int filas, int columnas, int matriz[filas][columnas]) {
   
    float det = 0;
    int matrizn[3][5];
    int diag1 = 0;
    int diag2 = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizn[i][j] = matriz[i][j];
        }
        matrizn[i][3] = matriz[i][0];
        matrizn[i][4] = matriz[i][1];
    }

    diag1 = 0;
    for (int j = 0; j < 3; j++) {
        int mult1 = 1;
        for (int i = 0; i < 3; i++) {
            mult1 *= matrizn[i][(i + j) % 5];
        }
        diag1 += mult1;
    }
    diag2 = 0;
    for (int j = 0; j < 3; j++) {
        int mult2 = 1;
        for (int i = 0; i < 3; i++) {
            mult2 *= matrizn[2-i][(i + j) % 5];
        }
        diag2 += mult2;
    }
    det = diag1 - diag2;
    return det;
}

int main() {

    printf("\033[2J");
 int filas, columnas;
 printf("Para calcular el determinante la matriz debe ser 3x3.\n");
 printf("Ingrese el número de filas: ");
 scanf("%d", &filas);
 printf("Ingrese el número de columnas: ");
 scanf("%d", &columnas);
 
 int matriz_a[filas][columnas];
 int matriz_b[filas][columnas];
 int matriz_r[filas][columnas];
 

 llenarMatriz(filas, columnas, matriz_a);
 llenarMatriz(filas, columnas, matriz_b);
 printf("\n\n\n\n");
 imprimirMatriz(filas, columnas, matriz_a);
 imprimirMatriz(filas, columnas, matriz_b);
 sumarMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
 imprimirMatriz(filas, columnas, matriz_r);
 restaMatriz(filas, columnas, matriz_a, matriz_b, matriz_r);
 imprimirMatriz(filas, columnas, matriz_r);

 
 int esc1;
 printf("\nIngresa el numero para multiplicar para matriz A: ");
 scanf("%d", &esc1);
 escMatriz1(filas, columnas, esc1, matriz_a, matriz_r);
 imprimirMatriz(filas, columnas, matriz_r);

 int esc2;
 printf("\nIngresa el numero para multiplicar para matriz B: ");
 scanf("%d", &esc2);
 escMatriz2(filas, columnas, esc2, matriz_b, matriz_r);
 imprimirMatriz(filas, columnas, matriz_r);

 
 
 float det1 = 0;
 float det2 = 0;
 printf("\n\nDeterminante de Matriz A\n");
     det1 = cdet(filas, columnas, matriz_a);
         printf("El resultado es: %.2f\n", det1);

 printf("\n\nDeterminante de Matriz B\n");
     det2 = cdet(filas, columnas, matriz_b);
         printf("El resultado es: %.2f\n", det2);
     

 
 return 0;
}