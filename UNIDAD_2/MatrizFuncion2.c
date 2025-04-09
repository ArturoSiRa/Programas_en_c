#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int den; 
} Fraccion;

// Función para calcular el máximo común divisor (MCD)
int mcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para simplificar una fracción
Fraccion simplificar(Fraccion f) {
    int divisor = mcd(abs(f.num), abs(f.den));
    f.num /= divisor;
    f.den /= divisor;

    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }

    return f;
}

// Función para crear una fracción
Fraccion crearFraccion(int num, int den) {
    Fraccion f = {num, den};
    return simplificar(f);
}

// Operaciones básicas con fracciones
Fraccion sumarFracciones(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.num = a.num * b.den + b.num * a.den;
    resultado.den = a.den * b.den;
    return simplificar(resultado);
}

Fraccion restarFracciones(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.num = a.num * b.den - b.num * a.den;
    resultado.den = a.den * b.den;
    return simplificar(resultado);
}

Fraccion multiplicarFracciones(Fraccion a, Fraccion b) {
    Fraccion resultado;
    resultado.num = a.num * b.num;
    resultado.den = a.den * b.den;
    return simplificar(resultado);
}

// Función para leer una matriz de fracciones
void llenarMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas]) {
    printf("\nNombre de la matriz: %s\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese la fracción para [%d][%d] (formato a/b): ", i+1, j+1);
            scanf("%d/%d", &matriz[i][j].num, &matriz[i][j].den);
            while(matriz[i][j].den == 0) {
                printf("El denominador no puede ser cero. Ingrese nuevamente: ");
                scanf("%d/%d", &matriz[i][j].num, &matriz[i][j].den);
            }
            matriz[i][j] = simplificar(matriz[i][j]);
        }
    }
}

// Función para imprimir una matriz de fracciones
void imprimirMatriz(char *nombre, int filas, int columnas, Fraccion matriz[filas][columnas]) {
    printf("\n%s:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if(matriz[i][j].den == 1)
                printf("%4d\t", matriz[i][j].num);
            else
                printf("%2d/%-2d\t", matriz[i][j].num, matriz[i][j].den);
        }
        printf("\n");
    }
}

// Operaciones con matrices
void sumarMatrices(int filas, int columnas, Fraccion A[filas][columnas], Fraccion B[filas][columnas], Fraccion R[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            R[i][j] = sumarFracciones(A[i][j], B[i][j]);
        }
    }
}

void restarMatrices(int filas, int columnas, Fraccion A[filas][columnas], Fraccion B[filas][columnas], Fraccion R[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            R[i][j] = restarFracciones(A[i][j], B[i][j]);
        }
    }
}

void productoEscalar(int filas, int columnas, Fraccion escalar, Fraccion A[filas][columnas], Fraccion R[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            R[i][j] = multiplicarFracciones(escalar, A[i][j]);
        }
    }
}

void multiplicarMatrices(int filasA, int columnasA, int columnasB, Fraccion A[filasA][columnasA], Fraccion B[columnasA][columnasB], Fraccion R[filasA][columnasB]) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            R[i][j] = crearFraccion(0, 1); // Inicializar con 0
            for (int k = 0; k < columnasA; k++) {
                Fraccion producto = multiplicarFracciones(A[i][k], B[k][j]);
                R[i][j] = sumarFracciones(R[i][j], producto);
            }
        }
    }
}

