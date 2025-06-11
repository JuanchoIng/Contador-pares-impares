#include <stdio.h>
#include <string.h>
#include "funciones.h"

int registrarLibro(struct Libro libros[], int cantidadLibros) {
    if (cantidadLibros >= MAX_LIBROS) {
        printf("Ya no se pueden agregar más libros.\n");
        return cantidadLibros;
    }

    int id;
    printf("Ingrese el ID del libro: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < cantidadLibros; i++) {
        if (libros[i].id == id) {
            printf("Ese ID ya está registrado.\n");
            return cantidadLibros;
        }
    }

    printf("Ingrese el título del libro: ");
    fgets(libros[cantidadLibros].titulo, sizeof(libros[cantidadLibros].titulo), stdin);
    libros[cantidadLibros].titulo[strcspn(libros[cantidadLibros].titulo, "\n")] = 0;

    printf("Ingrese el autor del libro: ");
    fgets(libros[cantidadLibros].autor, sizeof(libros[cantidadLibros].autor), stdin);
    libros[cantidadLibros].autor[strcspn(libros[cantidadLibros].autor, "\n")] = 0;

    printf("Ingrese el año de publicación del libro: ");
    scanf("%d", &libros[cantidadLibros].anioPublicacion);
    getchar();

    strcpy(libros[cantidadLibros].estado, "Disponible");
    libros[cantidadLibros].id = id;
    cantidadLibros++;
    printf("Libro registrado exitosamente.\n");
    return cantidadLibros;
}

void mostrarLibros(struct Libro libros[], int cantidadLibros) {
    printf("\nID\tTítulo\tAutor\tAño\tEstado\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < cantidadLibros; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n",
            libros[i].id,
            libros[i].titulo,
            libros[i].autor,
            libros[i].anioPublicacion,
            libros[i].estado);
    }
}

int buscarLibroPorId(struct Libro libros[], int cantidadLibros, int id) {
    for (int i = 0; i < cantidadLibros; i++) {
        if (libros[i].id == id) {
            return i;
        }
    }
    return -1;
}

int buscarLibroPorTitulo(struct Libro libros[], int cantidadLibros, const char *titulo) {
    for (int i = 0; i < cantidadLibros; i++) {
        if (strstr(libros[i].titulo, titulo) != NULL) {
            return i;
        }
    }
    return -1;
}

void mostrarInformacionLibro(struct Libro libro) {
    printf("\nID: %d\nTítulo: %s\nAutor: %s\nAño de publicación: %d\nEstado: %s\n",
        libro.id, libro.titulo, libro.autor, libro.anioPublicacion, libro.estado);
}

void actualizarEstadoLibro(struct Libro libros[], int cantidadLibros, int id) {
    int pos = buscarLibroPorId(libros, cantidadLibros, id);
    if (pos == -1) {
        printf("Libro no encontrado.\n");
        return;
    }
    if (strcmp(libros[pos].estado, "Disponible") == 0) {
        strcpy(libros[pos].estado, "Prestado");
    } else {
        strcpy(libros[pos].estado, "Disponible");
    }
    printf("Estado actualizado correctamente.\n");
}

int eliminarLibro(struct Libro libros[], int cantidadLibros, int id) {
    int pos = buscarLibroPorId(libros, cantidadLibros, id);
    if (pos == -1) {
        printf("Libro no encontrado.\n");
        return cantidadLibros;
    }
    for (int i = pos; i < cantidadLibros - 1; i++) {
        libros[i] = libros[i + 1];
    }
    printf("Libro eliminado correctamente.\n");
    return cantidadLibros - 1;
}





