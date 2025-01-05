// Author: reDragonCoder
//Maquinita de productos
//Ejemplo de uso de switch
//Los valores que evalua el switch deben ser entero o caracter. 
//NO cadenas, NO reales

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int opcion=0;
    printf("Selecciona tu producto: ");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            printf("Ruffles");
        break;
        case 2:
            printf("Gansito");
        break;
        case 3:
            printf("Coca-Cola");
        break;
        default:
            printf("La opcion no existe \n");
    }
    return 0;
}