#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Prototipos de funciones
void estructuraImpresionCartas();
void apuntador2();
void apuntadoresConstante();
void arreglo();
void arregloEstructuras();
void arregloLeer();
void banderaMexico();
void banderaUSA();
void claveValor();
void cuadradoColores();
void ecuadratica2();
void ecuadraticaStruct();
void ejercicioFunciones();
void estructura();
void estructuraAnidada();
void estructuraDeclarativa();
void estructuraDobleAnidada();
void estructuraImpresion();
void estructuraUnion();
void apuntador1();
void funcion3nMayor();
void funcionDivisas();
void funcionEcuadratica();
void funciones1();
void funcionExponencial();
void funcionNumeroMayor();
void funcionPalabras();
void funcionPares();
void funcionPositivoNegativo();
void funcionSumaIntervalo();
void funcionTablaMultiplicar();
void funcionTemperatura();
void gotoxyLeer();
void gotoxyFunc();
void matriz();
void matrizCadenas();
void matrizExponente();
void matrizFraccionesMultiplicacion();
void matrizFuncion();
void matrizN();
void menuGotoxyColores();
void modificacionColoresDeterminante();
void multiplicacionEstructura();
void multiplicacionMatriz();
void multiplicacionMatrizVector();
void operacionMatriz();
void operacionRegistro2();
void punteroDoble();
void punterosOperaciones();
void punteroSuma();
void setcolorFunc();
void sprintfFunc();
void tablaMultiplicar();
void transpuestaMatriz();
void trianguloColores();
void unionFunc();
void vehiculoUnion();

int main() {
    int opcion = 0;
    
    printf("Seleccione una opción (1-57): ");
    scanf("%d", &opcion);
    
    if (opcion < 1 || opcion > 57) {
        printf("Opción fuera de rango. Por favor, seleccione un número entre 1 y 57.\n");
        return 1;
    }
    
    printf("\n===== MENÚ DE PROGRAMAS EN C =====\n"
           "1.  Estructura impresión cartas\n"
           "2.  Apuntador 2\n"
           "3.  Apuntadores constante\n"
           "4.  Arreglo\n"
           "5.  Arreglo Estructuras\n"
           "6.  Arreglo leer\n"
           "7.  Bandera México\n"
           "8.  Bandera USA\n"
           "9.  Clave valor\n"
           "10. Cuadrado Colores\n"
           "11. Ecuadrática 2\n"
           "12. Ecuadrática struct\n"
           "13. Ejercicio funciones\n"
           "14. Estructura\n"
           "15. Estructura anidada\n"
           "16. Estructura declarativa\n"
           "17. Estructura doble anidada\n"
           "18. Estructura impresión\n"
           "19. Estructura unión\n"
           "20. Apuntador 1\n"
           "21. Función 3n mayor\n"
           "22. Función divisas\n"
           "23. Función ecuadrática\n"
           "24. Funciones 1\n"
           "25. Función exponencial\n"
           "26. Función número mayor\n"
           "27. Función palabras\n"
           "28. Función pares\n"
           "29. Función positivo negativo\n"
           "30. Función suma intervalo\n"
           "31. Función tabla multiplicar\n"
           "32. Función temperatura\n"
           "33. Gotoxy Leer\n"
           "34. Gotoxy\n"
           "35. Matriz\n"
           "36. Matriz cadenas\n"
           "37. Matriz exponente\n"
           "38. Matriz fracciones multiplicación\n"
           "39. Matriz función\n"
           "40. Matriz n\n"
           "41. Menú Gotoxy Colores\n"
           "42. Modificación de colores determinante\n"
           "43. Multiplicación estructura\n"
           "44. Multiplicación matriz\n"
           "45. Multiplicación matriz vector\n"
           "46. Operación matriz\n"
           "47. Operación registro 2\n"
           "48. Puntero doble\n"
           "49. Punteros operaciones\n"
           "50. Puntero suma\n"
           "51. Setcolor\n"
           "52. Sprintf\n"
           "53. Tabla multiplicar\n"
           "54. Transpuesta matriz\n"
           "55. Triángulo Colores\n"
           "56. Unión\n"
           "57. Vehículo Unión\n"
           "=================================\n");
    
    switch (opcion) {
        case 1: estructuraImpresionCartas(); break;
        case 2: apuntador2(); break;
        case 3: apuntadoresConstante(); break;
        case 4: arreglo(); break;
        case 5: arregloEstructuras(); break;
        case 6: arregloLeer(); break;
        case 7: banderaMexico(); break;
        case 8: banderaUSA(); break;
        case 9: claveValor(); break;
        case 10: cuadradoColores(); break;
        case 11: ecuadratica2(); break;
        case 12: ecuadraticaStruct(); break;
        case 13: ejercicioFunciones(); break;
        case 14: estructura(); break;
        case 15: estructuraAnidada(); break;
        case 16: estructuraDeclarativa(); break;
        case 17: estructuraDobleAnidada(); break;
        case 18: estructuraImpresion(); break;
        case 19: estructuraUnion(); break;
        case 20: apuntador1(); break;
        case 21: funcion3nMayor(); break;
        case 22: funcionDivisas(); break;
        case 23: funcionEcuadratica(); break;
        case 24: funciones1(); break;
        case 25: funcionExponencial(); break;
        case 26: funcionNumeroMayor(); break;
        case 27: funcionPalabras(); break;
        case 28: funcionPares(); break;
        case 29: funcionPositivoNegativo(); break;
        case 30: funcionSumaIntervalo(); break;
        case 31: funcionTablaMultiplicar(); break;
        case 32: funcionTemperatura(); break;
        case 33: gotoxyLeer(); break;
        case 34: gotoxyFunc(); break;
        case 35: matriz(); break;
        case 36: matrizCadenas(); break;
        case 37: matrizExponente(); break;
        case 38: matrizFraccionesMultiplicacion(); break;
        case 39: matrizFuncion(); break;
        case 40: matrizN(); break;
        case 41: menuGotoxyColores(); break;
        case 42: modificacionColoresDeterminante(); break;
        case 43: multiplicacionEstructura(); break;
        case 44: multiplicacionMatriz(); break;
        case 45: multiplicacionMatrizVector(); break;
        case 46: operacionMatriz(); break;
        case 47: operacionRegistro2(); break;
        case 48: punteroDoble(); break;
        case 49: punterosOperaciones(); break;
        case 50: punteroSuma(); break;
        case 51: setcolorFunc(); break;
        case 52: sprintfFunc(); break;
        case 53: tablaMultiplicar(); break;
        case 54: transpuestaMatriz(); break;
        case 55: trianguloColores(); break;
        case 56: unionFunc(); break;
        case 57: vehiculoUnion(); break;
        default: printf("Opción no válida\n");
    }
    
    return 0;
}

