#include <stdio.h>
float fc(float f) {  
    return (f - 32) / 1.8;
}
int main (){
    float resultado, f;
    printf("Dame el valor en Fahrenheit: ");
    scanf("%f", &f);
    resultado = fc(f);
    printf("Equivalencia en Celsius = %.2f\n", resultado);
    
    return 0;  
}
