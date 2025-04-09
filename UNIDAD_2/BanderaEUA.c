#include <stdio.h>

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void setColor(const char* color) {
    printf("%s", color);
}

int main (){
    for(int i=0;i<=3;i++){
    int limitey1 =0;

    while (limitey1 >= 0) {
    int limitex1 = 4;

    while (limitex1 >= 0){
    setColor("\033[7;34m");
    printf("%4s", "");
    
  limitex1--;
 }
  limitey1--;
 }

 int limitey2 =0;
 while (limitey2 >= 0) {
int limitex2 = 8;
 while (limitex2 >= 0){
 setColor("\033[7;31m");
printf("%4s", "");
limitex2--;
}
printf("\n");
limitey2--;
}

int limitey3 =0;
while (limitey3 >= 0) {
int limitex3 = 4;
while (limitex3 >= 0){
setColor("\033[7;34m");
printf("%4s", "");
limitex3--;
}
limitey3--;
}

int limitey4 =0;
while (limitey4 >= 0) {
int limitex4 = 8;
while (limitex4 >= 0){
setColor("\033[7;37m");
printf("%4s", "");
limitex4--;
}
printf("\n");
limitey4--;
}
    }
    
    for(int i=0;i<=3;i++){


 int limitey5 =0;
 while (limitey5 >= 0) {
int limitex5 = 13;
 while (limitex5 >= 0){
 setColor("\033[7;31m");
printf("%4s", "");
limitex5--;
}
printf("\n");
limitey5--;
}


int limitey6 =0;
while (limitey6 >= 0) {
int limitex6 = 13;
while (limitex6 >= 0){
setColor("\033[7;37m");
printf("%4s", "");
limitex6--;
}
printf("\n");
limitey6--;
}
    }

 return 0;     
}