// Implementación de funciones
void estructuraImpresionCartas() {
    int n;
    printf("Ingrese el numero de cartas: ");
    scanf("%d", &n);
    getchar();
    
    struct detalle {
        char Escrita_con[50];
        char Tipo[50];
        char Margen[50];
        char Tiene_Estampas[50];
        char Es_Formal[50];
        char Color[50];
        char En_Sobre[50];
        char Tipo_De_Letra[50];
    };

    struct cartas {
        char Remitente[50];
        char Destinatario[50];
        int precio;
        int peso;
        struct detalle carta;
    };
    
    struct cartas cartass[n];
    for (int i = 0; i < n; i++) {
        printf("\nIngrese el remitente %d:\n", i + 1);
        printf("Remitente: ");
        scanf(" %[^\n]", cartass[i].Remitente);
        printf("\nIngrese el destinatario: ");
        scanf(" %[^\n]", cartass[i].Destinatario);
        printf("\nPrecio: ");
        scanf("%d", &cartass[i].precio);
        printf("\nIngrese el peso (kg): ");
        scanf("%d", &cartass[i].peso);
        printf("\nEscrita con: ");
        scanf(" %[^\n]", cartass[i].carta.Escrita_con);
        printf("\nTipo: ");
        scanf(" %[^\n]", cartass[i].carta.Tipo);
        printf("\nMargen: ");
        scanf(" %[^\n]", cartass[i].carta.Margen);
        printf("\nTiene Estampas: ");
        scanf(" %[^\n]", cartass[i].carta.Tiene_Estampas);
        printf("\nEs Formal: ");
        scanf(" %[^\n]", cartass[i].carta.Es_Formal);
        printf("\nColor: ");
        scanf(" %[^\n]", cartass[i].carta.Color);
        printf("\nEn Sobre: ");
        scanf(" %[^\n]", cartass[i].carta.En_Sobre);
        printf("\nTipo De letra: ");
        scanf(" %[^\n]", cartass[i].carta.Tipo_De_Letra);
        getchar();
    }
    
    printf("\n%-20s | %-20s | %-10s | %-10s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s\n", 
           "Remitente", "Destinatario", "Precio", "Peso (kg)", "Escrita Con", "Tipo", "Margen", "Tiene Estampas", 
           "Es Formal", "Color", "En Sobre", "Tipo de Letra");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++)
        printf("%-20s | %-20s | %-10d | %-10d | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s | %-20s\n",
               cartass[i].Remitente,
               cartass[i].Destinatario,
               cartass[i].precio,
               cartass[i].peso,
               cartass[i].carta.Escrita_con,
               cartass[i].carta.Tipo,
               cartass[i].carta.Margen,
               cartass[i].carta.Tiene_Estampas,
               cartass[i].carta.Es_Formal,
               cartass[i].carta.Color,
               cartass[i].carta.En_Sobre,
               cartass[i].carta.Tipo_De_Letra);
}

void apuntador2() {
    int numero = 42;
    int *apuntador = &numero;
    printf("Valor del número: %d\n", numero);
    printf("Posición del número: %p\n", &numero);
    printf("Valor del apuntador %d\n", *apuntador);
    printf("Posición del apuntador: %p\n", apuntador);
}

void apuntadoresConstante() {
    int a, b, c, d, e;
    printf("Ingrese valor A: ");
    scanf("%d", &a);
    printf("Ingrese valor B: \n");
    scanf("%d", &b);
    printf("Ingrese valor C: \n");
    scanf("%d", &c);
    printf("Ingrese valor D: \n");
    scanf("%d", &d);
    printf("ingrese valor E: \n");
    scanf("%d", &e);
    
    int * const pa = &a;
    int * const pb = &b;
    int * const pc = &c;
    int * const pd = &d;
    int * const pe = &e;
    
    printf("Valores ingresados: A = %p\n", (void*)pa);
    printf("Valores ingresados: B = %p\n", (void*)pb);
    printf("Valores ingresados C = %p\n", (void*)pc);
    printf("Valores ingresados D = %p\n", (void*)pd);
    printf("Valores ingreasdos E = %p\n", (void*)pe);
}

void arreglo() {
    int numeros[] = {12, 20, 30, 20};
    int size = sizeof(numeros) / sizeof(numeros[0]);

    printf("tamaño: %d\n", size);
    
    for (int i = 0; i < size; i++) {
        printf("numeros[%d] = %d\n", i, numeros[i]);
    }
}

void arregloEstructuras() {
    struct Producto {
        char nombre[50];
        float precio;
        int cantidad;
        char categoria[30];
        char marca[30];
        char fecha_expiracion[20];
        char codigo[20];
        char descripcion[100];
    };
    
    int tamanio;
    printf("Ingrese el número de productos que desea registrar:\n");
    scanf("%d", &tamanio);
    
    struct Producto productos[tamanio];
    for (int j = 0; j < tamanio; j++) {
        printf("Ingrese el nombre del producto:\n");
        scanf("%s", productos[j].nombre);
        printf("Ingrese el precio del producto:\n");
        scanf("%f", &productos[j].precio);
        printf("Ingrese la cantidad de producto que tiene:\n");
        scanf("%d", &productos[j].cantidad);
        printf("Ingrese la categoría del producto: \n");
        scanf("%s", productos[j].categoria);
        printf("Ingrese la fecha de expiración del producto: \n");
        scanf("%s", productos[j].fecha_expiracion);
        printf("Ingrese el codigo del producto: \n");
        scanf("%s", productos[j].codigo);
        printf("Ingrese la marca del producto: \n");
        scanf("%s", productos[j].marca);
        printf("Ingrese la descripción del producto: \n");
        scanf("%s", productos[j].descripcion);
    }
    
    printf("\nDatos de los productos:\n");
    for (int i = 0; i < tamanio; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Precio: %.2f\n", productos[i].precio);
        printf("Cantidad: %d\n", productos[i].cantidad);
        printf("Categoría: %s\n", productos[i].categoria);
        printf("Codigo: %s\n", productos[i].codigo);
        printf("Marca: %s\n", productos[i].marca);
        printf("Descripción: %s\n", productos[i].descripcion);
        printf("Fecha de expiración: %s\n", productos[i].fecha_expiracion);
    }
}

void arregloLeer() {
    int size;
    printf("Ingrese el tamaño del arreglo:\n");
    scanf("%d", &size);

    int ArregloNumeros[size];
    for (int i = 0; i < size; i++) {
        printf("Ingrese el valor en posicion [%d]:\n", i);
        scanf("%d", &ArregloNumeros[i]);
    }
    
    for (int i = 0; i < size; i++) {
        printf("arreglo [%d] = %d\n", i, ArregloNumeros[i]);
    }
}

void banderaMexico() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 4; j++) {
            printf("\033[7;32m  ");
        }
        for (int k = 4; k < 10; k++) {
            printf("\033[7;37m  ");
        }
        for (int j = 9; j < 13; j++) {
            printf("\033[7;31m  ");
        }
        printf("\n");
    }
    printf("\033[0m");
}

