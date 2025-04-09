#include <stdio.h>

#define FILAS 3
#define COLUMNAS 2

struct Carac {
    char marca[15];
    char estado[15];
    char color[20];
    int peso;
    int precio;
};

struct Audifonos {
    char conec[20];
    struct Carac uso;
};

int main() {
    struct Audifonos info[FILAS][COLUMNAS] = {
        {
            {"Inalambricos", {"Realme", "Nuevo", "Azul", 200, 1000}},
            {"Alambricos", {"Honor", "Usado", "Blanco", 150, 500}}
        },
        {
            {"Inalambricos", {"Sony", "Nuevo", "Rojo", 180, 800}},
            {"Alambricos", {"JBL", "Usado", "Negro", 160, 600}}
        },
        {
            {"Inalambricos", {"Huawei", "Nuevo", "Verde", 190, 1100}},
            {"Alambricos", {"Motorola", "Usado", "Gris", 170, 550}}
        }
    };

    printf("|%15s | %10s | %10s | %10s | %6s | %7s |",
           "Conexion", "Marca", "Estado", "Color", "Peso", "Precio");

    printf("\t|%15s | %10s | %10s | %10s | %6s | %7s |\n",
        "Conexion", "Marca", "Estado", "Color", "Peso", "Precio");
        printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("|%15s | %10s | %10s | %10s | %6d | $%6d |\t",
                   info[i][j].conec,
                   info[i][j].uso.marca,
                   info[i][j].uso.estado,
                   info[i][j].uso.color,
                   info[i][j].uso.peso,
                   info[i][j].uso.precio);
        }
        printf("\n");
    }

    return 0;
}
