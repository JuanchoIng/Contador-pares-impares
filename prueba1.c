#include <stdio.h>

int main (int argc, char *argv[]) {

    int opc2;   
    int contador2[5] = {0};  // Inicializa los contadores en 0 para 5 productos

    do {

        printf("CALCULADORA DE COSTOS EN UNA TIENDA DE ROPA\n");
        int opc, opc1, contador[5] = {0}, opcr[5] = {6, 8, 15, 10, 3}, opcc[5] = {0}, tpb = 0, sm[5] = {0};
        float dct[5] = {0}, dcttotal = 0, iva = 0;

        do {
            printf("Seleccione el tipo de prenda que desea comprar\n");
            printf("1. Camisetas 6$/u\n2. Pantalon 8$/u \n3. Zapatos 15$/u\n4. Busos 10$/u\n5. Medias 3$/u\n");
            scanf("%i", &opc1);

            switch (opc1) {
                case 1:
                    printf("Ingrese la cantidad de camisetas seleccionada\n");
                    scanf("%i", &opcc[0]);
                    sm[0] = opcr[0] * opcc[0];  
                    if (opcc[0] > 5) {
                        dct[0] = sm[0] * 0.90;  // Aplica descuento
                    } else {
                        dct[0] = sm[0];
                    }
                    contador[0] += opcc[0];
                    break;
                case 2:
                    printf("Ingrese la cantidad de pantalones seleccionada\n");
                    scanf("%i", &opcc[1]);
                    sm[1] = opcr[1] * opcc[1]; 
                    if (opcc[1] > 5) {
                        dct[1] = sm[1] * 0.90;  // Aplica descuento
                    } else {
                        dct[1] = sm[1];
                    }
                    contador[1] += opcc[1];
                    break;
                case 3:
                    printf("Ingrese la cantidad de zapatos seleccionada\n");
                    scanf("%i", &opcc[2]);
                    sm[2] = opcr[2] * opcc[2];  
                    if (opcc[2] > 5) {
                        dct[2] = sm[2] * 0.90;  // Aplica descuento
                    } else {
                        dct[2] = sm[2];
                    }
                    contador[2] += opcc[2];
                    break;
                case 4:
                    printf("Ingrese la cantidad de busos seleccionada\n");
                    scanf("%i", &opcc[3]);
                    sm[3] = opcr[3] * opcc[3];  
                    if (opcc[3] > 5) {
                        dct[3] = sm[3] * 0.90;  // Aplica descuento
                    } else {
                        dct[3] = sm[3];
                    }
                    contador[3] += opcc[3];
                    break;
                case 5:
                    printf("Ingrese la cantidad de medias seleccionada\n");
                    scanf("%i", &opcc[4]);
                    sm[4] = opcr[4] * opcc[4];  
                    if (opcc[4] > 5) {
                        dct[4] = sm[4] * 0.90;  // Aplica descuento
                    } else {
                        dct[4] = sm[4];
                    }
                    contador[4] += opcc[4];
                    break;
                default:
                    printf("No existe esa opción\n");
                    break;
            }

            // Acumulando el total de productos comprados
            for (int i = 0; i < 5; i++) {
                contador2[i] += contador[i];  // Se acumulan los productos comprados de este cliente
            }
        
            printf("Desea ingresar otra prenda?\n1. SI\n2. NO\n");
            scanf("%i", &opc);

        } while (opc == 1);  

        // Cálculo del total de la compra
        for (int i = 0; i < 5; i++) {
            tpb += sm[i];  // Acumulamos el total sin descuentos
            dcttotal += dct[i];  // Acumulamos el total con descuentos si los hay
            if (opcc[i] > 5) {
                printf("Producto %i aplicado descuentos existentes es: %.f\n", i+1, dct[i]);
            }
        }
        
        printf("El subtotal de su compra es: %i\n", tpb); 
        printf("Descuento por comprar más de 5 unidades por prenda (si compró menos, precio base se mantiene): %.f\n", dcttotal);

        iva = dcttotal * 0.15;
        dcttotal += iva;  // Precio final con IVA

        printf("PRECIO Final con iva: %.2f\n", dcttotal);

        printf("Desea registrar la compra de otro cliente?\n");
        scanf("%i", &opc2);

    } while (opc2 == 1);

    // Mostrar resumen de ventas al final
    printf("Resumen de ventas\n");
    for (int i = 0; i < 5; i++) {
        if (contador2[i]!= 0)
        {
            printf("El producto %i ha sido comprado %i veces\n", i+1, contador2[i]);
        }
        
        
    }

    return 0;
}
