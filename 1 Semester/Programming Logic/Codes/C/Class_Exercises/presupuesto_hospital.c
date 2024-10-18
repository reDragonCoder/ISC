// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float pres_anual, pres_gine, pres_trauma, pres_pedia;
    printf("ingrese el presupuesto anual: ");
    scanf("%f", &pres_anual);
    pres_gine = pres_anual * 0.4;
    pres_trauma = pres_anual * 0.3;
    pres_pedia = pres_anual * 0.3;
    printf("El area de ginecologia recibira $%f \n", pres_gine);
    printf("El area de traumatologia recibira $%f \n", pres_trauma);
    printf("El area de pediatria recibira $%f \n", pres_pedia);
    return 0;
}