void banderaUSA() {
    printf("\033[2J");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;31m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;37m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;31m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;37m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;31m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;37m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;31m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;37m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;31m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;34m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\033[7;37m");
    for (int j = 0; j < 20; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;31m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;37m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;31m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;37m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;31m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;37m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[7;31m");
    for (int j = 0; j < 40; j++) {
        printf(" ");
    }
    printf("\n");
    
    printf("\033[0m");
}

void claveValor() {
    struct Keyvalue {
        char Clave[50];
        char valor[100];
    };
    
    struct Keyvalue tabla[3] = {
        {"usuario", "admin"},
        {"contraseña", "1234"},
        {"servidor", "localhost"}
    };
    
    printf("tabla Clave-Valor:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", tabla[i].Clave, tabla[i].valor);
    }
}

void cuadradoColores() {
    int n;
    printf("Introduzca el número de filas que desea que tenga el cuadrado: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("\033[7;33m * ");
        }
        printf("\n");
    }
    printf("\033[0m");
}

void ecuadratica2() {
    printf("Menú de figuras. \n");
    printf("Figuras 3D: \n");
    printf("1.- Volúmen y área de un cilindro: \n");
    printf("2.- Volúmen y área de un cubo: \n");
    printf("3.- Volúmen y área de un cono: \n");
    printf("4.- Volúmen y área de una esfera: \n");
    printf("5.- Volúmen y área de un prisma rectangular: \n");
    printf("Figuras 2D: \n");
    printf("6.- Área de un cuadrado: \n");
    printf("7.- Área de un triángulo: \n");
    printf("8.- Área de un circulo: \n");
    printf("9.- Área de un rectángulo: \n");
    printf("10.- Área de un rombo: \n");
    
    printf("Seleccione una opción (1-10): ");
    int opc;
    scanf("%d", &opc);
    
    switch (opc) {
        case 1: {
            int r;
            printf("Introduzca el valor del radio: \n");
            scanf("%d", &r);
            int h;
            printf("Introduzca el valor de la altura: \n");
            scanf("%d", &h);
            
            float volumencilindro1 = M_PI * pow(r, 2) * h;
            printf("El volumen del cilindro es: %f \n", volumencilindro1);
            
            float areacilindro1 = (2 * M_PI * pow(r, 2)) + (2 * M_PI * r * h);
            printf("El área del cilindro es: %f \n", areacilindro1);
            break;
        }
        case 2: {
            int a;
            printf("Introduzca el valor del lado del cubo: \n");
            scanf("%d", &a);
            
            float volumencubo1 = pow(a, 3);
            printf("El volumen del cubo es: %f \n", volumencubo1);
            
            float areacubo1 = 6 * pow(a, 2);
            printf("El área del cubo es: %f \n", areacubo1);
            break;
        }
        default:
            printf("Opción no válida\n");
            break;
    }
}

void ecuadraticaStruct() {
    struct Ecuadratica {
        int a;
        int b;
        int c;
        int discriminante;
        float x1;
        float x2;
        char solucion[50];
    };
    
    struct Ecuadratica array[2] = {
        {2, 3, -5, 0, 0.0, 0.0, ""},
        {3, 7, -6, 0, 0.0, 0.0, ""}
    };
    
    for (int i = 0; i < 2; i++) {
        int d = pow(array[i].b, 2) - (4 * array[i].a * array[i].c);
        if (d < 0) {
            strcpy(array[i].solucion, "No tiene solución");
        } else {
            float valx1 = ((-1) * array[i].b + sqrt(d)) / (2.0 * array[i].a);
            float valx2 = ((-1) * array[i].b - sqrt(d)) / (2.0 * array[i].a);
            strcpy(array[i].solucion, "Tiene solución");
            array[i].x1 = valx1;
            array[i].x2 = valx2;
        }
    }
    
    printf("%s|%s|%s|%s|%s|%s\n", "a", "b", "c", "x1", "x2", "sol");
    for (int i = 0; i < 2; i++) {
        printf("%d|%d|%d|%.2f|%.2f|%s\n",
               array[i].a, array[i].b, array[i].c, 
               array[i].x1, array[i].x2, array[i].solucion);
    }
}

void ejercicioFunciones() {
    int op1 = 3 + 2;
    int op2 = 5 - 3;
    int op3 = 3 * 3;
    float op4 = 5.0 / 3.0;
    
    printf("Resultado de la suma: %d\nResta: %d\nMultplicación: %d\nDivisión: %.2f\n", 
           op1, op2, op3, op4);
}

void estructura() {
    struct Estudiante {
        char nombre[50];
        int edad;
        float promedio;
    };
    
    struct Estudiante estudiante1 = {"Alejandro Díaz", 24, 6.5};
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);
}

void estructuraAnidada() {
    struct Direccion {
        char calle[50];
        int numero;
    };

    struct Persona {
        char nombre[50];
        struct Direccion domicilio;
    };
    
    struct Persona persona1 = {"Carlos Ramirez", {"Av.Reforma", 123}};
    printf("nombre: %s\n", persona1.nombre);
    printf("domicilio: %s #%d\n", persona1.domicilio.calle, persona1.domicilio.numero);
}

void estructuraDeclarativa() {
    typedef struct {
        char nombre[50];
        int edad;
        float promedio;
    } Estudiante;
    
    Estudiante estudiante1 = {"Marta López", 22, 9.31};
    printf("Nombre: %s\n", estudiante1.nombre);
}

void estructuraDobleAnidada() {
    struct coordenadas {
        char numero[50];
        char calle[50];
        int cp;
    };
    
    struct ubicacion {
        char ciudad[50];
        char estado[50];
        struct coordenadas direccion;
    };
    
    struct persona {
        char nombre[50];
        struct ubicacion domicilio;
    };
    
    struct persona p1 = {"Juan Pérez", {"México", "CDMX", {"123", "Reforma", 11000}}};
    
    printf("Nombre: %s\n", p1.nombre);
    printf("Ciudad: %s\n", p1.domicilio.ciudad);
    printf("Estado: %s\n", p1.domicilio.estado);
    printf("Dirección: %s %s, CP: %d\n", 
           p1.domicilio.direccion.numero, 
           p1.domicilio.direccion.calle, 
           p1.domicilio.direccion.cp);
}

void estructuraImpresion() {
    struct Estudiante {
        char nombre[50];
        int edad;
        float promedio;
    };
    
    struct Estudiante e1 = {"Ana López", 20, 9.5};
    struct Estudiante e2 = {"Carlos Pérez", 22, 8.7};
    
    printf("Estudiante 1:\n");
    printf("Nombre: %s\n", e1.nombre);
    printf("Edad: %d\n", e1.edad);
    printf("Promedio: %.2f\n\n", e1.promedio);
    
    printf("Estudiante 2:\n");
    printf("Nombre: %s\n", e2.nombre);
    printf("Edad: %d\n", e2.edad);
    printf("Promedio: %.2f\n", e2.promedio);
}

void estructuraUnion() {
    union Dato {
        int entero;
        float decimal;
        char texto[20];
    };
    
    union Dato valor;
    valor.entero = 10;
    printf("Valor entero: %d\n", valor.entero);
    
    valor.decimal = 3.14;
    printf("Valor decimal: %.2f\n", valor.decimal);
    
    strcpy(valor.texto, "Hola");
    printf("Valor texto: %s\n", valor.texto);
}

void apuntador1() {
    int numero = 10;
    int *ptr = &numero;
    
    printf("Valor de número: %d\n", numero);
    printf("Dirección de número: %p\n", &numero);
    printf("Valor de ptr: %p\n", ptr);
    printf("Valor al que apunta ptr: %d\n", *ptr);
    
    *ptr = 20;
    printf("Nuevo valor de número (después de *ptr = 20): %d\n", numero);
}

void funcion3nMayor() {
    int a, b, c;
    printf("Introduzca el valor 1: \n");
    scanf("%d", &a);
    printf("Introduzca el valor 2: \n");
    scanf("%d", &b);
    printf("Introduzca el valor 3: \n");
    scanf("%d", &c);
    
    int mayor;
    if (a > b && a > c) {
        mayor = a;
    } else if (b > a && b > c) {
        mayor = b;
    } else {
        mayor = c;
    }
    
    printf("El número mayor es: %d\n", mayor);
}

void funcionDivisas() {
    int opc;
    float valor, resultado;
    
    printf("Conversión de divisas: \n"
            "1.- Euro a Dolar.\n"
            "2.- Euro a Libra esterlina.\n"
            "3.- Euro a Peso mexicano.\n"
            "4.- Dolar a Euro.\n"
            "5.- Dolar a Libra esterlina.\n"
            "6.- Dolar a Peso mexicano.\n"
            "7.- Peso mexicano a Dolar.\n"
            "8.- Peso mexicano a Libra esterlina.\n"
            "9.- Peso mexicano a Euro.\n"
            "10.- Libra esterlina a Euro.\n"
            "11.- Libra esterlina a Dolar.\n"
            "12.- Libra esterlina a Peso mexicano.\n");
    scanf("%d", &opc);
    
    switch (opc) {
    case 1:
        printf("Ingrese la cantidad en euros que desea convertir: \n");
        scanf("%f", &valor);
        resultado = valor * 1.08;
        printf("La conversión de %.2f € a Dolares es: $%.2f\n", valor, resultado);
        break;
    case 2:
        printf("Ingrese la cantidad en euros que desea convertir: \n");
        scanf("%f", &valor);
        resultado = valor * 0.84;
        printf("La conversión de %.2f € a Libras esterlinas es: £%.2f\n", valor, resultado);
        break;
    case 3:
        printf("Ingrese la cantidad en euros que desea convertir: \n");
        scanf("%f", &valor);
        resultado = valor * 21.98;
        printf("La conversión de %.2f € a Pesos mexicanos es: $%.2f MXN\n", valor, resultado);
        break;
    default:
        printf("Opción no válida\n");
        break;
    }
}

void funcionEcuadratica() {
    int a, b, c;

    printf("Ingresa el valor de A: \n");
    scanf("%d", &a);
    printf("Ingresa el valor de B: \n");
    scanf("%d", &b);
    printf("Ingresa el valor de C: \n");
    scanf("%d", &c);

    int disc = (b * b) - (4 * a * c);

    if (disc < 0) {
        printf("No es posible calcular el resultado.\n");
    } else {
        float x1 = (-b + sqrt(disc)) / (2.0 * a);
        float x2 = (-b - sqrt(disc)) / (2.0 * a);
        printf("Las raices son: (%.2f, %.2f)\n", x1, x2);
    }
}

void funciones1() {
    int suma_resultado = 3 + 2;
    int resta_resultado = 5 - 3;
    int multiplicar_resultado = 3 * 3;
    float dividir_resultado = 5.0 / 3.0;

    printf("Resultado de la suma: %d\nResta: %d\nMultplicación: %d\nDivisión: %.2f\n", 
          suma_resultado, resta_resultado, multiplicar_resultado, dividir_resultado);
}

void funcionExponencial() {
    int a, b;
    printf("Introduzca el número: \n");
    scanf("%d", &a);
    printf("Introduzca el exponente: \n");
    scanf("%d", &b);
    
    int resultado = a;
    for (int i = 1; i < b; i++) {
        resultado *= a;
    }
    
    printf("El resultado es: %d\n", resultado);
}

void funcionNumeroMayor() {
    int a, b;
    printf("Introduzca un número: \n");
    scanf("%d", &a);
    printf("Introduzca otro número: \n");
    scanf("%d", &b);
    
    int mayor = (a > b) ? a : b;
    printf("El número mayor es: %d\n", mayor);
}

void funcionPalabras() {
    int numero;
    printf("Ingresa un numero (1-5): ");
    scanf("%d", &numero);
    
    const char* palabra;
    switch (numero) {
        case 1:
            palabra = "Hola";
            break;
        case 2:
            palabra = "Mundo";
            break;
        case 3:
            palabra = "Programacion";
            break;
        case 4:
            palabra = "Lenguaje";
            break;
        case 5:
            palabra = "Diversión";
            break;
        default:
            palabra = "Número fuera de rango";
            break;
    }
    
    printf("La palabra correspondiente es: %s\n", palabra);
}

void funcionPares() {
    int n;
    printf("Introduzca la cantidad de números que desea ingresar: \n");
    scanf("%d", &n);
    int numeros[n];
    
    for(int i = 0; i < n; i++) {
        printf("Introduzca un número: \n");
        scanf("%d", &numeros[i]);
    }
    
    printf("Los números impares que ingresó son:\n");
    for(int i = 0; i < n; i++) {
        if (numeros[i] % 2 == 1) {
            printf("Número %2d: %2d\n", i+1, numeros[i]);
        }
    }
}

void funcionPositivoNegativo() {
    float a;
    printf("Introduzca un número: \n");
    scanf("%f", &a);
    
    if (a > 0) {
        printf("El número es positivo\n");
    } else if (a == 0) {
        printf("El número que ha ingresado es 0\n");
    } else {
        printf("El número es negativo\n");
    }
}

void funcionSumaIntervalo() {
    int a, b;
    printf("Ingrese el número menor: \n");
    scanf("%d", &a);
    printf("Ingrese el número mayor: \n");
    scanf("%d", &b);
    
    int suma = a + b;
    for(int i = a + 1; i < b; i++) {
        suma += i;
    }
    
    printf("La suma de todos los números en el intervalo es de: %d\n", suma);
}

void funcionTablaMultiplicar() {
    int N;
    printf("Ingrese hasta que numero quiere ver las tabla de multiplicar: ");
    scanf("%d", &N);
    
    printf("Tabla de %d: \n", N);
    for(int j = 1; j <= 10; j++) {
        int resultado = N * j;
        printf("%d x %d = %d\n", N, j, resultado);
    }
}

void funcionTemperatura() {
    int opc;
    float K, C, F;
    printf("Ingrese la opción que desea realizar: \n");
    printf("1.- Convertir grados Celsius a Kelvin \n"
            "2.- Convertir grados Farenheit a Celsius\n"
            "3.- Convertir grados Celsius a Farenheit\n"
            "4.- Convertir grados Kelvin a Farenheit\n");
    scanf("%d", &opc);
    
    switch (opc) {
    case 1:
        printf("Ingrese los grados Celsius que desea convertir a Kelvin: \n");
        scanf("%f", &C);
        K = C + 273.15;
        printf("La conversión de %.2f ºC a ºK es: %.2f ºK\n", C, K);
        break;
    case 2:
        printf("Ingrese los grados Farenheit que desea convertir a Celsius: \n");
        scanf("%f", &F);
        C = (F - 32) * (5.0 / 9.0);
        printf("La conversión de %.2f ºF a ºC es: %.2f ºC\n", F, C);
        break;
    case 3:
        printf("Ingrese los grados Celsius que desea convertir a Farenheit: \n");
        scanf("%f", &C);
        F = (C * (9.0 / 5.0)) + 32;
        printf("La conversión de %.2f ºC a ºF es: %.2f ºF\n", C, F);
        break;
    case 4:
        printf("Ingrese los grados Kelvin que desea convertir a Farenheit: \n");
        scanf("%f", &K);
        F = ((K - 273.15) * (9.0 / 5.0)) + 32;
        printf("La conversión de %.2f ºK a ºF es: %.2f ºF\n", K, F);
        break;
    default:
        printf("Opción no válida \n");
        break;
    }
}

void gotoxyLeer() {
    char nombre[50];
    int edad;
 
    printf("\033[2J"); 
    printf("\033[7;34m");
 
    printf("\033[%d;%dH", 5, 10);
    printf("Ingrese su nombre: ");
    printf("\033[%d;%dH", 5, 30);
    printf("\033[7;35m");
    scanf("%s", nombre);
 
    printf("\033[7;34m");
    printf("\033[%d;%dH", 7, 10);
    printf("Ingrese su edad: ");
    printf("\033[%d;%dH", 7, 30);
    printf("\033[7;35m");
    scanf("%d", &edad);
 
    printf("\033[%d;%dH", 9, 10);
    printf("Hola %s, tienes %d años.\n", nombre, edad);
    printf("\033[0m");
}

void gotoxyFunc() {
    printf("\033[2J");
    printf("\033[%d;%dH", 5, 10);
    printf("Hola desde (10,5) !");
}

void matriz() {
    int filas;
    printf("Introduzca el número de filas que quiere que tenga la matriz:\n");
    scanf("%d", &filas);
    int columnas;
    printf("Introduzca el número de columnas que desea que tenga la matriz:\n");
    scanf("%d", &columnas);
    
    int matriz[filas][columnas];
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Introduzca un numero para guardar en la matriz [%d] [%d]: \n", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("Recorriendo la matriz\n");
    for (int i = filas - 1; i >= 0; i--) {
        for (int j = columnas - 1; j >= 0; j--) {
            printf("| %2d |", matriz[i][j]); 
        }
        printf("\n");
    }
}

void matrizCadenas() {
    #define FILAS 3
    #define COLUMNAS 3  
    #define LONGITUD 40

    char matriz[FILAS][COLUMNAS][LONGITUD];

    printf("ingrese 9 palabras:\n ");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("matriz [%d][%d]: ", i, j);
            scanf("%s", matriz[i][j]);
        }
    }

    printf("Recorriendo la matriz:\n"); 
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%-10s", matriz[i][j]);
            printf("%s", "|");
        }
        printf("\n");
    }
}

