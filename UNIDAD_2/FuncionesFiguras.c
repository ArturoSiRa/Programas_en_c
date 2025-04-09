#include <stdio.h>
#define pi 3.1416
float circ(float r){
    float area = pi * r * r;
    return area;
}
float rect(float a, float b){
    float area = a*b;
    return area;
}
float cuad(float a){
    float area = a * a;
    return area;
}
float trig(float a, float b){
    float area = 0.5*a*b;
    return area;
}
float trap(float a, float b, float c){
    float area = (1/2)*(a+b)*c;
    return area;
}
float esfera(float r){
    float vol =  (4.0 / 3.0) * pi * r * r * r; 
    return vol;
}
float cubo(float a){
    float vol = a * a * a; 
    return vol;
}
float prisma(float a, float b, float h){ 
    float vol = a * b * h; 
    return vol;
}
float cil(float r, float h){ 
    float vol = pi * r * r * h; 
    return vol;
}
float cono(float r, float h){ 
    float vol = (1.0 / 3.0) * pi * r * r * h; 
    return vol;
}

typedef struct {
    char figuno [50];
    float area;
} Dosd;

typedef struct {
    char figdos [50];
    float volum;
} Tresd;

typedef union {
    Dosd dos;
    Tresd tres;
} Tipo;

int main(){
    Tipo tipos[10];
    char opc;
    printf("Elige una opción: ");
    printf("\nMenú de Opciones:\n");
    printf("a - Calcular el área de un círculo\n");
    printf("b - Calcular el área de un rectángulo\n");
    printf("c - Calcular el área de un cuadrado\n");
    printf("d - Calcular el área de un triángulo\n");
    printf("e - Calcular el área de un trapecio\n");
    printf("f - Calcular el volumen de una esfera\n");
    printf("g - Calcular el volumen de un cubo\n");
    printf("h - Calcular el volumen de un prisma rectangular\n");
    printf("i - Calcular el volumen de un cilindro\n");
    printf("j - Calcular el volumen de un cono\n");
    scanf("%c", &opc);

    float a1, a2, a3, rad;
    switch (opc)
    {
    case 'a':
        printf("Ingresa el valor del radio: ");
        scanf("%f", &rad);
        printf("EL área es: %.2f", circ(rad));
        break;
    
    case 'b':
        printf("Ingresa el valor del primer lado: ");
        scanf("%f", &a1);
        printf("Ingresa el valor del segundo lado: ");
        scanf("%f", &a2);
        printf("EL área es: %.2f", rect(a1,a2));
        break;

    case 'c':
        printf("Ingresa el valor del lado: ");
        scanf("%f", &a1);
        printf("EL área es: %.2f", cuad(a1));
        break;

    case 'd':
        printf("Ingresa el valor de la base: ");
        scanf("%f", &a1);
        printf("Ingresa el valor de la altura ");
        scanf("%f", &a2);
        printf("EL área es: %.2f", rect(a1,a2));
        break;

    case 'e':
        printf("Ingresa el valor de la base mayor: ");
        scanf("%f", &a1);
        printf("Ingresa el valor de la base menor: ");
        scanf("%f", &a2);
        printf("Ingresa el valor de la altura: ");
        scanf("%f", &a3);
        printf("EL área es: %.2f", trap(a1,a2,a3));
        break;

    case 'f':
        printf("Ingresa el radio de la esfera: ");
        scanf("%f", &rad);
        printf("El volumen es: %.2f\n", esfera(rad));
        break;

    case 'g':
        printf("Ingresa el lado: ");
        scanf("%f", &a1);
        printf("El volumen del cubo es: %.2f\n", cubo(a1));
        break;

    case 'h':
        printf("Ingresa el valor del ancho: ");
        scanf("%f", &a1);
        printf("Ingresa el valor del largo: ");
        scanf("%f", &a2);
        printf("Ingresa el valor de la altura: ");
        scanf("%f", &a3);
        printf("El volumen del prisma rectangular es: %.2f\n", prisma(a1, a2, a3));
        break;

    case 'i':
        printf("Ingresa el radio del cilindro: ");
        scanf("%f", &rad);
        printf("Ingresa la altura: ");
        scanf("%f", &a1);
        printf("El volumen es: %.2f\n", cil(rad, a1));
        break;

    case 'j':
        printf("Ingresa el radio del cono: ");
        scanf("%f", &rad);
        printf("Ingresa la altura: ");
        scanf("%f", &a1);
        printf("El volumen es: %.2f\n", cono(rad, a1));
        break;

    default:
        printf("Ingrese una opción válida");
        break;
    }

}