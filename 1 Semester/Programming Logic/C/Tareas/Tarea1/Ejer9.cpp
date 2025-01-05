// Author: reDragonCoder
//EJERCICIO 9. Una tienda ofrece el descuento del 15% sobre el total de la compra y un cliente 
//desea saber cuánto deberá pagar finalmente por su compra. 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float total_compra, total_descuento=0;

    //Pedir datos al usuario
    printf("Ingrese el valor total de su compra: ");
    scanf("%f", &total_compra);

    //Calculos
    total_descuento=total_compra*0.85;

    //Mostrar total de la compra con el descuento
    printf("Usted pagara: $%.2f", total_descuento);

    return 0;
}