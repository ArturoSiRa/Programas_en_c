#include <stdio.h>
#include <stdbool.h>

bool flag = false;


bool buscraiz(int num) {
    for (int i = 1; i * i <= num; i++) {
        if (i * i == num) {
            flag = true;
            break;
        }
    }
    return flag;
}

int raizc(int num) {
    for (int i = 1; i * i <= num; i++) {
        if (i * i == num) {
            return i;
        }
    }
    return 0;
}

void ingmat(int raiz, char matr[raiz][raiz]) {
    printf("Introduce %d caracteres:\n", raiz * raiz);
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("Introduce la posicion [%d][%d]: ", i + 1, j + 1);
            scanf(" %c", &matr[i][j]);  
        }
    }
}

void ImpMat(int raiz, char matr[raiz][raiz]) {
    printf("Los caracteres son:\n");
    for (int i = 0; i < raiz; i++) {
        for (int j = 0; j < raiz; j++) {
            printf("%c ", matr[i][j]);
        }
    }
}

int main() {
    int num;
    printf("Introduce un número: ");
    scanf("%d", &num);
    
    if (buscraiz(num)) {
        int raiz = raizc(num);
        printf("La raíz cuadrada de %d es %d.\n", num, raiz);
        
        char matr[raiz][raiz]; 
        
        ingmat(raiz, matr);
        ImpMat(raiz, matr);
    } else {
        printf("No tiene una raíz exacta.\n");
    }
    
    return 0;
}