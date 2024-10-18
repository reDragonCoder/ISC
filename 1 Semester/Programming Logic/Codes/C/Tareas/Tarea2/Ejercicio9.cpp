// Author: reDragonCoder
//EJERCICIO 9: El programa dado como dato el precio básico de un artículo, calcula el
//impuesto correspondiente del mismo teniendo en cuenta ciertos criterios

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    float prebas, imp=0, pretot=0;
    //Pedir datos al usuario
    printf("Ingrese el precio basico del articulo: ");
    scanf("%f", &prebas);
    //Calculos del impuesto
    if(prebas>500){
        imp=20*0.30+(prebas-40)*0.50;
    }
    else{
        if(prebas>40){
            imp=20*0.30+(prebas-40)*0.40;
        }
        else{
            if(prebas>20){
                imp=(prebas-20)*0.30;
            }
            else{
                imp=0;
            }
        }
    }
    pretot=prebas+imp;
    //Mostrar el total con impuesto
    printf("El total con impuesto es de: $%.2f", pretot);
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes