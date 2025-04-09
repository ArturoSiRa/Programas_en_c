#include <stdio.h>
#define COLUMNAS 6
#define FILAS 6
int main(){
    int matriz[FILAS] [COLUMNAS] = {
        {5, 9, 2, 3, 6, 8},
        {1, 7, 9, 6, 2, 0},
        {4, 6, 5, 3, 7, 1},
        {5, 9, 2, 3, 6, 8},
        {1, 7, 9, 6, 2, 0},
        {4, 6, 5, 3, 7, 1}
    };

    printf("Recorriendo la matriz: \n");
    printf("\n  %-6s |  %-6s |  %-6s |  %-6s |  %-6s |  %-6s |\n", "UNO", "DOS", "TRES", "CUATRO", "CINCO", "SEIS");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (j%2 == 0)
            {
                printf("    %-4d |", matriz[i][j]);
            }
            else{
                printf ("    #    |");
            }
            
        }
        printf("\n");
    }
    return 0;
}