void matrizExponente() {
    int fya, exp;
    printf("Introduzca el número de filas y columnas que desea que tenga la matriz A: \n");
    scanf("%d", &fya);
    printf("Introduzca el exponente por el cual desea multiplicar la matriz A: \n");
    scanf("%d", &exp);
    
    if (exp <= 0) {
        printf("El exponente debe ser mayor a 0.\n");
        return;
    }
    
    int matrizA[fya][fya];
    int matrizAorg[fya][fya];
    
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("Introduzca el valor para la matriz en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
            matrizAorg[i][j] = matrizA[i][j];
        }
    }
    
    printf("Recorriendo la matriz.\n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("|%2d| ", matrizA[i][j]);
        }
        printf("\n");
    }
    
    int matrizC[fya][fya];
    for (int e = 1; e < exp; e++) {
        for (int i = 0; i < fya; i++) {
            for (int j = 0; j < fya; j++) {
                int suma = 0;
                for (int k = 0; k < fya; k++) {
                    suma += matrizAorg[i][k] * matrizA[k][j]; 
                }
                matrizC[i][j] = suma;
            }
        }
        
        for (int i = 0; i < fya; i++) {
            for (int j = 0; j < fya; j++) {
                matrizA[i][j] = matrizC[i][j];
            }
        }
    }
    
    printf("Matriz (A)^%d: \n", exp);
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("|%2d| ", matrizC[i][j]);
        }
        printf("\n");
    }
}

