#include <stdio.h>

void gotoxy (int x, int y){
    printf("\033[%d; %dH", y, x);  //GANSI escape sequence
}

int main (){
    printf("\033[2j"); //Limpia pantalla
    gotoxy(10,5);
    printf("Hola desde(10, 5)!");
    return 0; 
}