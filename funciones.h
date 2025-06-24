#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    int id; // Added unique ID field
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

typedef struct {
    char cliente[50];
    char producto[50];
    int cantidad;
    float total;
} Venta;

typedef struct {
    int id;
    char nombre[50];
    int cantidad;
} PiezaDaniada;

void menu();
void agregarProducto();
void mostrarStock();
void registrarVenta();
void mostrarVentas();
void agregarPiezaPorID();
void comprarProducto();
void devolverProductoDaniado();
void arreglarPiezas();
void ensureFileExists(const char *filename);

#endif
