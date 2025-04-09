#include <stdio.h>
struct Datos
{
    char nombre [50];
    char correo [50];
    char matricula [9];
    char carrera [50];
    char asesor [50];
    char coord [50];
    char semestre [10];
    char promedio [4];
};
int main(){
    int size;
    printf("ingrese la cantidad de personas a registrar: \n");
    scanf("%d", &size);

    struct Datos dato1[size];

    for (int i = 0; i < size; i++)
    {
        printf("\nIngrese los datos de la persona [%d] \n", i+1);

        printf("Ingrese su nombre: ");
        scanf("%s", dato1[i].nombre);
   
        printf("Ingrese su correo: ");
        scanf("%s", dato1[i].correo);

        printf("Ingrese su matricula: ");
        scanf("%s", dato1[i].matricula);
   
        printf("Ingrese su carrera: ");
        scanf("%s", dato1[i].carrera);
        
        printf("Ingrese su asesor: ");
        scanf("%s", dato1[i].asesor);
   
        printf("Ingrese su coordinador: ");
        scanf("%s", dato1[i].coord);

        printf("Ingrese su semestre: ");
        scanf("%s", dato1[i].semestre);
   
        printf("Ingrese su promedio: ");
        scanf("%s", dato1[i].promedio);

    }

    for (int i = 0; i < size; i++){
        printf("\nDatos persona: %d\n", i+1);
        printf("Nombre: %s\n", dato1[i].nombre);
        printf("Correo: %s\n", dato1[i].correo);
        printf("Matricula: %s\n", dato1[i].matricula);
        printf("Carrera: %s\n", dato1[i].carrera);
        printf("Asesor: %s\n", dato1[i].asesor);
        printf("Coordinador: %s\n", dato1[i].coord);
        printf("Semestre: %s\n", dato1[i].semestre);
        printf("Promedio: %s\n", dato1[i].promedio);
    }
}
