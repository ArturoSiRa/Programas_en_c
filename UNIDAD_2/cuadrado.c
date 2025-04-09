#include <stdio.h>
void setColor(int col) {
    printf("\033[7;%dm", col); 
}

int main() {
    printf("\033[2J"); 
    int area;
    printf("Ingrese un lado del cuadrado: ");
    scanf("%d", &area);

    int colores[] = {31, 32, 33, 34, 35, 36, 37};
    int numc = 7;

    for (int i = 0; i < area; i++) {      
        for (int j = 0; j < area; j++) { 
            int col = colores[(i + j) % numc]; 
            setColor(col);
            printf("  "); 
            printf("\033[0m"); 
        }
        printf("\n");
    }
    return 0;
}