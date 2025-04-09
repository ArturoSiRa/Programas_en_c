#include <stdio.h>
struct Carac
{
    char marca[15];
    char estado[15];
    char color[20];
    int peso;
    int precio;
    char tipo[20]; //in ear/over ear
    char resistencia[20];
    char cancelacion[20];
    char comodidad[20];
    char garantia[20];
    char control[20];
};

struct Audifonos
{
    char conec[20];
    struct Carac uso;
};
int main(){
    int n;
    printf("Ingrese el numero de audifonos: ");
    scanf("%d", &n);
    getchar();   

    struct Audifonos tipos[n];
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese los datos de los audifonos %d:\n", i+1);

        printf("Tipo de conexión: ");
        scanf(" %s", tipos[i].conec);
        
        printf("Marca de los audifonos: ");
        scanf(" %s", tipos[i].uso.marca);

        printf("Estado (nuevo/usado): ");
        scanf(" %s", tipos[i].uso.estado);
        
        printf("Color: ");
        scanf(" %s", tipos[i].uso.color);

        printf("Peso: ");
        scanf(" %d", &tipos[i].uso.peso);

        printf("Precio: ");
        scanf(" %d", &tipos[i].uso.precio);

        printf("Tipo (in/over): ");
        scanf(" %s", tipos[i].uso.tipo);

        printf("Resistencia al polvo (si/no): ");
        scanf(" %s", tipos[i].uso.resistencia);
        
        printf("Cancelacion de ruido (si/no): ");
        scanf(" %s", tipos[i].uso.cancelacion);

        printf("Comodidad (buena/media/mala): ");
        scanf(" %s", tipos[i].uso.comodidad);
        
        printf("Garantia (si/no): ");
        scanf(" %s", tipos[i].uso.garantia);

        printf("Controles multimedia (si/no): ");
        scanf(" %s", tipos[i].uso.control);
        getchar();
    }
    printf("\n%-13s | %-7s | %-7s | %-7s | %-5s | %-5s | %-7s | %-10s | %-15s | %-10s | %-10s | %-9s\n", 
        "Conexión", "Marca", "Estado", "Color", "Peso", "Precio", "Tipo", "Resistente", "Cancelacion", "Comodidad", "Garantia", "Controles");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-13s | %-7s | %-7s | %-7s | %-5d | %-5d | %-7s | %-10s | %-15s | %-10s | %-10s | %-9s\n", 
            tipos[i].conec,
            tipos[i].uso.marca,
            tipos[i].uso.estado,
            tipos[i].uso.color,
            tipos[i].uso.peso,
            tipos[i].uso.precio,
            tipos[i].uso.tipo,
            tipos[i].uso.resistencia,
            tipos[i].uso.cancelacion,
            tipos[i].uso.comodidad,
            tipos[i].uso.garantia,
            tipos[i].uso.control
        );
    }
    
    return 0;
}