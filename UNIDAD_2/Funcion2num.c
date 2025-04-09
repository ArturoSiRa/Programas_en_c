#include <stdio.h> 

void datos(int a, int b) {
    if (a > b ) {
        printf("a es el mayor\n");
    } else if (b > a) {
        printf("b es el mayor\n");
}
}
int main (){
    int a, b;
    printf("Dame el valor de a");
    scanf("%d", &a);
    printf("Dame el valor de b");
    scanf("%d", &b);
    datos (a, b);
    return 0;



}