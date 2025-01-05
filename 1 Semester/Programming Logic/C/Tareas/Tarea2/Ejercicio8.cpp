// Author: reDragonCoder
//EJERCICIO 8: El programa dado como dato el monto de la compra de un cliente, determina lo
//que el mismo debe pagar teniendo en cuenta una serie de descuentos

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    float compra, pagar=0;
    //Pedir datos al usuario
    printf("Ingrese el valor de su compra: ");
    scanf("%f", &compra);
    //Aplicar los descuentos correspondientes
    if(compra<500){
        pagar=compra;
    }
    else{
        if(compra<=1000){
            pagar=compra-(compra*0.05);
        }
        else{
            if(compra<=7000){
                pagar=compra-(compra*0.11);
            }
            else{
                if(compra<=15000){
                    pagar=compra-(compra*0.18);
                }
                else{
                    pagar=compra-(compra*0.25);
                }
            }
        }
    }
    //Mostrar el total a pagar
    printf("El total a pagar es de: $%.2f", pagar);
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes