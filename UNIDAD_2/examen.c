#include <stdio.h>
#include <stdlib.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setColor(const char* color) {
    printf("%s", color);
}

void limpiarPantalla() {
    printf("\033[2J");
}

int** crearMatriz(int filas, int cols) {
    int **matriz = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(cols * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
void dibujarMatrizVisual(int x, int y, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            gotoxy(x + j * 6, y + i * 2);
            printf("+----+");
            gotoxy(x + j * 6, y + i * 2 + 1);
            printf("|    |");
        }
    }
}

void capturarMatriz(int **matriz, int x, int y, int filas, int cols, const char* color) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            gotoxy(x + j * 6 + 2, y + i * 2 + 1);
            setColor(color);
            printf("\033[4m"); // subrayado
            scanf("%d", &matriz[i][j]);
            setColor("\033[0m");
        }
    }
}

void imprimirMatrizResultado(int **matriz, int x, int y, int filas, int cols, const char* color) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            gotoxy(x + j * 6 + 2, y + i * 2 + 1);
            setColor(color);
            printf("%2d", matriz[i][j]);
            setColor("\033[0m");
        }
    }
}

void sumarMatrices(int **A, int **B, int **C, int filas, int cols) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void restarMatrices(int **A, int **B, int **C, int filas, int cols) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void multiplicarEscalar(int **A, int **C, int filas, int cols, int escalar) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] * escalar;
}


int main(){
    limpiarPantalla();

    int filas, cols, escalar;
 
    int opc;
    gotoxy(10, 5);
    printf("Ingrese la opción deseada: ");

    gotoxy(10, 7);
    printf("1) Suma de matrices ");

    gotoxy(10, 9);
    printf("2) Resta de matrices ");
    
    gotoxy(10, 11);
    printf("3) Escalar");

    gotoxy(10, 13);
    printf("4) Exponencial");
    
    gotoxy(100, 20);
    scanf("%d", &opc);
    
    switch (opc)
    {
    case 1:
    limpiarPantalla();
    gotoxy(5, 2);
    printf("Ingrese número de filas de la matriz: ");
    scanf("%d", &filas);
    gotoxy(5, 3);
    printf("Ingrese número de columnas de la matriz: ");
    scanf("%d", &cols);
    int **A = crearMatriz(filas, cols);
    int **B = crearMatriz(filas, cols);
    int **C = crearMatriz(filas, cols);

    int x1 = 5;
    int x2 = x1 + cols * 6 + 10;
    int x3 = x2 + cols * 6 + 10;
    int y = 5;

    gotoxy(x1, y - 2);
        printf("Matriz A");
        dibujarMatrizVisual(x1, y, filas, cols);
        capturarMatriz(A, x1, y, filas, cols, "\033[7;31m");

        gotoxy(x2, y - 2);
        printf("Matriz B");
        dibujarMatrizVisual(x2, y, filas, cols);
        capturarMatriz(B, x2, y, filas, cols, "\033[7;34m");

        sumarMatrices(A, B, C, filas, cols);

        gotoxy(x1 + cols * 6 + 2, y + 2);
        setColor("\033[1;33m");
        printf("+");

        gotoxy(x2 + cols * 6 + 2, y + 2);
        printf("=");

        gotoxy(x3, y - 2);
        printf("Resultado");
        dibujarMatrizVisual(x3, y, filas, cols);
        imprimirMatrizResultado(C, x3, y, filas, cols, "\033[7;32m");

        break;
    
    case 2:
        limpiarPantalla();
        gotoxy(5, 2);
        printf("Ingrese número de filas de la matriz: ");
        scanf("%d", &filas);
        gotoxy(5, 3);
        printf("Ingrese número de columnas de la matriz: ");
        scanf("%d", &cols);
        int **A2 = crearMatriz(filas, cols);
        int **B2 = crearMatriz(filas, cols);
        int **C2 = crearMatriz(filas, cols);

        int x11 = 5;
        int x22 = x11 + cols * 6 + 10;
        int x33 = x22 + cols * 6 + 10;
        int y2 = 5;
        
        gotoxy(x11, y2 - 2);
        printf("Matriz A");
        dibujarMatrizVisual(x11, y2, filas, cols);
        capturarMatriz(A2, x11, y2, filas, cols, "\033[7;31m");

        gotoxy(x22, y2 - 2);
        printf("Matriz B");
        dibujarMatrizVisual(x22, y2, filas, cols);
        capturarMatriz(B2, x22, y2, filas, cols, "\033[7;34m");

        restarMatrices(A2, B2, C2, filas, cols);

        gotoxy(x1 + cols * 6 + 2, y2 + 2);
        setColor("\033[1;33m");
        printf("+");

        gotoxy(x22 + cols * 6 + 2, y2 + 2);
        printf("=");

        gotoxy(x33, y2 - 2);
        printf("Resultado");
        dibujarMatrizVisual(x33, y2, filas, cols);
        imprimirMatrizResultado(C2, x33, y2, filas, cols, "\033[7;32m");
        break;
    
    case 3:
    limpiarPantalla();
        int **A3 = crearMatriz(filas, cols);
        int **C3 = crearMatriz(filas, cols);

        int x12 = 5;
        int x23 = x11 + cols * 6 + 10;
        int x34 = x22 + cols * 6 + 10;
        int y3 = 5;
        
        gotoxy(x12, y3 - 2);
        printf("Matriz A");
        dibujarMatrizVisual(x12, y3, filas, cols);
        capturarMatriz(A3, x12, y3, filas, cols, "\033[7;36m");

        gotoxy(5, y3 + filas * 2 + 3);
        printf("Ingrese escalar: ");
        scanf("%d", &escalar);

        multiplicarEscalar(A3, C3, filas, cols, escalar);

        gotoxy(x12 + cols * 6 + 2, y3 + 2);
        setColor("\033[1;33m");
        printf("*");

        gotoxy(x23, y3 + 2);
        setColor("\033[0m");
        printf("%d", escalar);

        gotoxy(x23 + 6, y3 + 2);
        printf("=");

        dibujarMatrizVisual(x34, y3, filas, cols);
        imprimirMatrizResultado(C3, x34, y3, filas, cols, "\033[7;35m");
    default:
        break;
    }

}