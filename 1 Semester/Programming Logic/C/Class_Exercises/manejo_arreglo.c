// Author: reDragonCoder
//Manejo de arreglos

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
const int MAX=10;

//MAIN
int main(){
    int vec[MAX], aux[MAX], i, j; 
    //inicialización de vectores
    for(int h=0; h<MAX; h++){ //recorrer el vector y almacenar un cero en cada posición
        vec[h]=0;
        aux[h]=0;
    }
    //llenado manual
    i=0;
    while(i<MAX){
        printf("Valor [%d]: ", i);
        scanf("%d", &vec[i]);
        i++;
    }
    //mostar el contenido de las posiciones impares
    j=0;
    for(int k=1; k<MAX; k++){
        //si k es impar, muestra el contenido en pantalla
        if(k%2!=0){
            printf("%d \t",vec[k]);
        }
        //si el valor del vector es par, se copia al auxiliar
        if(vec[k]%2==0){ //vec[k] indica el contenido de una posicion
            aux[j]=vec[k];
            j++;
        }
    }//for i
    //mostrar el contenido de aux
    printf("\n\n");
    i=0;
    do{
        printf("%d \t", aux[i++]);
    }while(i<j);

    //mostrar vec de forma invertida
    for(int t=MAX-1; t>=0; t--){
        printf("%d \t", vec[t]);
    }

    return 0; 
}