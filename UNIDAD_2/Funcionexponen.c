#include <stdio.h>
int exponenciales(int base, int exponente) {
    int resultado = 1;  
    for (int i = 1; i <= exponente; i++) {
        resultado *= base; 
    }
    return resultado;
}

int main() {
    int base, exponente;
    printf("Ingrese la base: ");
    scanf("%d", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    int resultado = exponenciales(base, exponente);
    
    printf("Resultado: %d", resultado);

    return 0;
}
