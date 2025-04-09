#include <stdio.h>
int main(){
    //barco
    for (int i = 1; i <= 3; i++) {
        printf("   ");
        for (int j = 1; j <= 3 - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
    int espacio2 = 0;
    int asterisco2 = 9;
    for (int i3 = 3; i3 >= 0; i3--)
    {    
        for (int j3 = 1; j3 <= espacio2; j3++)
        {
            printf("%s", " ");
        }
        espacio2++;
        for (int k3 = -1; k3 <= asterisco2; k3++)
        {
            printf("%s", "*");
        }
        asterisco2-=2;
        printf("\n");
    }


    
    int espacio = 2;
    int asterisco = 7;
    for (int i2 = 2; i2 >= 0; i2--)
    {    
        for (int j2 = 1; j2 <= espacio; j2++)
        {
            printf("%s", " ");
        }
        espacio--;
        for (int k2 = 1; k2 <= asterisco; k2++)
        {
            printf("%s", "*");
        }
        asterisco+=2;
        printf("\n");
    }
    printf("\n\n");
}