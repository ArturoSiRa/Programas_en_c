#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gotoxy(int y, int x) {
    printf("\033[%d;%dH", y, x);
}

void setColor(const char* color) {
    printf("%s", color);
}

void limpiarPantalla() {
    printf("\033[2J");
}

#define MAX 1024

int main(){
    FILE *file;
    char archivo[MAX];
    char nombre[MAX];
    int edad;
    char pais[MAX];
    int cantidad, i;
    char base[] = "../";
    char ruta[200];

    limpiarPantalla();
    gotoxy(20, 10);
    setColor("\033[7;34m");
    printf("Ingrese el nombre del archivo: ");
    gotoxy(20, 45);
    setColor("\033[7;35m");
    scanf("%s", archivo);

    strcpy(ruta, base);
    strcat(ruta, archivo);

    limpiarPantalla();

    file = fopen(ruta, "w");
    if (file == NULL) {
        perror("error al abrir el archivo");
        return 1;
    }

    fprintf(file, "nombre,edad,pais\n");

    limpiarPantalla();
    gotoxy(20, 10);
    setColor("\033[7;34m");
    printf("¿Cuántas personas quieres registrar? ");
    gotoxy(20, 50);
    setColor("\033[7;35m");
    scanf("%d", &cantidad);
    getchar();
    limpiarPantalla();

    for (i = 0; i < cantidad; i++) {
        limpiarPantalla();
        gotoxy(18, 25);
        setColor("\033[7;33m");
        printf("\nPersona %d\n", i + 1);

        gotoxy(21, 25);
        setColor("\033[7;37m");
        printf("nombre: ");
        gotoxy(21, 35);
        setColor("\033[7;32m");
        fgets(nombre, MAX, stdin);
        nombre[strcspn(nombre, "\n")] = 0;

        gotoxy(22, 25);
        setColor("\033[7;37m");
        printf("edad: ");
        gotoxy(22, 35);
        setColor("\033[7;32m");
        scanf("%d", &edad);
        getchar();

        gotoxy(23, 25);
        setColor("\033[7;37m");
        printf("pais: ");
        gotoxy(23, 35);
        setColor("\033[7;32m");
        fgets(pais, MAX, stdin);
        pais[strcspn(pais, "\n")] = 0;
        setColor("\033[0m");
        fprintf(file, "%s,%d,%s\n", nombre, edad, pais);
    }

    // Cerrar el archivo
    fclose(file);
    limpiarPantalla();
    // Imprimir tabla
    setColor("\033[7;37m");
    printf("\nDatos registrados:\n");
    setColor("\033[0m");
    printf("------------------------------------------------------------------------------\n");
    setColor("\033[7;31m");
    printf("*   Nombre                                 |   Edad    |      País       *\n");
    setColor("\033[0m");
    printf("------------------------------------------------------------------------------\n");

    file = fopen(ruta, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }

    char line[MAX];
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ",");
        if (token != NULL) printf("* %-40s | ", token);

        token = strtok(NULL, ",");
        if (token != NULL) printf("%-8s | ", token);

        token = strtok(NULL, ",");
        if (token != NULL) printf("%-15s *\n", token);
    }
    printf("--------------------------------------------------------------------------\n");

    fclose(file);

    return 0;
}
