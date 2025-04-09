#include <stdio.h>

    int main() {
    float a;
    float b;
    float c2;
    char op;
    
    printf("Ingresa un numero: \n");
    scanf("%f", &a);
    printf("Ingresa el operador (+,-,*,/): \n");
    scanf(" %c", &op);
    printf("Ingresa otro numero: \n");
    scanf("%f",&b);
    switch(op) {
        case'+':
        c2 = a + b;
        printf("%.2f", c2);
        break;
        
        case'-':
        c2 = a - b;
        printf("%.2f", c2);
        break;
        
        case'*':
        c2 = a * b;
        printf("%.3f", c2);
        break;
        
        case'/':
        if(b != 0){
            c2 = a / b;
            printf("%.3f", c2);
            break;}
        else{
            printf("%s","No es posible");
        }
        default:
            printf("%s", "No ha seleccionado una opcion correcta");
            break;
    }
}