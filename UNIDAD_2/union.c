/*
Una unión en C es similar a una estructura
pero todos los miembros comparten la misma ubicación en memoria

Esto significa que solo se puede almacenar un valor a la vez, 
o que sla hace útil para ahorra memoria cuando se necesita

Cada asignación sobreescribe el valor anterior
porque todos los datos comparten el mismo lugar en la memoria
*/
#include <stdio.h>
union Dato
{
    int entero;
    float decimal;
    char texto[20];
};

int main(){
    union Dato variable;

    variable.entero = 42;
    printf("Entero: %d\n", variable.entero);

    variable.decimal = 3.14;
    printf("Decimal: %d\n", variable.decimal);

    sprintf(variable.texto, "Hola C");
    printf("Texto: %d\n", variable.texto);

    printf("\nDespués de asignar un texto: \n");
    printf("Entero: %d\n", variable.entero);
    printf("Decimal: %d\n", variable.decimal);
    printf("Texto: %d\n", variable.texto);

    return 0;
}