#include <stdio.h>
#include <math.h>
struct Coordenada
{
    int x;
    int y;
};
int main(){
    int opc;
    printf("%s\n", "Selecciona una operación");
    printf("%s\n", ",1. Cuadrado");
    printf("%s\n", ",2. Triangulo");
    scanf("%d", &opc);
    struct Coordenada arreglo[4];
    switch (opc)
    {
    case 1:

        for (int i = 0; i < 4; i++)
        {
            printf("Ingrese x: ");
            scanf("%d", &arreglo[i].x);
            printf("Ingrese y: ");
            scanf("%d", &arreglo[i].y);
        }
        
        float ab = sqrt(pow(arreglo[1].x - arreglo[0].x, 2) - pow(arreglo[1].y - arreglo[0].y, 2));
        float bc = sqrt(pow(arreglo[2].x - arreglo[1].x, 2) - pow(arreglo[2].y - arreglo[1].y, 2));
        float cd = sqrt(pow(arreglo[3].x - arreglo[2].x, 2) - pow(arreglo[3].y - arreglo[2].y, 2));
        float ad = sqrt(pow(arreglo[0].x - arreglo[3].x, 2) - pow(arreglo[0].y - arreglo[3].y, 2));

        float perimetro = ab + bc + cd +ad;
        float area = cd * ad;
        printf("%s%d\n", "Perimetro total: ", perimetro);
        printf("%s%d\n", "Area total: ", area);
        break;
    
    default:
        break;
    }
}