void matrizFraccionesMultiplicacion() {
    typedef struct {
        int numerador;
        int denominador;
    } fraccion;

    int filas, columnas;
    printf("Introduzca el número de filas que desea que tenga la matriz A y B: \n");
    scanf("%d", &filas);
    printf("Introduzca el número de columnas que desea que tenga la matriz A y B: \n");
    scanf("%d", &columnas);
    
    fraccion matrizA[filas][columnas];
    fraccion matrizB[filas][columnas];
    fraccion matrizC[filas][columnas];
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Introduzca el valor del numerador para la matriz A en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizA[i][j].numerador);
            printf("Introduzca el valor del denominador para la matriz A en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizA[i][j].denominador);
        }
    }
    
    printf("Recorriendo la matriz A.\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("|%2d/%2d| ", matrizA[i][j].numerador, matrizA[i][j].denominador);
        }
        printf("\n");
    }
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Introduzca el valor del numerador para la matriz B en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizB[i][j].numerador);
            printf("Introduzca el valor del denominador para la matriz B en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizB[i][j].denominador);
        }
    }
    
    printf("Recorriendo la matriz B.\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("|%2d/%2d| ", matrizB[i][j].numerador, matrizB[i][j].denominador);
        }
        printf("\n");
    }
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizC[i][j].numerador = matrizA[i][j].numerador * matrizB[i][j].numerador;
            matrizC[i][j].denominador = matrizA[i][j].denominador * matrizB[i][j].denominador;
        }
    }
    
    printf("Resultado de la multiplicación A*B:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("|%2d/%2d| ", matrizC[i][j].numerador, matrizC[i][j].denominador);
        }
        printf("\n");
    }
}

void matrizFuncion() {
    int filas, columnas;
    
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);
    
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_rsuma[filas][columnas];
    int matrizsarrus[3][5];
    
    printf("Matriz A\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz_a[i][j]);
        }
    }
    
    printf("Matriz B\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz_b[i][j]);
        }
    }
    
    printf("Matriz A ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_a[i][j]);
        }
        printf("\n");
    }
    
    printf("Matriz B ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_b[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_rsuma[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
    }
    
    printf("SUMA A+B:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_rsuma[i][j]);
        }
        printf("\n");
    }
    
    if (filas == 3 && columnas == 3) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                matrizsarrus[i][j] = matriz_a[i][j];
            }
            matrizsarrus[i][3] = matriz_a[i][0];
            matrizsarrus[i][4] = matriz_a[i][1];
        }
        
        int sumadiagonales = 0;
        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 3; j++) {
                sumadiagonales += matrizsarrus[i][j] * matrizsarrus[i+1][j+1] * matrizsarrus[i+2][j+2];
            }
        }
        
        int restadiagonales = 0;
        for (int i = 0; i < 1; i++) {
            for (int j = 2; j >= 0; j--) {
                restadiagonales += matrizsarrus[i][j+2] * matrizsarrus[i+1][j+1] * matrizsarrus[i+2][j];
            }
        }
        
        int determinante = sumadiagonales - restadiagonales;
        printf("La determinante de la matriz A es: %d\n", determinante);
    } else {
        printf("La matriz A no es una matriz 3x3, no se puede calcular su determinante.\n");
    }
}

