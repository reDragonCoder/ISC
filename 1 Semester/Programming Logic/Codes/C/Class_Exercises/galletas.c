// Author: reDragonCoder
//Tienda de galletas - ciclos anidados
//Obtener totales por tienda y total general

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define TIENDA 3
const int GALLETA=3;

//MAIN
int main(){
    int cantG=0, sumaT=0, sumaG=0;
    float costoG=0, ganancia=0;
    printf("Dame el costo de la galleta: ");
    scanf("%f", &costoG);
    //capturar la cantidad de galletas por tienda
    for(int t=0; t<TIENDA; t++){ //tiendas
        for(int g=0; g<GALLETA; g++){//galletas
            printf(" \nGalleta tipo %d en tienda %d: ", g+1, t+1); //g+1 no modifica el valor de la galleta, g++ si porque es g=g+1
            scanf("%d", &cantG);
            sumaT+=cantG;
        }
        printf("\nTotal de galletas en la tienda %d es: %d \n", t+1, sumaT);
        sumaG+=sumaT;
        sumaT=0;
    }//for t
    printf("\nTotal de galletas vendidas: %d\n", sumaG);
    ganancia=sumaG*costoG;
    printf("Ganancias $%.2f: \n", ganancia);
    return 0;
}
