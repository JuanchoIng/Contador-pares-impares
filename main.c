#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct Libro libros[MAX_LIBROS];
    int cantidadLibros = 0;
    int opcion;

    do {
        printf("\n--- Biblioteca ---\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Buscar libro por título\n");
        printf("5. Actualizar estado de libro\n");
        printf("6. Eliminar libro\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        if (opcion == 1) {
            cantidadLibros = registrarLibro(libros, cantidadLibros);
        } else if (opcion == 2) {
            mostrarLibros(libros, cantidadLibros);
        } else if (opcion == 3) {
            int id;
            printf("Ingrese el ID del libro: ");
            scanf("%d", &id);
            getchar();
            int pos = buscarLibroPorId(libros, cantidadLibros, id);
            if (pos != -1) {
                mostrarInformacionLibro(libros[pos]);
            } else {
                printf("Libro no encontrado.\n");
            }
        } else if (opcion == 4) {
            char titulo[100];
            printf("Ingrese el título del libro: ");
            fgets(titulo, sizeof(titulo), stdin);
            int pos = buscarLibroPorTitulo(libros, cantidadLibros, titulo);
            if (pos != -1) {
                mostrarInformacionLibro(libros[pos]);
            } else {
                printf("Libro no encontrado.\n");
            }
        } else if (opcion == 5) {
            int id;
            printf("Ingrese el ID del libro: ");
            scanf("%d", &id);
            getchar();
            actualizarEstadoLibro(libros, cantidadLibros, id);
        } else if (opcion == 6) {
            int id;
            printf("Ingrese el ID del libro a eliminar: ");
            scanf("%d", &id);
            getchar();
            cantidadLibros = eliminarLibro(libros, cantidadLibros, id);
        } else if (opcion == 0) {
            printf("Saliendo...\n");
        } else {
            printf("Opción no válida.\n");
        }
    } while (opcion != 0);

    return 0;
}