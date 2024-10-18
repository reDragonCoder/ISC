// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num, cen, dec, uni;
    printf("Ingrese su numero de 3 digitos: ");
    scanf("%d", &num);
    if(num>=100 && num<=999){
        cen=num/100;
        num=num%100;
        dec=num/10;
        uni=num%10;
    }
    printf("Centenas: %d\n", cen);
    printf("Decenas: %d\n", dec);
    printf("Unidades: %d", uni);
    return 0;
}