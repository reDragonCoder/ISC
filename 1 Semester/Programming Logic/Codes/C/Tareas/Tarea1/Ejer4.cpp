// Author: reDragonCoder
//EJERCICIO 4. Don Juan vendió a 3 personas varias hectáreas de tierra a cada una. Cada hectárea cuesta 30000. 
//Don Juan quiere saber el número de hectáreas que vendió en total, lo que le pagará cada uno de ellos 
//(considerando un descuento del 7% por cada hectárea) y lo que le pagarán en conjunto considerando también el descuento.  

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define COSTO_POR_HECT 3000 //forma 1 de declarar constantes
const float DESCUENTO = 0.93; //forma 2 de declarar constantes

//MAIN
int main(){
    //Variables
    float hectPer1=0, hectPer2=0, hectPer3=0, hectVend=0, pagoIn1=0, pagoIn2=0, pagoIn3=0, pagoTotal=0;

    //Pedir datos al usuario
    printf("Dame las hectareas de la persona 1: ");
    scanf("%f", &hectPer1);
    printf("Dame las hectareas de la persona 2: ");
    scanf("%f", &hectPer2);
    printf("Dame las hectareas de la persona 3: ");
    scanf("%f", &hectPer3);

    //Calcular el total de hectáreas vendidas
    hectVend = hectPer1+hectPer2+hectPer3;
    printf("Total de hectareas vendidas: %.2f \n\n", hectVend);

    //Calcular el pago individual
    pagoIn1 = (COSTO_POR_HECT*hectPer1)*DESCUENTO;
    printf("Pago por persona 1 con descuento: %.2f \n", pagoIn1);
    pagoIn2 = (COSTO_POR_HECT*hectPer2)*DESCUENTO;
    printf("Pago por persona 2 con descuento: %.2f \n", pagoIn2);
    pagoIn3 = (COSTO_POR_HECT*hectPer3)*DESCUENTO;
    printf("Pago por persona 3 con descuento: %.2f \n\n", pagoIn3);

    //Calcular el pago total
    pagoTotal = pagoIn1 + pagoIn2 + pagoIn3;
    printf("El pago total es: $%.2f \n", pagoTotal);
    return 0;
} //Main