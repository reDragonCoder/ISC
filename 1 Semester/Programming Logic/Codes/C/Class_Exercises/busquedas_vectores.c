// Author: reDragonCoder
//búsqueda de vectores

//LIBRERIAS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

//CONSTANTES GLOBALES
#define MAX 10

//MAIN
int main(){
    srand(time(NULL));
    int vec[MAX], i=0, opc=0, dato=0, pos=0, cont=0;
    bool existe=false;

    //llenar el vector con aleatorios
    while(i<MAX){
        vec[i]=rand()%100;
        i++;
    }
    printf("\n\n");

    //mostrar arreglo
    i=0;
    do{
        printf("%d \t", vec[i++]);
    }while(i<MAX);
    printf("\n\n");

    //menu con opciones para buscar
    do{
        printf("BUSQUEDAS \n");
        printf("1... existencia de un dato \n");
        printf("2... consultar el dato de una posicion \n");
        printf("3... cantidad de veces que se localice un dato \n");
        printf("4... posicion de un dato \n");
        printf("5... salir \n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            //indicar si existe o no un dato
            case 1:
                existe=false;
                dato=0;
                printf("Dato a buscar: ");
                scanf("%d", &dato);
                //recorrer el vector buscando el dato
                for(int k=0; k<MAX; k++){
                    if(vec[k]==dato){ //revisar cada valor del vector
                        existe=true;
                        break;
                    }//if
                }//for k
                if(existe){ //se pregunta si existe==true
                    printf("El valor %d si existe! \n", dato);
                }
                else{
                    printf("Dato no localizado :( \n");
                }
            break;
            //mostrar el valor que se encuentre en una posicion
            case 2:
                dato=0;
                printf("Posicion a consultar: ");
                scanf("%d", &pos);
                //validar que la posicion se encuentre en el rango
                if(pos>=0 && pos<MAX){
                    printf("El valor almacenado en la posicion %d es: %d \n", pos, vec[pos]);
                }
                else{
                    printf("La posicion no existe en el arreglo \n");
                }
            break;
            //mostrar el numero de veces que existe un dato en el arreglo
            case 3:
                dato=0;
                cont=0;
                existe=false;
                printf("Dato a buscar: ");
                scanf("%d", &dato);
                //recorrer el vector buscando el dato
                for(int k=0; k<MAX; k++){
                    if(vec[k]==dato){ //revisar cada valor del vector
                        cont++; //cuento cada vez que lo encuentre
                        existe=true;
                    }
                }//for k
                if(existe){
                    printf("Total de veces encontrado el dato: %d", cont);
                }
                else{
                    printf("El dato no existe en el arreglo");
                }
            break;
            //mostrar la posicion de un dato dentro de un arreglo
            case 4:
                dato=0;
                printf("Dato a buscar: ");
                scanf("%d", &dato);
                //recorrer el vector buscando el dato
                for(int u=0; u<MAX; u++){
                    if(vec[u]==dato){
                        printf("Posicion: %d \t \n", u); //mostrar el valor de u (posicion)
                        existe=true;
                    }
                }
                printf("\n\n");
                if(!existe){ //preguntar si existe==false
                    printf("Valor no localizado! \n");
                }
            break;
        }
    }while(opc!=5);

    return 0;
}