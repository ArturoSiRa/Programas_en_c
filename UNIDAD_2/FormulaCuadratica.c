#include <stdio.h>
#include <math.h>
#include <string.h>

struct Eccuadratica {
    int a;
    int b;
    int c;
    int d;
    float x1;
    float x2;
    char solucion[30];
};

int main() {
    struct Eccuadratica arreglo[2] = {
        {2, 3, -5, 0, 0.0, 0.0, ""},
        {3, 7, -6, 0, 0.0, 0.0, ""}
    };

    for (int i = 0; i < 2; i++) {
        arreglo[i].d = (arreglo[i].b * arreglo[i].b) - (4 * arreglo[i].a * arreglo[i].c);

        if (arreglo[i].d < 0) {
            strcpy(arreglo[i].solucion, "NO TIENE SOLUCIÓN");
        } else {
            float valx1 = ((-1) * arreglo[i].b + sqrt(arreglo[i].d)) / (2.0 * arreglo[i].a);
            float valx2 = ((-1) * arreglo[i].b - sqrt(arreglo[i].d)) / (2.0 * arreglo[i].a);
            strcpy(arreglo[i].solucion, "Tiene solución");
            arreglo[i].x1 = valx1;
            arreglo[i].x2 = valx2;
        }
    }

    printf("%-3s | %-3s | %-3s | %-8s | %-8s | %-20s\n", "a", "b", "c", "x1", "x2", "solucion");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < 2; i++) {
        printf("%-3d | %-3d | %-3d | %-8.2f | %-8.2f | %-20s\n", 
            arreglo[i].a, 
            arreglo[i].b, 
            arreglo[i].c, 
            arreglo[i].x1, 
            arreglo[i].x2, 
            arreglo[i].solucion);
    }

    return 0;
}
