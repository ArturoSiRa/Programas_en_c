#include <stdio.h>
int main(){
int al,ah,bh,bl,ch,cl, dl;
printf("Ingrese el valor de AL \n");
scanf("%d", &al);
printf("Ingrese el valor de AH \n");
scanf("%d", &ah);
printf("Ingrese el valor de BL \n");
scanf("%d", &bl);
printf("Ingrese el valor de BH \n");
scanf("%d", &bh);
printf("Ingrese el valor de CL \n");
scanf("%d", &cl);
printf("Ingrese el valor de CH \n");
scanf("%d", &ch);

int *const pal = &al;
int *const pah = &ah;
int *const pbh = &bh;
int *const pbl = &bl;
int *const pch = &ch;
int *const pcl= &cl;
int *const pdl= &dl;


printf(" SUMA   RESTA   DIV    MULT  \n");
//AL U AH
int suma= *pal + *pah;

*pdl = suma;
printf("%-6d  ", *pdl);

int resta= *pal - *pah;

*pdl = resta;
printf("%-6d  ", *pdl);

int mult= (*pal * *pah);

*pdl = mult;
printf("%-6d  ", *pdl);

int div= *pal / *pah;

*pdl = div;
printf("%-6d  \n", *pdl);


//BL Y BH
suma= *pbl + *pbh;

*pdl = suma;
printf("%-6d  ", *pdl);

resta= *pbl - *pbh;

*pdl = resta;
printf("%-6d  ", *pdl);

mult= (*pbl * *pbh);

*pdl = mult;
printf("%-6d  ", *pdl);

div= *pbl / *pbh;

*pdl = div;
printf("%-6d  \n", *pdl);

//CL Y CH
suma= *pcl + *pch;

*pdl = suma;
printf("%-6d  ", *pdl);

resta= *pcl - *pch;

*pdl = resta;
printf("%-6d  ", *pdl);

mult= (*pcl * *pch);

*pdl = mult;
printf("%-6d  ", *pdl);

div= *pcl / *pch;

*pdl = div;
printf("%-6d  \n", *pdl);

return 0;
}
