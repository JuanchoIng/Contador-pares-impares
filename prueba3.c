#include <stdio.h>

int main (int argc, char *argv[]) {

    int opc, opcr[5] = {6, 8, 15, 10, 3}, opcc[5] = {0, 0, 0, 0, 0}, tpb = 0, sm[5] = {0, 0, 0, 0, 0};
    float dct[5], dcttotal, iva;

    printf("CALCULADORA DE COSTOS EN UNA TIENDA DE ROPA\n");

    do {
        printf("Seleccione el tipo de prenda que desea comprar\n");
        printf("1. Camisetas 6$/u\n2. Pantalon 8$/u \n3. Zapatos 15$/u\n4. Busos 10$/u\n5. Medias 3$/u\n");
        scanf("%i", &opc);

        switch (opc) {
        case 1:
            printf("Ingrese la cantidad de camisetas seleccionada\n");
            scanf("%i", &opcc[0]);
            sm[0] = opcr[0] * opcc[0];  
            if (opcc[0]>5)
            {
                dct[0]=sm[0]*0.90;
            }
            
            break;
        case 2:
            printf("Ingrese la cantidad de pantalones seleccionada\n");
            scanf("%i", &opcc[1]);
            sm[1] = opcr[1] * opcc[1]; 
            if (opcc[1]>5)
            {
                dct[1]=sm[1]*0.90;
            }
            break;
        case 3:
            printf("Ingrese la cantidad de zapatos seleccionada\n");
            scanf("%i", &opcc[2]);
            sm[2] = opcr[2] * opcc[2];  
            if (opcc[2]>5)
            {
                dct[2]=sm[2]*0.90;
            }
            break;
        case 4:
            printf("Ingrese la cantidad de busos seleccionada\n");
            scanf("%i", &opcc[3]);
            sm[3] = opcr[3] * opcc[3];  
            if (opcc[3]>5)
            {
                dct[3]=sm[3]*0.90;
            }
            break;
        case 5:
            printf("Ingrese la cantidad de medias seleccionada\n");
            scanf("%i", &opcc[4]);
            sm[4] = opcr[4] * opcc[4];  
            if (opcc[4]>5)
            {
                dct[4]=sm[4]*0.90;
            }
            break;
        default:
            printf("No existe esa opción\n");
            break;
        }

        printf("Desea ingresar otra prenda?\n1. SI\n2. NO\n");
        scanf("%i", &opc);

    } while (opc == 1);  

   
    for (int i = 0; i < 5; i++) 
    {
        tpb = tpb + sm[i];  
        dcttotal=dcttotal+dct[i];
        printf("Producto %i aplicado descuentos existentes es: %.f\n", i+1, dct[i]);
    }
    
  
    printf("El total de su compra es: %i\n", tpb); 
    printf("Desacuento total por comprar mas de 5 unidades por prenda %.f\n", dcttotal);
      iva=dcttotal;
      dcttotal=dcttotal*0.15;
      iva=iva+dcttotal;
    printf("PRECIO Final con iva: %.f\n", iva);

    

    return 0;
}
