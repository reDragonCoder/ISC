// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main()
{
    float total_compra, descuento, total_descuento;
    printf("Ingrese el valor total de su compra: ");
    scanf("%f", &total_compra);
    descuento = total_compra * 0.15;
    total_descuento = total_compra - descuento;
    printf("Usted pagara: %f", total_descuento);
    return 0;
}