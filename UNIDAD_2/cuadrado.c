#include <stdio.h>
//\033[ estilo ; color m
/*
Código	Color
30	    Negro
31	    Rojo
32	    Verde
33	    Amarillo
34	    Azul
35	    Magenta
36	    Cyan
37	    Blanco*/
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