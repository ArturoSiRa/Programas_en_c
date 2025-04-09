#include <stdio.h>
#define COLUMNAS 3
#define FILAS 3
int main(){
    int num = 1;
    char matriz[FILAS][COLUMNAS][20];
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("Ingresa palabra [%d]: \n", num);
            scanf("%s", &matriz[i][j]);
            num ++;
        } 
        
    }

    printf("Recorriendo la matriz: \n");
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("\t%s\t|", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}