#include <stdio.h>


typedef struct {
    int num;
    int den; 
} Fraccion;

int mcd(int a, int b) {
    int temp, i = 0;
    for (i = 0; b != 0; i++) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraccion simplificar(Fraccion f) {
    int divisor = mcd(f.num, f.den);
    f.num /= divisor;
    f.den /= divisor;

    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }

    return f;
}

Fraccion multiplicarFracciones(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.num = a.num * b.num;
    resultado.den = a.den * b.den;
    return simplificar(resultado);
}

Fraccion sumarFracciones(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.num = a.num * b.den + b.num * a.den;
    resultado.den = a.den * b.den;
    return simplificar(resultado);
}

void llenarMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese la fracción para la posición [%d][%d] (formato a/b): ", i+1, j+1);
            scanf("%d/%d", &matriz[i][j].num, &matriz[i][j].den);
            matriz[i][j] = simplificar(matriz[i][j]);
        }
    }
}

void imprimirMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas]) {
    printf("Nombre de la matriz: %s\n", nombre);
    printf("Matriz:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d/%d\t", matriz[i][j].num, matriz[i][j].den);
        }
        printf("\n");
    }
}

void multMat(int filasA, int columnasA, int columnasB,
             Fraccion matrizA[filasA][columnasA],
             Fraccion matrizB[columnasA][columnasB],
             Fraccion matrizR[filasA][columnasB]) {

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            matrizR[i][j].num = 0;
            matrizR[i][j].den = 1;
        }
    }

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                Fraccion producto = multiplicarFracciones(matrizA[i][k], matrizB[k][j]);
                matrizR[i][j] = sumarFracciones(matrizR[i][j], producto);
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
    } else {
        Fraccion matriz_a[filasA][columnasA];
        Fraccion matriz_b[filasB][columnasB];
        Fraccion matriz_r[filasA][columnasB];

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
