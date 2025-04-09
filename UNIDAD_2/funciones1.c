#include <stdio.h>
int suma(int a, int b){
    return a+b;
}
int resta(int a, int b){
    int result = a-b;
    return result;
}
int mult(int a){
    return a*a;
}
float div(int a, int b){
    return a/b;
}
void imprimir(int a, int b, int c, float d){
    printf("\nResultados:\nSuma: %d\nResta: %d\nMultiplicación: %d\nDivisión: %.2f", a, b, c, d);
}
int main(){
    int op1 = suma(3,2);
    int op2 = resta(5,3);
    int op3 = mult(3);
    float op4 = div(5,3);
    imprimir(op1, op2, op3, op4);
}