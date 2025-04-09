#include <stdio.h>
#include <math.h>

// Estructura para almacenar coordenadas
struct Coordenadas {
    int x;
    int y;
};

int main() {
    char opcion;
    struct Coordenadas coord[4];
    float lados[4];
    float perimetro = 0, area = 0;
    
    printf("\nMenú:\n");
    printf("1) Calcular cuadrado\n");
    printf("2) Calcular triángulo\n");
    printf("3) Salir\n");
    printf("Seleccione una opción: ");
    scanf(" %c", &opcion);
    
    switch (opcion) {
        case '1':
            printf("\nIngresa las coordenadas del cuadrado:\n");
            for (int i = 0; i < 4; i++) {
                printf("Punto %d - x: ", i + 1);
                scanf("%d", &coord[i].x);
                printf("Punto %d - y: ", i + 1);
                scanf("%d", &coord[i].y);
            }
            
            for (int i = 0; i < 4; i++) {
                lados[i] = sqrt(pow(coord[(i + 1) % 4].x - coord[i].x, 2) + pow(coord[(i + 1) % 4].y - coord[i].y, 2));
                perimetro += lados[i];
            }
            area = lados[0] * lados[1];
            break;
        
        case '2':
            printf("\nIngresa las coordenadas del triángulo:\n");
            for (int i = 0; i < 3; i++) {
                printf("Punto %d - x: ", i + 1);
                scanf("%d", &coord[i].x);
                printf("Punto %d - y: ", i + 1);
                scanf("%d", &coord[i].y);
            }
            
            for (int i = 0; i < 3; i++) {
                lados[i] = sqrt(pow(coord[(i + 1) % 3].x - coord[i].x, 2) + pow(coord[(i + 1) % 3].y - coord[i].y, 2));
                perimetro += lados[i];
            }
            
            float s = perimetro / 2; 
            area = sqrt(s * (s - lados[0]) * (s - lados[1]) * (s - lados[2]));
            break;
        
        case '3':
            printf("\nSaliendo del programa...\n");
            return 0;
        
        default:
            printf("\nOpción inválida.\n");
            return 0;
    }
    
    printf("\nPerímetro: %.2f", perimetro);
    printf("\nÁrea: %.2f\n", area);
    
    return 0;
}