// Función para calcular el determinante (solo para matrices 3x3)
Fraccion determinante3x3(Fraccion matriz[3][3]) {
    // Regla de Sarrus
    Fraccion diag1 = multiplicarFracciones(multiplicarFracciones(matriz[0][0], matriz[1][1]), matriz[2][2]);
    Fraccion diag2 = multiplicarFracciones(multiplicarFracciones(matriz[0][1], matriz[1][2]), matriz[2][0]);
    Fraccion diag3 = multiplicarFracciones(multiplicarFracciones(matriz[0][2], matriz[1][0]), matriz[2][1]);
    
    Fraccion diag4 = multiplicarFracciones(multiplicarFracciones(matriz[0][2], matriz[1][1]), matriz[2][0]);
    Fraccion diag5 = multiplicarFracciones(multiplicarFracciones(matriz[0][0], matriz[1][2]), matriz[2][1]);
    Fraccion diag6 = multiplicarFracciones(multiplicarFracciones(matriz[0][1], matriz[1][0]), matriz[2][2]);
    
    Fraccion sum_pos = sumarFracciones(sumarFracciones(diag1, diag2), diag3);
    Fraccion sum_neg = sumarFracciones(sumarFracciones(diag4, diag5), diag6);
    
    return restarFracciones(sum_pos, sum_neg);
}

int main() {
    int opcion;
    printf("OPERACIONES CON MATRICES DE FRACCIONES\n");
    
    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1. Suma de matrices\n");
        printf("2. Resta de matrices\n");
        printf("3. Producto escalar\n");
        printf("4. Multiplicacion de matrices\n");
        printf("5. Determinante (3x3)\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        if(opcion == 0) break;
        
        int filas, columnas;
        Fraccion escalar;
        
        switch(opcion) {
            case 1: // Suma
            case 2: { // Resta
                printf("\nIngrese dimensiones de las matrices (filas columnas): ");
                scanf("%d %d", &filas, &columnas);
                
                Fraccion A[filas][columnas], B[filas][columnas], R[filas][columnas];
                
                llenarMatriz("Matriz A", filas, columnas, A);
                llenarMatriz("Matriz B", filas, columnas, B);
                
                if(opcion == 1) {
                    sumarMatrices(filas, columnas, A, B, R);
                    imprimirMatriz("Resultado A + B", filas, columnas, R);
                } else {
                    restarMatrices(filas, columnas, A, B, R);
                    imprimirMatriz("Resultado A - B", filas, columnas, R);
                }
                break;
            }
            
            case 3: { // Producto escalar
                printf("\nIngrese dimensiones de la matriz (filas columnas): ");
                scanf("%d %d", &filas, &columnas);
                printf("Ingrese el escalar (fraccion a/b): ");
                scanf("%d/%d", &escalar.num, &escalar.den);
                escalar = simplificar(escalar);
                
                Fraccion A[filas][columnas], R[filas][columnas];
                llenarMatriz("Matriz A", filas, columnas, A);
                
                productoEscalar(filas, columnas, escalar, A, R);
                imprimirMatriz("Resultado del producto escalar", filas, columnas, R);
                break;
            }
            
            case 4: { // Multiplicación
                int filasA, columnasA, filasB, columnasB;
                printf("\nIngrese dimensiones de Matriz A (filas columnas): ");
                scanf("%d %d", &filasA, &columnasA);
                printf("Ingrese dimensiones de Matriz B (filas columnas): ");
                scanf("%d %d", &filasB, &columnasB);
                
                if(columnasA != filasB) {
                    printf("Error: Las matrices no son multiplicables\n");
                    break;
                }
                
                Fraccion A[filasA][columnasA], B[filasB][columnasB], R[filasA][columnasB];
                
                llenarMatriz("Matriz A", filasA, columnasA, A);
                llenarMatriz("Matriz B", filasB, columnasB, B);
                
                multiplicarMatrices(filasA, columnasA, columnasB, A, B, R);
                imprimirMatriz("Resultado A × B", filasA, columnasB, R);
                break;
            }
            
            case 5: { // Determinante
                printf("\nCalculo del determinante (matriz 3x3)\n");
                filas = columnas = 3;
                Fraccion A[3][3], det;
                
                llenarMatriz("Matriz A", 3, 3, A);
                det = determinante3x3(A);
                
                printf("\nDeterminante: ");
                if(det.den == 1)
                    printf("%d\n", det.num);
                else
                    printf("%d/%d\n", det.num, det.den);
                break;
            }
            
            default:
                printf("Opcion no valida!\n");
        }
        
    } while(opcion != 0);
    
    printf("\nPrograma terminado.\n");
    return 0;
}