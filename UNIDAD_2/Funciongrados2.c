# include<stdio.h>
float ck(float c) {  
    return c + 273.15;
}
int main (){
    float resultado, c;
    printf("Dame el valor en Celsius: ");
    scanf("%f", &c);
    resultado = ck(c);
    printf("Equivalencia en Kelvin = %.2f\n", resultado);
    
    return 0;  
}