void matrizN() {
    int val;
    printf("Introduzca el valor al que le quiere sacar raiz: \n");
    scanf("%d", &val);
    
    int n = 0;
    for (int i = 0; i <= val; i++) {
        if (i * i == val) {
            n = i;
            printf("El valor de la raíz es: %d \n", n);
            break;
        }
    }
    
    if (n == 0) {
        printf("No tiene raíz entera\n");
        return;
    }
    
    char matriz[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Introduzca el valor para la matriz en la posición [%d] [%d]: ", i, j);
            scanf(" %c", &matriz[i][j]);
        }
    }
    
    printf("Recorriendo la matriz\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Valor de la Matriz en la posición [%d][%d]: %c\n", i, j, matriz[i][j]);
        }
    }
}

void menuGotoxyColores() {
    int opc;
    float n1, n2, resultado;
    
    printf("\033[0m");
    printf("\033[7;32m");
    printf("\033[%d;%dH", 5, 10);
    printf("Calculadora Basica con gotoxy y switch case");
    
    printf("\033[%d;%dH", 6, 30);
    printf("\033[0m");
    printf("\033[4;37m");
    printf("Menu de operaciones");
    
    printf("\033[0m");
    printf("\033[7;34m");
    printf("\033[%d;%dH", 7, 10);
    printf("1.-");
    printf("\033[0m");
    printf("\033[%d;%dH", 7, 13);
    printf("Suma");
    
    printf("\033[7;36m");
    printf("\033[%d;%dH", 8, 10);
    printf("2.-");
    printf("\033[0m");
    printf("\033[%d;%dH", 8, 13);
    printf("Resta");
    
    printf("\033[7;35m");
    printf("\033[%d;%dH", 9, 10);
    printf("3.-");
    printf("\033[0m");
    printf("\033[%d;%dH", 9, 13);
    printf("Multiplicación");
    
    printf("\033[7;31m");
    printf("\033[%d;%dH", 10, 10);
    printf("4.-");
    printf("\033[0m");
    printf("\033[%d;%dH", 10, 13);
    printf("División");
    
    printf("\033[0m");
    printf("\033[%d;%dH", 11, 10);
    printf("Seleccione una opción ");
    
    printf("\033[7;33m");
    printf("\033[%d;%dH", 11, 32);
    printf("(1-4)");
    printf("\033[0m");
    printf("\033[%d;%dH", 11, 37);
    scanf("%d", &opc);
    
    switch (opc) {
    case 1:
        printf("\033[2J");
        printf("\033[%d;%dH", 5, 10);
        printf("Introduzca el primer número: ");
        scanf("%f", &n1);
        printf("\033[%d;%dH", 6, 10);
        printf("Introduzca el segundo número: ");
        scanf("%f", &n2);
        resultado = n1 + n2;
        printf("\033[%d;%dH", 7, 10);
        printf("\033[7;34m");
        printf("El resultado es: %.2f\n", resultado);
        break;
    case 2:
        printf("\033[2J");
        printf("\033[%d;%dH", 5, 10);
        printf("Introduzca el primer número: ");
        scanf("%f", &n1);
        printf("\033[%d;%dH", 6, 10);
        printf("Introduzca el segundo número: ");
        scanf("%f", &n2);
        resultado = n1 - n2;
        printf("\033[%d;%dH", 7, 10);
        printf("\033[7;36m");
        printf("El resultado es: %.2f\n", resultado);
        break;
    case 3:
        printf("\033[2J");
        printf("\033[%d;%dH", 5, 10);
        printf("Introduzca el primer número: ");
        scanf("%f", &n1);
        printf("\033[%d;%dH", 6, 10);
        printf("Introduzca el segundo número: ");
        scanf("%f", &n2);
        resultado = n1 * n2;
        printf("\033[%d;%dH", 7, 10);
        printf("\033[7;35m");
        printf("El resultado es: %.2f\n", resultado);
        break;
    case 4:
        printf("\033[2J");
        printf("\033[%d;%dH", 5, 10);
        printf("Introduzca numerador: ");
        scanf("%f", &n1);
        printf("\033[%d;%dH", 6, 10);
        printf("Introduzca el denominador: ");
        scanf("%f", &n2);
        if (n2 == 0) {
            printf("\033[%d;%dH", 7, 10);
            printf("\033[7;31m");
            printf("Error: División por cero.");
        } else {
            resultado = n1 / n2;
            printf("\033[%d;%dH", 7, 10);
            printf("\033[7;31m");
            printf("El resultado es: %.2f\n", resultado);
        }
        break;
    default:
        printf("\033[2J");
        printf("\033[0m");
        printf("Opción no válida");
        break;
    }
    printf("\033[0m");
}

void modificacionColoresDeterminante() {
    printf("\033[2J");
    printf("\033[%d;%dH", 3, 5);
    printf("Helloooo from (5,3)");
}

void multiplicacionEstructura() {
    struct tabla {
        int Valor1;
        int Valor2;
        int resultado;
    };
    
    struct tabla Arreglo[3] = {
        {1, 3, 0},
        {2, 3, 0},
        {3, 3, 0}
    };
    
    for (int i = 0; i < 3; i++) {
        int resultado = (Arreglo[i].Valor1) * (Arreglo[i].Valor2);
        Arreglo[i].resultado = resultado;
    }
    
    for (int i = 0; i < 3; i++) {
        printf("%d X %d = %d\n",
            Arreglo[i].Valor1,
            Arreglo[i].Valor2,
            Arreglo[i].resultado);
    }
}

void multiplicacionMatriz() {
    int fya;
    printf("Introduzca el número de filas y columnas que desea que tenga la matriz A y B: \n");
    scanf("%d", &fya);
    
    int matrizA[fya][fya], matrizB[fya][fya], matrizC[fya][fya];
    
    printf("Matriz A:\n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("Introduzca el valor para la matriz A en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }
    
    printf("Matriz A ingresada:\n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("|%2d| ", matrizA[i][j]);
        }
        printf("\n");
    }
    
    printf("Matriz B:\n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("Introduzca el valor para la matriz B en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }
    
    printf("Matriz B ingresada:\n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("|%2d| ", matrizB[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            int suma = 0;
            for (int k = 0; k < fya; k++) {
                suma += matrizA[i][k] * matrizB[k][j]; 
            }
            matrizC[i][j] = suma;
        }
    }
    
    printf("Matriz AB: \n");
    for (int i = 0; i < fya; i++) {
        for (int j = 0; j < fya; j++) {
            printf("|%2d| ", matrizC[i][j]);
        }
        printf("\n");
    }
}

