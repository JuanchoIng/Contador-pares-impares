#include <stdio.h>

int main (int argc, char *argv[]) {

float p_diametro, p_altura;
float a=1, n, contador_n=0, contador_a=0, contador_do=0, d;
char opc;

do
{
    
    printf("Cuantos arboles desea calcular el promedio tanto de diametro como de altura?\n");
scanf("%f", &contador_a);
do
{
    printf("Escriba la altura del arbol numero %.0f \n", a );
    scanf("%f", &n);
    contador_n=contador_n+n;
    

    printf("Escriba el diametro del arbol numero %.0f \n", a );
    scanf("%f", &d);
    p_diametro=p_diametro+d;

    a=a+1;
    contador_do=contador_do+1;
} while (contador_do<contador_a);

contador_n=contador_n/contador_a;

printf("El promedio de altura es: %.0f m\n", contador_n);

p_diametro=p_diametro/contador_a;

printf("El promedio de diametro es: %.0f cm\n ", p_diametro);

printf("Desea continuar S/N\n");
scanf(" %c", &opc);

if (opc == 'N' || opc == 'n') {
printf("Programa terminado.\n");
}

} while (opc == 'S' || opc == 's');




    return 0;
}
