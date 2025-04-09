#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char asignatura[3][30];
    char estudiantes[5][30];
    float notas[3][5];
    float promedio[3][5];
    float spp, promedioF;
    float minNota, maxNota;
    int opc1, cont = 0, len;
    int aprobados, reprobados;
    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Registro nombres\n");
        printf("2. Registro asignatura y notas\n");
        printf("3. Notas finales\n");
        printf("4. Salir\n");
        printf(">> ");
        scanf("%d", &opc1);
        switch (opc1)
        {
        case 1:
            // Registro de nombres de estudiantes
            for (int i = 0; i < 5; i++)
            {
                printf("Nombre estudiante %d: ", i + 1);
                fflush(stdin);
                fgets(estudiantes[i], 30, stdin);
                len = strlen(estudiantes[i]) - 1;
                estudiantes[i][len] = '\0';
            }
            break;

        case 2:
            // Registro de asignatura y notas
            printf("Ingrese la asignatura %d: ", cont + 1);
            fflush(stdin);
            fgets(asignatura[cont], 30, stdin);
            len = strlen(asignatura[cont]) - 1;
            asignatura[cont][len] = '\0';
            for (int i = 0; i < 5; i++)
            {
                
                printf("%s - Ingrese la nota en la materia %s: ", estudiantes[i], asignatura[cont]);
                scanf("%f", &notas[cont][i]);
                if (notas[cont][i] > 10 || notas[cont][i] < 0)
                {
                    do
                    {
                        printf("Ese no es un numero valido\n");
                        printf("%s - Ingrese la nota en la materia %s: ", estudiantes[i], asignatura[cont]);
                        scanf("%f", &notas[cont][i]);
                    } while (notas[cont][i] > 10 || notas[cont][i] < 0);
                }
                
            }
            cont++;
            break;
        case 3:

            for (int i = 0; i < 5; i++)
            {
                spp = 0;
                for (int t = 0; t < 3; t++)
                {

                    spp += notas[t][i];
                }
                promedioF = spp / 3;

                printf("%s - %.2f\n", estudiantes[i], promedioF);
            }



            for (int t = 0; t < 3; t++) 
            {
                spp = 0;
                for (int i = 0; i < 5; i++) 
                {
                    spp += notas[t][i];
                }
                float promedioMateria = spp / 5;
                printf("%s - Promedio: %.2f\n", asignatura[t], promedioMateria);
            }

            break;

        case 4:
            printf("Notas mas altas y bajas por Estudiante\n");
            for (int i = 0; i < 5; i++) 
            {
                maxNota = notas[0][i]; 
                minNota = notas[0][i]; 

                for (int t = 1; t < 3; t++) 
                {
                    if (notas[t][i] > maxNota) // Si encontramos una nota más alta
                        maxNota = notas[t][i];
                    if (notas[t][i] < minNota) // Si encontramos una nota más baja
                        minNota = notas[t][i];
                }

                printf("%s - Nota más alta: %.2f, Nota más baja: %.2f\n", estudiantes[i], maxNota, minNota);
            }
            break;



            case 5:
            printf(" \t aprobados y reprobasdos \n");
            for (int t = 0; t < 3; t++) 
            {
                aprobados = 0;  
                reprobados = 0; 
                
                printf("Asignatura: %s\n", asignatura[t]);
                
                for (int i = 0; i < 5; i++) 
                {
                    if (notas[t][i] >= 6)  
                    {
                        printf("%s - Aprobado: %.2f\n", estudiantes[i], notas[t][i]);
                        aprobados++;  
                    }
                    else  
                    {
                        printf("%s - Reprobado: %.2f\n", estudiantes[i], notas[t][i]);
                        reprobados++;  
                    }
                }
        
                printf("\t cantidad re y apro %s:\n", asignatura[t]);
                printf("Aprobados: %d\n", aprobados);
                printf("Reprobados: %d\n", reprobados);
            }
            break;


        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida. Intente nuevamente.\n");
            break;
        }
    } while (opc1 != 6);

    return 0;
}