#include <stdio.h>

int main (int argc, char *argv[]) {

int opc2;   
int contador[4], contador2[4];

do
{
    int opc, opc1, opcr[5] = {6, 8, 15, 10, 3}, opcc[5] = {0, 0, 0, 0, 0}, tpb = 0, sm[5] = {0, 0, 0, 0, 0};
    float dct[5], dcttotal, iva;

    printf("CALCULADORA DE COSTOS EN UNA TIENDA DE ROPA\n");

    do {
        printf("Seleccione el tipo de prenda que desea comprar\n");
        printf("1. Camisetas 6$/u\n2. Pantalon 8$/u \n3. Zapatos 15$/u\n4. Busos 10$/u\n5. Medias 3$/u\n");
        scanf("%i", &opc1);

        switch (opc1) {
        case 1:
            printf("Ingrese la cantidad de camisetas seleccionada\n");
            scanf("%i", &opcc[0]);
            sm[0] = opcr[0] * opcc[0];  

            if (opcc[0]>5)
            {
                dct[0]=sm[0]*0.90;
            }

            contador[0]=opcc[0];
            break;
        case 2:
            printf("Ingrese la cantidad de pantalones seleccionada\n");
            scanf("%i", &opcc[1]);
            sm[1] = opcr[1] * opcc[1]; 
            if (opcc[1]>5)
            {
                dct[1]=sm[1]*0.90;
            }

            contador[1]=opcc[1];
            break;
        case 3:
            printf("Ingrese la cantidad de zapatos seleccionada\n");
            scanf("%i", &opcc[2]);
            sm[2] = opcr[2] * opcc[2];  
            if (opcc[2]>5)
            {
                dct[2]=sm[2]*0.90;
            }

            contador[2]=opcc[2];
            break;
        case 4:
            printf("Ingrese la cantidad de busos seleccionada\n");
            scanf("%i", &opcc[3]);
            sm[3] = opcr[3] * opcc[3];  
            if (opcc[3]>5)
            {
                dct[3]=sm[3]*0.90;
            }

            contador[3]=opcc[3];
            break;
        case 5:
            printf("Ingrese la cantidad de medias seleccionada\n");
            scanf("%i", &opcc[4]);
            sm[4] = opcr[4] * opcc[4];  
            if (opcc[4]>5)
            {
                dct[4]=sm[4]*0.90;
            }

            contador[4]=opcc[4];
            break;
        default:
            printf("No existe esa opción\n");
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            if (contador[i]>contador2[i])
            {
                contador2[i]=contador[i];
            }
            
        }
        
        printf("Desea ingresar otra prenda?\n1. SI\n2. NO\n");
        scanf("%i", &opc);

    } while (opc == 1);  

   
    for (int i = 0; i < 5; i++) 
    {


        tpb = tpb + sm[i];  
        if (opcc[i]>5)
        {
         dcttotal=dcttotal+dct[i];
         printf("Producto %i aplicado descuentos existentes es: %.f\n", i+1, dct[i]);
        }else
        {
        dct[0]=sm[0];
        dcttotal=dcttotal+sm[i];
        }
        
        
    }
    
  
    printf("El subtotal de su compra es: %i\n", tpb); 
    printf("Desacuento por comprar mas de 5 unidades por prenda (si compro menos, precio base se mantiene): %.f\n", dcttotal);
      iva=dcttotal;
      dcttotal=dcttotal*0.15;
      iva=iva+dcttotal;
    printf("PRECIO Final con iva: %.2f\n", iva);

    printf("Desea registrar la compra de otro cliente?\n");
    scanf("%i", &opc2);
              
    
} while (opc2==1);

printf("Resunen de ventas\n");

printf("PRODUCTO")

    return 0;
}
