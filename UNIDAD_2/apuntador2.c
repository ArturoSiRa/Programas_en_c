#include <stdio.h>
int main(){
    int numero = 42;
    int *apuntador = &numero;

    printf("Valor de número %d\n", numero);
    printf("Dirección de número %p\n", &numero); //recupera la posición
    printf("Dirección del apuntador %p\n", apuntador); //el valor de la posición
    printf("Dirección al que apunta %d\n", *apuntador); //valor que es apuntado
    return 0; 
}