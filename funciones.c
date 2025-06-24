#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> // Include for fixed-width integer types
#include <ctype.h>
#include "funciones.h"

void ensureFileExists(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (file) {
        fclose(file);
    }
}

void menu() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Agregar Producto\n");
    printf("2. Mostrar Stock\n");
    printf("3. Registrar Venta\n");
    printf("4. Mostrar Ventas\n");
    printf("0. Salir\n");
}

void agregarProducto() {
    ensureFileExists("stock.dat");
    Producto producto;
    FILE *file = fopen("stock.dat", "ab");
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    int id;
    do {
        printf("Ingrese ID del producto (numero entero positivo): ");
        if (scanf("%d", &id) != 1 || id <= 0) { // Validate input
            printf("ID invalido. Intente nuevamente.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        producto.id = id; // Assign ID to the product
        break;
    } while (1);

    printf("Ingrese nombre del producto: ");
    scanf("%s", producto.nombre);
    printf("Ingrese cantidad: ");
    scanf("%d", &producto.cantidad);
    printf("Ingrese precio: ");
    scanf("%f", &producto.precio);
    fwrite(&producto, sizeof(Producto), 1, file);
    fclose(file);
    printf("Producto agregado exitosamente.\n");
}

void agregarPiezaPorID() {
    int id;
    Producto producto;
    FILE *file = fopen("stock.dat", "ab");
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("Ingrese ID de la pieza: ");
    scanf("%d", &id);
    printf("Ingrese nombre de la pieza: ");
    scanf("%s", producto.nombre);
    printf("Ingrese cantidad: ");
    scanf("%d", &producto.cantidad);
    printf("Ingrese precio: ");
    scanf("%f", &producto.precio);
    fwrite(&producto, sizeof(Producto), 1, file);
    fclose(file);
    printf("Pieza agregada exitosamente.\n");
}

void mostrarStock() {
    ensureFileExists("stock.dat");
    ensureFileExists("piezas_daniadas.dat"); // Ensure the damaged pieces file exists

    Producto producto;
    PiezaDaniada piezaDaniada;
    FILE *stockFile = fopen("stock.dat", "rb");
    FILE *damagedFile = fopen("piezas_daniadas.dat", "rb");
    if (!stockFile || !damagedFile) {
        printf("Error al abrir los archivos.\n");
        if (stockFile) fclose(stockFile);
        if (damagedFile) fclose(damagedFile);
        return;
    }

    printf("\n--- Stock ---\n");
    while (fread(&producto, sizeof(Producto), 1, stockFile)) {
        int cantidadDaniada = 0; // Track damaged quantity for the product

        // Check for damaged pieces
        rewind(damagedFile); // Reset file pointer for damaged pieces
        while (fread(&piezaDaniada, sizeof(PiezaDaniada), 1, damagedFile)) {
            if (strcmp(piezaDaniada.nombre, producto.nombre) == 0) {
                cantidadDaniada += piezaDaniada.cantidad; // Sum up damaged quantity
            }
        }

        // Display usable stock (nuevo + reparado)
        int cantidadUtilizable = producto.cantidad - cantidadDaniada;
        if (cantidadUtilizable > 0) {
            printf("Nombre: %s, Cantidad: %d, Estado: Utilizable (nuevo/reparado)\n", producto.nombre, cantidadUtilizable);
        }

        // Display damaged stock
        if (cantidadDaniada > 0) {
            printf("Nombre: %s, Cantidad: %d, Estado: Dañado\n", producto.nombre, cantidadDaniada);
        }
    }

    fclose(stockFile);
    fclose(damagedFile);
}

void registrarVenta() {
    ensureFileExists("ventas.dat"); // Ensure the file exists
    Venta venta;
    FILE *file = fopen("ventas.dat", "ab"); // Open file in append mode
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("Ingrese nombre del cliente: ");
    scanf("%s", venta.cliente);
    printf("Ingrese nombre del producto: ");
    scanf("%s", venta.producto);
    printf("Ingrese cantidad: ");
    scanf("%d", &venta.cantidad);
    printf("Ingrese total: ");
    scanf("%f", &venta.total);

    if (fwrite(&venta, sizeof(Venta), 1, file) != 1) { // Validate write operation
        printf("Error al guardar la venta.\n");
    } else {
        printf("Venta registrada exitosamente.\n");
    }
    fclose(file);
}

void mostrarVentas() {
    ensureFileExists("ventas.dat"); // Ensure the file exists
    Venta venta;
    FILE *file = fopen("ventas.dat", "rb");
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("\n--- Ventas ---\n");
    int found = 0; // Flag to check if any sales exist
    while (fread(&venta, sizeof(Venta), 1, file)) {
        if (feof(file)) break; // Ensure EOF is handled correctly
        found = 1; // Set flag if a sale is found
        printf("Cliente: %s, Producto: %s, Cantidad: %d, Total: %.2f\n", venta.cliente, venta.producto, venta.cantidad, venta.total);
    }
    if (!found) {
        printf("No hay ventas registradas.\n"); // Display message if no sales exist
    }
    fclose(file);
}

void comprarProducto() {
    ensureFileExists("stock.dat");
    ensureFileExists("piezas_daniadas.dat"); // Ensure the damaged pieces file exists
    ensureFileExists("ventas.dat"); // Ensure the sales file exists

    Producto producto;
    PiezaDaniada piezaDaniada;
    FILE *stockFile = fopen("stock.dat", "rb+");
    FILE *damagedFile = fopen("piezas_daniadas.dat", "rb");
    if (!stockFile || !damagedFile) {
        printf("Error al abrir los archivos.\n");
        if (stockFile) fclose(stockFile);
        if (damagedFile) fclose(damagedFile);
        return;
    }

    char nombre[50];
    int cantidad;
    int cantidadDaniada = 0; // Track damaged quantity for the product

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre);
    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidad);

    // Check for damaged pieces
    while (fread(&piezaDaniada, sizeof(PiezaDaniada), 1, damagedFile)) {
        if (strcmp(piezaDaniada.nombre, nombre) == 0) {
            cantidadDaniada += piezaDaniada.cantidad; // Sum up damaged quantity
        }
    }
    fclose(damagedFile);

    // Process the purchase
    while (fread(&producto, sizeof(Producto), 1, stockFile)) {
        if (strcmp(producto.nombre, nombre) == 0 && producto.cantidad - cantidadDaniada >= cantidad) {
            producto.cantidad -= cantidad; // Deduct purchased quantity
            int64_t offset = -(int64_t)sizeof(Producto); // Use int64_t for the offset
            if (fseek(stockFile, offset, SEEK_CUR) != 0) { // Check fseek result
                perror("Error al mover el puntero del archivo de stock");
                fclose(stockFile);
                return;
            }
            fwrite(&producto, sizeof(Producto), 1, stockFile);

            // Register the sale
            Venta venta;
            strcpy(venta.cliente, "Cliente"); // Placeholder for client name
            strcpy(venta.producto, nombre);
            venta.cantidad = cantidad;
            venta.total = cantidad * producto.precio;

            FILE *ventasFile = fopen("ventas.dat", "ab");
            if (!ventasFile) {
                printf("Error al abrir el archivo de ventas.\n");
                fclose(stockFile);
                return;
            }
            if (fwrite(&venta, sizeof(Venta), 1, ventasFile) != 1) {
                printf("Error al registrar la venta.\n");
            } else {
                printf("Compra realizada exitosamente y venta registrada.\n");
            }
            fclose(ventasFile);
            fclose(stockFile);
            return;
        }
    }
    printf("Producto no disponible o cantidad insuficiente.\n");
    fclose(stockFile);
}

