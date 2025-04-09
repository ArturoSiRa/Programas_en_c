#include <stdio.h>
void setcolor(const char* color){  //n cantidad de caracteres
    printf("%s", color);
}

int main(){
  //Limpiar pantalla
    printf("033[2j"); 

    setcolor ("\033[4;36m"); 
    printf("\n Bienvenido al programa con marco y colores"); 

    //Restaurar color
    setcolor ("\033[0m");

    setcolor("\033[7;34m"); 
    printf("\nBienvenido al programa con marco y colores!\n");

    setcolor("\033[0m");

    setcolor("\033[4;34m");
    printf("Bienvenido al programa con marco y colores 2!\n");
    
    return 0;

}