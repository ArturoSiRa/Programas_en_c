void limpiarpantalla (){
    printf("\033[2]");
}
void gotoxy(int x, int y){
    printf("\033[%d; %dH", x, y);
}
int main (){
    limpiarpantalla();
    gotoxy (5, 3);
    printf("Helloud from(5, 3)");
    }
