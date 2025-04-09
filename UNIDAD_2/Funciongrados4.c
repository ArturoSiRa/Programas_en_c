#include <stdio.h>
float kf(float k) {  
    return ((k - 273.15) * 1.8) + 32;
}
int main (){
    float resultado, k;
    printf("Dame el valor en Kelvin: ");
    scanf("%f", &k);
    resultado = kf(k);
    printf("Equivalencia en Fahrenheit = %.2f\n", resultado);
    
    return 0;  
}
