#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}

int main(){
    int opc, num1, num2;
        float result;
    printf("\033[2J"); // Limpia la pantalla
    
    setColor("\033[7;32m");
    gotoxy(10,5);
    printf("Calculadora Basica con gotoxy y swithc-case: ");

    setColor("\033[4;30m");
    gotoxy(10,6);
    printf("Menú de operaciones: ");


    setColor("\033[7;31m");
    gotoxy(30,7);
    printf("1.-: ");

    setColor("\033[0m");
    gotoxy(31,7);
    printf("Suma: ");

    setColor("\033[7;33m");
    gotoxy(30,8);
    printf("2.-: ");

    setColor("\033[0m");
    gotoxy(31,8);
    printf("Resta: ");

    setColor("\033[7;36m");
    gotoxy(30,9);
    printf("3.-: ");

    setColor("\033[0m");
    gotoxy(31,9);
    printf("Multiplciación: ");


    setColor("\033[7;35m");
    gotoxy(30,10);
    printf("4.-: ");

    setColor("\033[0m");
    gotoxy(31,10);
    printf("División: ");

    setColor("\033[0m");
    gotoxy(30,11);
    printf("Seleccione una opcion: ");

    setColor("\033[7;33m");
    gotoxy(55,11);
    printf("(1-4)");

scanf("%d", &opc);
switch(opc){
        case 1: 
            printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado suma");
            printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1+num2; 
            setColor("\033[7;31m");
            gotoxy(30,7);
            printf("Tu resultado es: %.2f\n", result);
            
            break; 
        case 2:
            printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado resta");
            printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1-num2;
            setColor("\033[7;33m");
            gotoxy(30,8);
            printf("Tu resultado es:%.2f\n", result);


            break;
        case 3:
             printf("\033[2J"); // Limpia la pantalla
            setColor("\033[0m");
            printf ("%s\n", "Ha seleccionado multiplicación");
             printf("Dame el primer número"); 
            scanf("%d", &num1);
            printf("Dame el segundo número"); 
            scanf("%d", &num2);
            result=num1*num2;
            setColor("\033[7;36m");
            gotoxy(30,9);
            printf("Tu resultado es:%.2f\n", result);
            break;  



        case 4:
        printf("\033[2J"); // Limpia la pantalla
        setColor("\033[0m");
        printf ("%s\n", "Ha seleccionado división");
        printf("Dame el primer número"); 
        scanf("%d", &num1);
        printf("Dame el segundo número"); 
        scanf("%d", &num2);
        if (num2==0){
        setColor("\033[7;35m");
        gotoxy(30,10);
            printf("No se puede hacer la operacion\n");
        
        }else {
        result=num1/num2;
        setColor("\033[7;35m");
        gotoxy(30,10);
        printf("Tu resultado es: %.2f\n", result);
        }

         break; 
        default:
        printf("%s\n", "No ha seleccionado una opción válida");
        break; 
    }
    return 0; 
}




