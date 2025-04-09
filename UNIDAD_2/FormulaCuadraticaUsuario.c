#include <stdio.h>  //Libreria base
#include <math.h>   //Libreria para operaciones matematicas complejas
#include <string.h> //Libreria para alterar strings

struct Eccuadratica { //se crea la estructura con los datos necesarios para la ecuación
    int a; //El valor de la incógnita al cuadrado
    int b; //El valor de la incógnita
    int c; //El valor entero
    int d; //El discriminante
    float x1;  //Valor final de x1
    float x2;  //Valor final de x2
    char solucion[30];  //Imprime si tiene o no solucion
};

int main() {
    int size; //Se define la variable de cantidad de ecuaciones
    printf("Ingrese la cantidad de ecuaciones a realizar: \n");
    scanf("%d", &size);//Se guarda el numero de ecuaciones

    struct Eccuadratica arreglo[size]; //Se define el arreglo de estructuras segun el tamaño dado
        
    for (int i = 0; i < size; i++)  //Se crea un bucle for para ingresar lo datos según el número de ecuaciones
    {
        printf("\nIngrese los datos de la ecuacion [%d] \n", i+1);

        printf("Ingrese a: ");
        scanf("%d", &arreglo[i].a); //Se registra el valor de a
   
        printf("Ingrese b: ");
        scanf("%d", &arreglo[i].b); //Se registra el valor de b

        printf("Ingrese c: ");
        scanf("%d", &arreglo[i].c); //Se registra el valor de c

        arreglo[i].d = 0; //Se definen los demás valores en cero hasta que se modifiquen
        arreglo[i].x1 = 0.0;
        arreglo[i].x2 = 0.0;
    };

    for (int i = 0; i < size; i++) { //Se crea un ciclo for para resolver las ecuaiones
        arreglo[i].d = (arreglo[i].b * arreglo[i].b) - (4 * arreglo[i].a * arreglo[i].c);
        //Se realiza la operación del discriminante y se almacena

        if (arreglo[i].d < 0) { 
            strcpy(arreglo[i].solucion, "NO TIENE SOLUCIÓN");   
            //Se crea una condición, si el discriminante es menor a cero, entonces se imprime no tiene solución
        } else {//De no cumplirse la condición se realiza la otra acción y se calculan las incógnitas
            float valx1 = ((-1) * arreglo[i].b + sqrt(arreglo[i].d)) / (2.0 * arreglo[i].a);
            //Se hace la operación para x1 y se almacena en variables locales
            float valx2 = ((-1) * arreglo[i].b - sqrt(arreglo[i].d)) / (2.0 * arreglo[i].a);
            //Se hace la operación para x2 y se almacena en variables locales
            strcpy(arreglo[i].solucion, "TIENE SOLUCIÓN");
            //Se altera la variable solución y ahora vale Tiene solución
            arreglo[i].x1 = valx1;  //Se altera la variable global de x1 y asume el valor de valx1
            arreglo[i].x2 = valx2;  //Se altera la variable global de x2 y asume el valor de valx2
            
        }
    }

    printf("%s  |  %s  |  %s  |  %s  |  %s  |  %s\n", "a", "b", "c", "x1", "x2", "solucion");
    //Se imprime un pequeño menú que permitirá ver que valores se asignarán
    printf("\n");

    for (int i = 0; i < size; i++) { //Se crea un bucle for en el que se van a imprimir los valores finales de cada ecuación
        printf("%d  |  %d  |  %d  |  %.3f  |  %.3f  |  %s\n", 
            arreglo[i].a, 
            arreglo[i].b, 
            arreglo[i].c, 
            arreglo[i].x1, 
            arreglo[i].x2, 
            arreglo[i].solucion); //Se imprimen todas las variables
    }

    return 0;
}