void multiplicacionMatrizVector() {
    int filas, columnas, vectorcol, vectorfil;
    
    printf("Introduzca el número de filas que desea que tenga la matriz: \n");
    scanf("%d", &filas);
    printf("Introduzca el número de columnas que desea que tenga la matriz: \n");
    scanf("%d", &columnas);
    
    int matrizA[filas][columnas];
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Introduzca el valor para la matriz en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }
    
    printf("Matriz ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("|%2d| ", matrizA[i][j]);
        }
        printf("\n");
    }
    
    printf("Ingrese el total filas del vector por el cual desea multiplicar la matriz: \n");
    scanf("%d", &vectorfil);
    printf("Ingrese el total columnas del vector por el cual desea multiplicar la matriz: \n");
    scanf("%d", &vectorcol);
    
    if (vectorfil != columnas) {
        printf("Para que se pueda realizar la operación el número de columnas de la matriz que ha ingresado debe ser igual a el número de filas del vector.\n");
        return;
    }
    
    int matrizV[vectorfil][vectorcol];
    
    for (int i = 0; i < vectorfil; i++) {
        for (int j = 0; j < vectorcol; j++) {
            printf("Introduzca el valor para el vector en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizV[i][j]);
        }
    }
    
    printf("Vector ingresado:\n");
    for (int i = 0; i < vectorfil; i++) {
        for (int j = 0; j < vectorcol; j++) {
            printf("|%2d| ", matrizV[i][j]);
        }
        printf("\n");
    }
    
    int matrizresultado[filas][vectorcol];
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < vectorcol; j++) {
            int resultado = 0;
            for (int k = 0; k < columnas; k++) {
                resultado += matrizA[i][k] * matrizV[k][j];
            }
            matrizresultado[i][j] = resultado;
        }
    }
    
    printf("Resultado de la multiplicación de la matriz por el vector: \n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < vectorcol; j++) {
            printf("|%2d| ", matrizresultado[i][j]);
        }
        printf("\n");
    }
}

void operacionMatriz() {
    int filas, columnas;
    
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);
    
    int matriz_a[filas][columnas];
    int matriz_b[filas][columnas];
    int matriz_rsuma[filas][columnas];
    
    printf("Matriz A\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz_a[i][j]);
        }
    }
    
    printf("Matriz B\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz_b[i][j]);
        }
    }
    
    printf("Matriz A ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_a[i][j]);
        }
        printf("\n");
    }
    
    printf("Matriz B ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_b[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz_rsuma[i][j] = matriz_a[i][j] + matriz_b[i][j];
        }
    }
    
    printf("SUMA A+B:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d ", matriz_rsuma[i][j]);
        }
        printf("\n");
    }
    
    if (filas == 3 && columnas == 3) {
        // Calcular determinante con el método de Sarrus
        int det_a = 
            matriz_a[0][0] * matriz_a[1][1] * matriz_a[2][2] +
            matriz_a[0][1] * matriz_a[1][2] * matriz_a[2][0] +
            matriz_a[0][2] * matriz_a[1][0] * matriz_a[2][1] -
            matriz_a[0][2] * matriz_a[1][1] * matriz_a[2][0] -
            matriz_a[0][0] * matriz_a[1][2] * matriz_a[2][1] -
            matriz_a[0][1] * matriz_a[1][0] * matriz_a[2][2];
        
        printf("La determinante de la matriz A es: %d\n", det_a);
        
        int det_b = 
            matriz_b[0][0] * matriz_b[1][1] * matriz_b[2][2] +
            matriz_b[0][1] * matriz_b[1][2] * matriz_b[2][0] +
            matriz_b[0][2] * matriz_b[1][0] * matriz_b[2][1] -
            matriz_b[0][2] * matriz_b[1][1] * matriz_b[2][0] -
            matriz_b[0][0] * matriz_b[1][2] * matriz_b[2][1] -
            matriz_b[0][1] * matriz_b[1][0] * matriz_b[2][2];
        
        printf("La determinante de la matriz B es: %d\n", det_b);
    } else {
        printf("Las matrices no son 3x3, no se pueden calcular determinantes.\n");
    }
}

void operacionRegistro2() {
    int AH, AL, BL, BH, CL, CH, DL;
    
    printf("Ingrese valor AL: \n");
    scanf("%d", &AL);
    printf("Ingrese valor AH: \n");
    scanf("%d", &AH);
    printf("Ingrese valor BL: \n");
    scanf("%d", &BL);
    printf("Ingrese valor BH: \n");
    scanf("%d", &BH);
    printf("ingrese valor CL: \n");
    scanf("%d", &CL);
    printf("Ingrese el valor CH: \n");
    scanf("%d", &CH);
    
    DL = AH + AL;
    printf("La suma de AH y AL es: %d \n", DL);
    
    DL = AH - AL; 
    printf("La resta de AH - AL es: %d\n", DL);
    
    DL = AH / AL;
    printf("La división entre AH y AL es: %d\n", DL);
    
    DL = AH * AL; 
    printf("La multiplicación entre AH y AL es: %d\n", DL);
    
    DL = BH + BL;
    printf("La suma entre BH y BL es: %d\n", DL);
    
    DL = BH - BL;
    printf("La resta entre BH y BL es: %d\n", DL);
    
    DL = BH * BL; 
    printf("La multiplicación entre BH y BL: %d\n", DL);
    
    DL = BH / BL;
    printf("La división de BH entre BL es: %d\n", DL);
    
    DL = CH + CL;
    printf("La suma entre CH y CL: %d\n", DL);
    
    DL = CH - CL;
    printf("La resta entre CH y CL es: %d\n", DL);
    
    DL = CH * CL;
    printf("La multiplicación entre CH y CL es: %d\n", DL);
    
    DL = CH / CL;
    printf("La división entre CH y CL es: %d\n", DL);
}

void punteroDoble() {
    int numero = 42;
    int *ptr = &numero;
    int **ptr_doble = &ptr;

    printf("Valor del 'numero': %d\n", numero);
    printf("Direccion de 'numero': %p\n", (void*)&numero);

    printf("\nUsando puntero simple: \n");
    printf("Valor de 'ptr': %p\n", (void*)ptr);
    printf("Valor al que apunta 'ptr': %d\n", *ptr);
    printf("Direccion de 'ptr': %p\n", (void*)&ptr);
    
    printf("\nUsando puntero doble: \n");
    printf("Valor de 'ptr_doble': %p\n", (void*)ptr_doble);
    printf("Valor al que apunta 'ptr_doble': %p\n", (void*)*ptr_doble);
    printf("Valor al que apunta el puntero al que apunta 'ptr_doble': %d\n", **ptr_doble);
    printf("Direccion de 'ptr_doble': %p\n", (void*)&ptr_doble);
}

