#include <stdio.h> //Iniciamos con la librería

int main() { //Metodo principal
    int fno, sno, *ptr, *qtr, suma,*sum, resta, *rest, multipli, *multi, division, *div;  //declaro variables y los punteros que les puse un nombre casi similar a las variabales
    printf("\n\nOperaciones con punteros: \n\n"); //Imprimo lo que hace mi programa
    printf("-------------------------------\n"); //Pongo una línea para separar

    printf("Ingresa el primer número:");   //Pido mi primer numero
    scanf("%d", &fno); //escaneo el valor de mi primer numero en la variable fno

    printf("Ingresa el segundo número:");  //Pido mi segundo numero
    scanf("%d", &sno); //escaneo el valor de mi primer numero en la variable sno

    ptr = &fno;    //Recojo la posición de la variable fno y se la asigno  mi puntero ptr 
    qtr = &sno;      //Recojo la posición de la variable sno y se la asigno  mi puntero qtr 
    printf("\n\nPointer 1: %p", ptr);     //Imprimo el valor donde esta mi  primer puntero
    printf("\n\nPointer 2: %p", qtr);  //Imprimo el valor donde esta mi segundo pontero

    suma =  *ptr  +  *qtr;        //Hago la suma con los valores de los numros que previamente hice, ayudandome del puntero
    resta= *ptr  -  *qtr;          //Hago la resta con los valores de los numros que previamente hice, ayudandome del puntero
    multipli =  *ptr  *  *qtr;       //Hago la multiplicacion con los valores de los numros que previamente hice, ayudandome del puntero
    division =  *ptr /  *qtr;        //Hago la división con los valores de los numros que previamente hice, ayudandome del puntero

    sum=&suma;        //Recupero la posición donde se guardó el valor de mi suma y le asigno el puntero sum
    rest=&resta;        //Recupero la posición donde se guardó el valor de mi resta y le asigno el puntero rest
    multi=&multipli;    //Recupero la posición donde se guardó el valor de mi multipli y le asigno el puntero multi
    div=&division;      ////Recupero la posición donde se guardó el valor de mi division y le asigno el puntero div


    
    printf("\n\nLa suma  de los números es: %d\n", suma);  //Imprimo el resultado de la suma 
    printf("\n\nLa resta  de los números es: %d\n", resta);  //Imprimo el resultado de la resta 
    printf("\n\nLa multiplicacion  de los números es: %d\n", multipli);    //Imprimo el resultado de la multiplicacion 
    printf("\n\nLa división  de los números es: %d\n", division);     //Imprimo el resultado de la division 

    printf("\n\nPointer de suma: %p", sum);      //Imprimo el apuntador es decir la posicion donde se guardó el resultado de la suma
    printf("\n\nPointer de resta: %p", rest);         //Imprimo el apuntador es decir la posicion donde se guardó el resultado de la resta
    printf("\n\nPointer de multiplicacion: %p", multi);  //Imprimo el apuntador es decir la posicion donde se guardó el resultado de la multiplicación
    printf("\n\nPointer de division: %p", div);    //Imprimo el apuntador es decir la posicion donde se guardó el resultado de la division

    


    return 0;        //para que el código no quiebre
}