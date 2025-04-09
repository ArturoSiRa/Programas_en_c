#include <stdio.h>
#include <math.h>

typedef struct {
    int num;
    int den; 
} Fraccion;

int mcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraccion simplificar(Fraccion f) {
    int divisor = mcd(abs(f.num), abs(f.den));
    if (divisor != 0) {
        f.num /= divisor;
        f.den /= divisor;
    }

    if (f.den < 0) {
        f.num *= -1;
        f.den *= -1;
    }
    return f;
}

void resolverEcuacionCuadratica(Fraccion a, Fraccion b, Fraccion c) {
    // Convertir fracciones a float
    float a_f = (a.den == 0) ? 0 : (float)a.num / a.den;
    float b_f = (b.den == 0) ? 0 : (float)b.num / b.den;
    float c_f = (c.den == 0) ? 0 : (float)c.num / c.den;

    // Verificar si es cuadrática
    if (a_f == 0) {
        printf("\nError: El coeficiente 'a' no puede ser cero en una ecuación cuadrática.\n");
        return;
    }

    // Calcular discriminante
    float discriminante = b_f * b_f - 4 * a_f * c_f;

    // Mostrar ecuación formateada
    printf("\nEcuación: ");
    if(a.num < 0) printf("-");
    if(abs(a.den) != 1) printf("(%d/%d)", abs(a.num), abs(a.den));
    else printf("%d", abs(a.num));
    printf("x² ");

    if(b.num >= 0) printf("+ "); else printf("- ");
    if(abs(b.den) != 1) printf("(%d/%d)", abs(b.num), abs(b.den));
    else printf("%d", abs(b.num));
    printf("x ");

    if(c.num >= 0) printf("+ "); else printf("- ");
    if(abs(c.den) != 1) printf("(%d/%d)", abs(c.num), abs(c.den));
    else printf("%d", abs(c.num));
    printf(" = 0\n");

    printf("Discriminante: ");
    if(discriminante == (int)discriminante) 
        printf("%.0f\n", discriminante);
    else
        printf("%.2f\n", discriminante);

    // Evaluar soluciones
    if (discriminante < 0) {
        printf("No hay soluciones reales (el discriminante es negativo)\n");
    } 
    else if (discriminante == 0) {
        float x = -b_f / (2 * a_f);
        printf("Solución única: x = ");
        if(x == (int)x) printf("%.0f\n", x);
        else printf("%.2f\n", x);
    }
    else {
        float x1 = (-b_f + sqrtf(discriminante)) / (2 * a_f);
        float x2 = (-b_f - sqrtf(discriminante)) / (2 * a_f);
        printf("Dos soluciones reales:\n");
        
        printf("x₁ = ");
        if(x1 == (int)x1) printf("%.0f\n", x1);
        else printf("%.2f\n", x1);
        
        printf("x₂ = ");
        if(x2 == (int)x2) printf("%.0f\n", x2);
        else printf("%.2f\n", x2);
    }
}

int main() {
    printf("RESOLVEDOR DE ECUACIONES CUADRÁTICAS\n");
    printf("Formato: ax² + bx + c = 0\n\n");

    Fraccion a, b, c;

    // Solicitar coeficientes
    printf("Ingrese el coeficiente a (como fracción a/b): ");
    scanf("%d/%d", &a.num, &a.den);
    a = simplificar(a);

    printf("Ingrese el coeficiente b (como fracción a/b): ");
    scanf("%d/%d", &b.num, &b.den);
    b = simplificar(b);

    printf("Ingrese el coeficiente c (como fracción a/b): ");
    scanf("%d/%d", &c.num, &c.den);
    c = simplificar(c);

    // Resolver la ecuación
    resolverEcuacionCuadratica(a, b, c);

    return 0;
}