void punterosOperaciones() {
    float *ptr1, *ptr2, valores[2];
    
    for (int i = 0; i < 2; i++) {
        printf("Ingrese un valor: \n");
        scanf("%f", &valores[i]);
    }
    
    for (int i = 0; i < sizeof(valores) / sizeof(valores[1]); i++) {
        printf("Los valores que introdujo son: %.2f\n", valores[i]);
    }
    
    ptr1 = &valores[0];
    ptr2 = &valores[1];
    
    float mult = (*ptr1) * (*ptr2);
    float div = *ptr1 / *ptr2;
    float sum = *ptr1 + *ptr2;
    float resta = *ptr1 - *ptr2;
    
    printf("La multiplicación de estos valores es: %.2f\n", mult);
    printf("La división de estos valores es: %.2f\n", div);
    printf("La suma de estos valores es: %.2f\n", sum);
    printf("La resta de estos valores es: %.2f\n", resta);
    printf("La posición del valor %.2f es: %p\n", *ptr1, ptr1);
    printf("La posición del valor %.2f es: %p\n", *ptr2, ptr2);
}

void punteroSuma() {
    int arr1[25], i, n;
    
    printf("\nPointer : Store and retrieve elements from an array:\n");
    printf("-----------------------------------------------------------\n");
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &n);  
    
    printf("Input %d number of elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", arr1 + i);  
    }
    
    printf("The elements you entered are: \n");
    for (i = 0; i < n; i++) {
        printf("element - %d: %d %p\n", i, *(arr1 + i), &arr1[i]);
    }
}

void setcolorFunc() {
    printf("\033[23");
    printf("\033[4;36m");
    printf("\nBienvenido al programa con marco y colores:\n");
    printf("\033[0m");
    printf("\033[7;34m");
    printf("\nBienvenido al programa con marco y colores:\n");
    printf("\033[0m");
    printf("\033[4;34m");
    printf("\nBienvenido al programa con marco y colores 2:\n");
}

void sprintfFunc() {
    char buffer[100];
    float pi = 3.14159;
    sprintf(buffer, "The value of pi is %.2f.", pi);
    printf("%s\n", buffer);
}

void tablaMultiplicar() {
    int tabla;
    printf("Ingresa la tabla de multiplicar que quieres ver: \n");
    scanf("%d", &tabla);
    for(int i = 1; i <= tabla; i++) {
        printf("La tabla de multiplicar de %d es: \n", i);
        for(int j = 1; j <= 10; j++) {
            int resultado = i * j;
            printf("%d x %d = %d\n", i, j, resultado);
        }
        printf("\n");
    }
}

void transpuestaMatriz() {
    int filas, columnas;
    printf("Introduzca el número de filas que desea que tenga la matriz: \n");
    scanf("%d", &filas);
    printf("Introduzca el número de columnas que desea que tenga la matriz: \n");
    scanf("%d", &columnas);
    int matrizor[filas][columnas];
    
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("Introduzca el valor para la matriz en la posición [%d] [%d]: ", i, j);
            scanf("%d", &matrizor[i][j]);
        }
    }
    
    printf("Recorriendo la matriz.\n");
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("|%2d| ", matrizor[i][j]);
        }
        printf("\n");
    }
    
    int matriztp[columnas][filas];
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            matriztp[j][i] = matrizor[i][j];
        }
    }
    
    printf("Matriz transpuesta: \n");
    for(int i = 0; i < columnas; i++) {
        for(int j = 0; j < filas; j++) {
            printf("|%2d| ", matriztp[i][j]);
        }
        printf("\n");
    }
}

void trianguloColores() {
    int N;
    printf("Introduzca el numero de filas del triángulo: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        printf("\033[0m");
        for(int espacios = 1; espacios <= N-i; espacios++) {
            printf(" ");
        }
        printf("\033[7;33m");
        for(int j = 1; j <= i*2-1; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\033[0m");
}

void unionFunc() {
    union Dato {
        int entero;
        float decimal;
        char texto[20];
    };
    
    union Dato variable;
    variable.entero = 42;

    printf("Entero: %d\n", variable.entero);
    variable.decimal = 3.14;
    
    printf("Decimal: %.2f\n", variable.decimal);
    sprintf(variable.texto, "Hola C");
    printf("Texto: %s\n", variable.texto);

    printf("\nDespués de asignar un texto: \n");
    printf("Entero: %d\n", variable.entero);
    printf("Decimal: %.2f\n", variable.decimal);
    printf("Texto: %s\n", variable.texto);
}

void vehiculoUnion() {
    struct Vehiculo {
        char num_llantas[10];  
        char color[20];  
        char hp[10];
    };
    
    struct Camion {
        char num_asientos[10];
        char num_puertas[10];
    };

    struct Motocicleta {
        char cilindrada[10];
        char tipo[20];
    };

    union TipoVehiculo {
        struct Camion camion;
        struct Motocicleta moto;
    };

    struct VehiculoCompleto {
        struct Vehiculo datos_generales;
        int tipo;
        union TipoVehiculo especifico;
    };

    struct VehiculoCompleto vehiculo;

    printf("Ingrese la cantidad de llantas: ");
    scanf("%s", vehiculo.datos_generales.num_llantas);
    
    printf("Ingrese el color del vehiculo: ");
    scanf("%s", vehiculo.datos_generales.color);

    printf("Ingrese la cantidad de caballos de fuerza: ");
    scanf("%s", vehiculo.datos_generales.hp);

    printf("Que tipo de veiculo es?\n");
    printf("1:Camion\n");
    printf("2:Motocicleta\n");
    scanf("%d", &vehiculo.tipo);

    switch (vehiculo.tipo){
        case 1:
            printf("Ingrese la cantidad de asientos del camion: ");
            scanf("%s", vehiculo.especifico.camion.num_asientos);

            printf("Ingrese la cantidad de puertas del camion: ");
            scanf("%s", vehiculo.especifico.camion.num_puertas);
            break;
        
        case 2:
            printf("Ingrese la cilindrada de la motocicleta: ");
            scanf("%s", vehiculo.especifico.moto.cilindrada);

            printf("Ingrese el tipo de motocicleta: ");
            scanf("%s", vehiculo.especifico.moto.tipo);
            break;
        
        default:
            printf("Tipo de vehiculo no valido.\n");
    }

    printf("\n\n");
    printf("Cantidad de llantas: %s\n", vehiculo.datos_generales.num_llantas);
    printf("Color: %s\n", vehiculo.datos_generales.color);
    printf("Caballos de fuerza: %s hp\n", vehiculo.datos_generales.hp);

    switch (vehiculo.tipo) {
        case 1:
            printf("Tipo: Camion\n");
            printf("Cantidad de asientos: %s\n", vehiculo.especifico.camion.num_asientos);
            printf("Cantidad de puertas: %s\n", vehiculo.especifico.camion.num_puertas);
            break;
        
        case 2:
            printf("Tipo: Motocicleta\n");
            printf("Cilindrada: %s cc\n", vehiculo.especifico.moto.cilindrada);
            printf("Tipo de motocicleta: %s\n", vehiculo.especifico.moto.tipo);
            break;
    }
 }