void devolverProductoDaniado() { // Updated function name
    ensureFileExists("piezas_daniadas.dat"); // Updated filename
    PiezaDaniada pieza; // Updated struct name
    FILE *file = fopen("piezas_daniadas.dat", "ab"); // Updated filename
    if (!file) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    printf("Ingrese ID de la pieza daniada: "); // Removed tilde
    scanf("%d", &pieza.id);
    printf("Ingrese nombre de la pieza daniada: "); // Removed tilde
    scanf("%s", pieza.nombre);
    printf("Ingrese cantidad: ");
    scanf("%d", &pieza.cantidad);
    fwrite(&pieza, sizeof(PiezaDaniada), 1, file); // Updated struct name
    fclose(file);
    printf("Pieza daniada registrada exitosamente.\n"); // Removed tilde
}

void arreglarPiezas() {
    ensureFileExists("piezas_daniadas.dat"); // Ensure the damaged pieces file exists
    ensureFileExists("stock.dat"); // Ensure the stock file exists

    PiezaDaniada pieza;
    Producto producto;
    FILE *damagedFile = fopen("piezas_daniadas.dat", "rb+"); // Open damaged pieces file in read/write mode
    FILE *stockFile = fopen("stock.dat", "rb+"); // Open stock file in read/write mode
    if (!damagedFile || !stockFile) {
        printf("Error al abrir los archivos.\n");
        if (damagedFile) fclose(damagedFile);
        if (stockFile) fclose(stockFile);
        return;
    }

    printf("\n--- Piezas Dañadas ---\n");
    int found = 0; // Flag to check if any damaged pieces exist
    while (fread(&pieza, sizeof(PiezaDaniada), 1, damagedFile)) {
        // Skip invalid entries (e.g., empty or repaired records)
        if (pieza.cantidad <= 0 || strlen(pieza.nombre) == 0) {
            continue;
        }

        found = 1; // Set flag if a valid damaged piece is found
        printf("ID: %d, Nombre: %s, Cantidad: %d\n", pieza.id, pieza.nombre, pieza.cantidad);
        int opcion;
        printf("¿Desea arreglar esta pieza? (1: Sí, 2: No): ");
        scanf("%d", &opcion);
        if (opcion == 1) {
            // Check if the product already exists in the stock
            rewind(stockFile); // Reset file pointer for stock
            int updated = 0; // Flag to check if the stock was updated
            while (fread(&producto, sizeof(Producto), 1, stockFile)) {
                if (strcmp(producto.nombre, pieza.nombre) == 0) {
                    // Update the quantity of the existing product
                    producto.cantidad += pieza.cantidad;
                    int64_t offset = -(int64_t)sizeof(Producto); // Move back to overwrite the record
                    if (fseek(stockFile, offset, SEEK_CUR) != 0) {
                        perror("Error al mover el puntero del archivo de stock");
                        fclose(damagedFile);
                        fclose(stockFile);
                        return;
                    }
                    fwrite(&producto, sizeof(Producto), 1, stockFile); // Write updated record
                    updated = 1;
                    break;
                }
            }

            // If the product does not exist in the stock, add it as a new entry
            if (!updated) {
                producto.id = pieza.id;
                strcpy(producto.nombre, pieza.nombre);
                producto.cantidad = pieza.cantidad;
                producto.precio = 0; // Set price to 0 or update as needed
                fseek(stockFile, 0, SEEK_END); // Move to the end of the file
                fwrite(&producto, sizeof(Producto), 1, stockFile); // Write new entry
            }

            printf("Pieza reparada y agregada al stock.\n");

            // Remove the repaired piece from damaged pieces file
            int64_t offset = -(int64_t)sizeof(PiezaDaniada); // Move back to overwrite the record
            if (fseek(damagedFile, offset, SEEK_CUR) != 0) {
                perror("Error al mover el puntero del archivo de piezas dañadas");
                fclose(damagedFile);
                fclose(stockFile);
                return;
            }
            pieza.cantidad = 0; // Mark as repaired (or remove completely)
            memset(pieza.nombre, 0, sizeof(pieza.nombre)); // Clear name field
            fwrite(&pieza, sizeof(PiezaDaniada), 1, damagedFile);
        }
    }

    if (!found) {
        printf("No hay piezas dañadas registradas.\n");
    } else {
        printf("Todas las piezas han sido procesadas.\n");
    }

    fclose(damagedFile);
    fclose(stockFile);
    printf("Regresando al menú del personal...\n"); // Automatically return to the personal menu
}