#include <stdio.h>
#include <string.h>

#define FILAS 2
#define COLUMNAS 2

typedef struct {
    char nombre[50];
    int edad;
} Gato;

typedef struct {
    char nombre[50];
    int edad;
} Perro;

typedef union {
    Gato gato;
    Perro perro;
} Dato;

typedef struct {
    Dato valor;
    int tipo;
} Celda;

int main() {
    Celda matriz[FILAS][COLUMNAS];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int opc = 0;

            printf("Selecciona 1 para gato y 2 para perro: ");
            scanf("%d", &opc);

            if (opc == 1) {
                printf("Ingrese el nombre del gato: ");
                scanf("%s", matriz[i][j].valor.gato.nombre);

                printf("Ingrese la edad del gato: ");
                scanf("%d", &matriz[i][j].valor.gato.edad);

                matriz[i][j].tipo = 1; 
            } else if (opc == 2) {
                printf("Ingrese el nombre del perro: ");
                scanf("%s", matriz[i][j].valor.perro.nombre);

                printf("Ingrese la edad del perro: ");
                scanf("%d", &matriz[i][j].valor.perro.edad);

                matriz[i][j].tipo = 2;
            } 
        }
    }

    printf("\nRecorriendo la matriz de uniones:\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("Celda [%d][%d]: ", i, j);

            if (matriz[i][j].tipo == 1) {
                printf("Gato - Nombre: %s, Edad: %d\n",
                       matriz[i][j].valor.gato.nombre,
                       matriz[i][j].valor.gato.edad);
            } else if (matriz[i][j].tipo == 2) {
                printf("Perro - Nombre: %s, Edad: %d\n",
                       matriz[i][j].valor.perro.nombre,
                       matriz[i][j].valor.perro.edad);
            }
        }
    }

    return 0;
}
