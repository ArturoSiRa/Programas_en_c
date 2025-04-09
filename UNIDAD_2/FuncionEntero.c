#include <stdio.h>

void numero(float a) {
    if (a > 0) {
        printf("Es un número positivo\n");
    } else if (a < 0) {
        printf("Es un número negativo\n");
    }
}
int main(){
    float a; 
    printf("Dame un numero");
    scanf ("%f", &a);
    numero(a);

}