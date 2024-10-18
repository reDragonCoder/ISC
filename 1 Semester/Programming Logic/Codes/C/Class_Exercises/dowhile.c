// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h> //Para agregar la opcion de limpiar la pantalla

//MAIN
int main(){
    int opc;
    do{
        system("cls"); //Para limpiar la pantalla
        printf("OPCIONES \n");
        printf("Dividir un numero ... 1 \n");
        printf("Convertir a romano .. 2 \n");
        printf("Triangulo ........... 3 \n");
        printf("Salir ............... 4 \n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1: 
                printf("Dividir un numero");
                system("pause");
            break;
            case 2: 
                printf("Convertir a romano");
                system("pause");
            break;
            case 3:
                printf("Dibujar un triangulo");
                system("pause");
            break;
            case 4: 
                printf("Saliendo...");
            break;
            default:
                printf("Opcion no valida");
            break;
        }
    }while(opc!=4);
    return 0;
}