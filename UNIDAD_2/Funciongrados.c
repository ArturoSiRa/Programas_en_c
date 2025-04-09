#include <stdio.h>
float cf(float c) {  
    return (c * 1.8) + 32;
}
int main() {
    float resultado, c;
    printf("Dame el valor de Celsius: ");
    scanf("%f", &c);
    resultado = cf(c);
    printf("Equivalencia en Fahrenheit = %.2f\n", resultado);
    
    return 0;  
}
