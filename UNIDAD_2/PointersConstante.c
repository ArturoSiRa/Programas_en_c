#include <stdio.h>}
int main(){
int a,b,c,d,e;
printf("Ingrese el valor de A \n");
scanf("%d", &a);
printf("Ingrese el valor de B \n");
scanf("%d", &b);
printf("Ingrese el valor de C \n");
scanf("%d", &c);
printf("Ingrese el valor de D \n");
scanf("%d", &d);
printf("Ingrese el valor de E \n");
scanf("%d", &e);

int *const pa = &a;
int *const pb = &b;
int *const pc = &c;
int *const pd = &d;
int *const pe = &e;

printf("Ingrese los valores ingresados A=%p\n", &pa);
printf("Ingrese los valores ingresados B=%p\n", &pb);
printf("Ingrese los valores ingresados C=%p\n", &pc);
printf("Ingrese los valores ingresados D=%p\n", &pd);
printf("Ingrese los valores ingresados E=%p\n", &pe);

int suma= *pa + *pa;
printf("Resultado de la suma: %d\n", suma);

*pa = suma;
printf("Valor nuevo: A=%d\n", *pa);

int resta= *pb - *pb;
printf("Resultado de la suma: %d\n", resta);

*pb = resta;
printf("Valor nuevo: B=%d\n", *pb);

int mult= *pc * *pc;
printf("Resultado de la suma: %d\n", mult);

*pc = mult;
printf("Valor nuevo: C=%d\n", *pc);

int div= *pd / *pd;
printf("Resultado de la suma: %d\n", div);

*pd = div;
printf("Valor nuevo: A=%d\n", *pd);

return 0;
}