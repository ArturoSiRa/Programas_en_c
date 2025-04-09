#include <stdio.h>
void seriedenum(int inicio, int fin) {
    int suma = 0;  
    for (int i = inicio; i <= fin; i++) {
        suma += i;  
    }
    printf("La suma de los números en el  intervalo es: %d", suma);
}

int main() {
    int inicio, fin;
    printf("Ingrese el numero inicial del intervalo: ");
    scanf("%d", &inicio);
    printf("Ingrese el numero final del intervalo: ");
    scanf("%d", &fin);
    seriedenum(inicio, fin);

    return 0;
}
