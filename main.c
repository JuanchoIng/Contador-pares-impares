#include <stdio.h>

int main (int argc, char *argv[]) {


    float impar = 0, par = 0;
    int n, b = 2;

    printf("Contador pares/impares\n");
    do {
        printf("Escriba un numero:\n");
        scanf("%d", &n);

        int a = n % b; 
        if (a == 1)
        { 
            impar = impar + 1;
        } else if (a == 0)
        { 
            
            par = par + 1;
        }

        printf("Existen %.0f numeros pares y %.0f numeros impares\n", par, impar);
    } while (n > 0);

 





    return 0;
}