#include <stdio.h>
long sumaenteros(int num){
if (num == 1) return 1;
else
    return num + sumaenteros(num -1);
}


int main(){
    printf("Ingresa un número a sumar: ");
    int n;
    scanf("%d", &n);
    printf("La suma de los números enteros hasta %d es: %ld\n", n, sumaenteros(n));
}