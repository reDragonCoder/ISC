// Author: reDragonCoder/
//Realice un programa que lea los nombres y las edades de diez alumnos, y que los datos se 
//almacenen en dos vectores, y con base en esto se determine el nombre del alumno con la 
//edad mayor del arreglo.

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define TAM 10

//MAIN
int main(){
    int edades[TAM], indice_edadMax=0, edadMax=0;
    char nombres[TAM][50];
    for(int i=0; i<10; i++){
        printf("Ingrese el nombre del alumno %d: ", i+1);
        scanf("%s", nombres[i]);
        printf("Ingrese la edad del alumno %d: ", i+1);
        scanf("%d", &edades[i]);
        if(edades[i]>edadMax){
            edadMax=edades[i];
            indice_edadMax=i;
        }
    }
    printf("El alumno con mayor edad es: %s", nombres[indice_edadMax]);
    return 0;
}