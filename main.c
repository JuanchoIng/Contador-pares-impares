#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int stockIngresado = 0; // Flag to track if stock has been entered

void menuPrincipal() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Menu del Personal\n");
    printf("2. Menu del Cliente\n");
    printf("0. Salir\n");
}

void menuPersonal() {
    printf("\n--- Menu del Personal ---\n");
    printf("1. Ingresar Stock\n");
    printf("2. Ver Stock\n");
    printf("3. Arreglar Piezas\n");
    printf("4. Ver Ventas\n");
    printf("0. Regresar\n");
}

void menuCliente() {
    printf("\n--- Menu del Cliente ---\n");
    printf("1. Ver y Comprar Stock\n"); // Combined option
    printf("2. Devolver Producto Dañado\n");
    printf("0. Regresar\n");
}

int main() {
    int option;
    do {
        menuPrincipal();
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int password;
                printf("Ingrese la contrasenia: ");
                scanf("%d", &password);
                if (password == 1234) {
                    int personalOption;
                    do {
                        menuPersonal();
                        printf("Seleccione una opcion: ");
                        scanf("%d", &personalOption);
                        switch (personalOption) {
                            case 1:
                                agregarProducto();
                                stockIngresado = 1; // Set flag when stock is entered
                                break;
                            case 2:
                                if (stockIngresado) {
                                    mostrarStock();
                                } else {
                                    printf("Primero debe ingresar el stock.\n");
                                }
                                break;
                            case 3:
                                arreglarPiezas();
                                break;
                            case 4:
                                mostrarVentas();
                                break;
                            case 0:
                                printf("Regresando al menu principal...\n");
                                break;
                            default:
                                printf("Opcion invalida. Intente nuevamente.\n");
                        }
                    } while (personalOption != 0);
                } else {
                    printf("Contrasenia incorrecta.\n");
                }
                break;
            }
            case 2: {
                if (!stockIngresado) {
                    printf("Primero debe ingresar el stock en el menu del personal.\n");
                    break;
                }
                int clienteOption;
                do {
                    menuCliente();
                    printf("Seleccione una opcion: ");
                    scanf("%d", &clienteOption);
                    switch (clienteOption) {
                        case 1:
                            mostrarStock();
                            comprarProducto();
                            break; // Combined "Ver Stock" and "Comprar"
                        case 2:
                            devolverProductoDaniado();
                            break;
                        case 0:
                            printf("Regresando al menu principal...\n");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                    }
                } while (clienteOption != 0);
                break;
            }
            case 0:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (option != 0);
    return 0;
}
