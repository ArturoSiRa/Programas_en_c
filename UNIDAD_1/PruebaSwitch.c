#include <stdio.h>
int main(){
    int opc;
    printf("%s", "Seleccione una opción");
    printf("%s", "1 - sumar");
    printf("%s", "2 - restar");
    scanf("%d", opc);
    switch (opc)
    {
        case 1:
            printf("%s", "Ha seleccionado suma");
            break;
        case 2:
            printf("%s", "Ha seleccionado resta");
            break;
        default:
            printf("%s", "No ha seleccionado una opción válida");
            break;
    }
}