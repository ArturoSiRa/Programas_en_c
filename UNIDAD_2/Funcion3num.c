#include <stdio.h> 

void datos(int a, int b, int c) {
    if (a > b && a > c) {
        printf("a es el mayor\n");
    } else if (b > a && b > c) {
        printf("b es el mayor\n");
    } else if (c > a && c > b) {
        printf("c es el mayor\n");
    }
}
int main (){
    int a, b, c;
    printf("Dame el valor de a");
    scanf("%d", &a);
    printf("Dame el valor de b");
    scanf("%d", &b);
    printf("Dame el valor de c");
    scanf("%d", &c);
    datos (a, b, c);
    return 0;



}