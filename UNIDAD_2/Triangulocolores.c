#include <stdio.h>
 
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
 
// Función para cambiar el color
void setColor(const char* color) {
    printf("%s", color);
}
int main(){
    printf("\033[2J"); // Limpia la pantalla
    int asteriscos=1;
    for (int i=6; i>=0; i--){
    for (int j=1; j<=asteriscos; j++){
setColor("\033[7;31m");
printf("%s", " ");
}
asteriscos ++; 
printf("\n");
}
}
