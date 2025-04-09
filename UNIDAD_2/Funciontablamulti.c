#include <stdio.h>
void tablamulti(int a) {
for (int i = 1; i <= 10; i++) {
        int resultado = a * i;
        printf("%d x %d = %d\n", a, i, resultado);
    }
}

int main() {
    int a;
    printf("Introduce un número para ver su tabla de multiplicar: ");
    scanf("%d", &a);
    tablamulti(a);

    return 0;
}
