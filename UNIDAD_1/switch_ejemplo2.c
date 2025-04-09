#include <stdio.h>
#include <math.h>
int main(){
    printf("%s", "Bienvenido al programa\nElige una opcion a-o\n");
    printf("%s", "A- Escapes\n");//
    printf("%s", "B- Tipos de Dato\n");//
    printf("%s", "C- Promedio de calificación\n");//
    printf("%s", "D- Temperatura Enteros\n");//
    printf("%s", "E- Temperatura Flotantes\n");//
    printf("%s", "F- Diagonales\n");//
    printf("%s", "G- Cuadro de números\n");
    printf("%s", "H- Cuadrado Asteriscos\n");//
    printf("%s", "I) Triangulo Rectangulo\n");//
    printf("%s", "J) Triangulo R inverso\n");
    printf("%s", "K) Triangulo Equilatero\n");
    printf("%s", "L) Trapecio\n");
    printf("%s", "M) Promedio leyendo datos\n");
    printf("%s", "N) Volumen esfera\n");//
    printf("%s", "O) Volumen cono\n");
    printf("%s", "P) Volumen cilindro\n");
    printf("%s", "Q) Prueba de switch\n");
    printf("%s", "R) Calculadora\n");
    char opc;
    printf("Ingrese una opción: \n");
    scanf("%c", &opc);
    switch (opc)
    {
    case 'a':{
            printf("\\n Salto de línea\n");
            printf("\\t Tabulador\n");
            printf("\\r Retorno de carro\n");
            printf("\\b Retroceso\n");
            printf("\\f Avance de página\n");
            printf("\\v Tabulación vertical\n");
            printf("\\\\ Imprimir Diagonal invertida\n");
            printf("\\?  Imprimir Signo de interrogacion\n");
            printf("\\\' Imprimir Comillas simples\n");
            printf("\\\" Imprimir Comillas dobles\n");
            printf("\\0 Caracter nulo\n");
            printf("\\000 Octal\n");
            printf("\\xhh Hexadecimal\n");}
            break;
        case 'b':{
        char letra = 'a';
        int entero = 4;  
        unsigned positivo = 6;
        short corto = 12;
        long largo = 486798712;
        long long muylargo = 1234567890987654321;
        float decimalcorto = 3.14;
        double decimallargo = 3.141592653589793;
        char nombre[20] = "Arturo Silva";
        printf("Caracter: %c\n", letra);
        printf("Entero: %d\n", entero);
        printf("Entero positivo: %u\n", positivo);
        printf("Entero corto: %hd\n", corto);
        printf("Entero largo: %ld\n", largo);
        printf("Entero muy largo: %lld\n", muylargo);
        printf("Decimal: %.2f\n", decimalcorto);
        printf("Decimal largo: %.15lf\n", decimallargo);
        printf("Imprimir el nombre: %c\n", nombre);
}
        break;
        case 'c':{
            int calif1,calif2,calif3;
            float promedio;
            calif1=6;
            calif2=8;
            calif3=10;
            printf("%s\n","calificacion 1:");
            printf("%d\n",calif1);
            printf("%s\n","calificacion 2:");
            printf("%d\n",calif2);
            printf("%s\n","calificacion 3:");
            printf("%d\n",calif3);
            promedio=(calif1+calif2+calif3)/3;
            printf("%s","tu promedio es:");
            printf("%2.0f\n",promedio);}
        break;

        case 'd':{
            int fahr, celsius;
            int lower, upper, step; 
            lower=0; 
            upper=300;
            step=20;
            fahr=lower;
            while (fahr<=upper){ 
                celsius= 5 * (fahr-32)/9; 
                printf("%d\t%d\n",fahr,celsius);
                fahr= fahr + step; 
            }
        break;
        case 'e':{
            float farh, celsius;
            int lower, upper, step;
            
            lower =0;
            upper = 300;
            step = 20;
        
            farh = lower;
            while (farh <= upper)
            {
                celsius = 5 * (farh - 32) /9;
                printf("%3.0f%6.1f\n", farh, celsius);
                farh = farh + step;
            }}
        break;
        case'f':
            #define SIZE 10 
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (i == j) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\nDiagonal inversa:\n");
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (i + j == SIZE - 1) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        break;

        case 'g':
            int contador = 0;
            int limite = 10;
        
            printf("%4s\n", "EJEMPLO DE IMPRESIÓN");
            while (contador <= limite)
            {
                printf("%4d", contador);
                contador ++;
            }
            
            printf("\n%s\n", "EJEMPLO DE IMPRESIÓN");
        
            int limitey = 10;
            while (limitey >= 0)
            {
                int limitex = 10;
                while (limitex >= 0)
                {
                    printf("%4d", limitex);
                    limitex--;
                }
                printf("\n");
                limitey--;
        
            }
            printf("\n");
            int limitey2 = 0;
            while (limitey2 <= 10)
            {
                int limitex2 = 0;
                while (limitex2 <= 10)
                {
                    printf("%4d", limitex2);
                    limitex2++;
                }
                printf("\n");
                limitey2++;
        
            }
        
            int tabla = 0;
            while (tabla <= 10)
            {
                int numero = 0;
                while (numero <=10 )
                {
                    int mult = numero * tabla;
                    printf("%s%d%s%d%s%d\n", "(", tabla, ")(", numero, ")=", mult);
                    numero++;
                }
                
            }
        break;
        case 'h':
        {
            for (int i = 0; i <= 10; i++) {
                for (int j = 0; j <= 10; j++) {
                    printf("%4s", "*");
                }
                printf("\n");
            }}
        break;
        case 'i': {
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }}
        break;
        case 'j': {
            for (int i = 6; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }}
        break;

        case 'k': {
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= 6 - i; j++) {
                    printf(" ");
                }
                for (int k = 1; k <= 2 * i - 1; k++) {
                    printf("*");
                }
                printf("\n");
            }}
        break;
        case 'l': {
            for (int i = 1; i <= 6; i++) {
                for (int j = 1; j <= 6 - i; j++) {
                    printf(" ");
                }
                for (int k = 1; k <= 2 * i - 1; k++) {
                    printf("*");
                }
                printf("\n");
            }}
        break;
        case 'm':{
        char nombre[50];
            printf("Ingrese su nombre: ");
            scanf("%s", nombre);
            
            int calf1, calf2, calf3;
            printf("Ingrese calf1: ");
            scanf("%d", &calf1);
            printf("Ingrese calf2: ");
            scanf("%d", &calf2);
            printf("Ingrese calf3: ");
            scanf("%d", &calf3);
    
            float promedio2 = (calf1 + calf2 + calf3) / 3.0;
    
            printf("Nombre: %s\n", nombre);
            printf("Promedio: %.2f\n", promedio2);
    
            if(promedio2 >= 60) {
                printf("Aprobado\n");
            } else {
                printf("Reprobado\n");
            }}
        break;
        case 'n':
        {float radio,altura,area,volumen;
            double pi=3.1416;
            printf("calcular area y volumen de un cilindro\n");
            printf("ingrese altura:");
            scanf("%f",&altura);
            printf("ingrese radio:");
            scanf("%f",&radio);
            area=2*pi*radio*(altura+radio);
            volumen=(radio*radio)*altura*pi;
            printf("area es:\n");
            printf("%.2f",area);
            printf("\nvolumen es:\n");
            printf("%.2f",volumen);
        
            return 0;
        }
        break;
        case 'o':{
            float radio,altura,generatriz,area,volumen,arealateral,areabase;
            double pi=3.1416;
            printf("calculo de area y volumen de un cono\n");
            printf("ingrese radio:\n");
            scanf("%f",&radio);
            printf("ingrese altura:\n");
            scanf("%f",&altura);
            generatriz= sqrt((radio*radio)+(altura*altura));
            areabase=(radio*radio)*pi;
            arealateral=pi*radio*generatriz;
            area=areabase+arealateral;
            volumen=((radio*radio)*pi*altura)/3;
            printf("area es:\n");
            printf("%.2f",area);
            printf("\nvolumen es:\n");
            printf("%.2f",volumen);
        return 0;
        }
        break;
        case 'p':{
            float radio,area,volumen;
            double pi=3.1416;
            printf("%s","calcular area y volumen de una esfera\n");
            printf("%s","ingresa valor de radio:\n");
            scanf("%f",&radio);
        
            area= (radio*radio)*(4*pi);
            volumen=((radio*radio*radio)*pi*4)/3;
            printf("%s","volumen es:\n");
            printf("%.2f",volumen);
            printf("%s","\narea es:\n");
            printf("%.2f",area);
        }
        break;
        case 'q':{
            char opc;
            printf("%s", "Seleccione una opción");
            printf("%s", "1 - sumar");
            printf("%s", "2 - restar");
            scanf("%c", &opc);
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
            }}
        break;
        case 'r':{
                float a;
                float b;
                float c2;
                char op;
                
                printf("Ingresa un numero: \n");
                scanf("%f", &a);
                printf("Ingresa el operador (+,-,*,/): \n");
                scanf(" %c", &op);
                printf("Ingresa otro numero: \n");
                scanf("%f",&b);
                switch(op) {
                    case'+':
                    c2 = a + b;
                    printf("%s%.2f","Resultado", c2);
                    break;
                    
                    case'-':
                    c2 = a - b;
                    printf("%s%.2f", "Resultado", c2);
                    break;
                    
                    case'*':
                    c2 = a * b;
                    printf("%s%.3f", "Resultado: ", c2);
                    break;
                    
                    case'/':
                    if(b != 0){
                        c2 = a / b;
                        printf("%s%.3f", "Resultado", c2);
                        break;}
                    else{
                        printf("No es posible");
                        break;
                    }
                    default:
                        printf("%s", "No ha seleccionado una opcion correcta");
                        break;
                }}
        break;
    default:
    printf("%s", "No ha seleccionado una opción válida");
        break;
    }
}}