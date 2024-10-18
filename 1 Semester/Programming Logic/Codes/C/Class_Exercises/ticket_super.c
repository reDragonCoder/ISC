// Author: reDragonCoder
//Interaccion de un cliente con su carrito de super (productos) que determina cuanto pagará

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int i, totalProd=0, cont=0;
    float sumaPre=0, precio=0;
    //Presguntar el total de productos a capturar
    printf("Total de prodcutos: ");
    scanf("%d", &totalProd);
    //Ciclo para capturar los precios
    for(i=1; i<=totalProd; i++){
        printf("Dame el precio: ");
        scanf("%f", &precio);
        sumaPre+=precio;
        cont+=1;
    } //i
    printf("Total a pagar: $%.2f \n", sumaPre);
    printf("Total de prodcutos: %d \n", cont);
    return 0;
}