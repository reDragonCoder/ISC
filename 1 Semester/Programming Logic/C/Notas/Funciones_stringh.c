// Author: reDragonCoder

//Ejercicio para el uso de funciones de string.h y manejo de funciones sin formato (gets, puts)

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//CONSTANTES GLOBALES
#define TAM 10

//MAIN
int main(){
    char nomAlu[TAM], materia[TAM], cadAux[30];
    int longitud=0;
    //printf("Nombre del alumno: ");
    puts("Nombre del alumno: ");
    //scanf("%s", nomAlu);
    gets(nomAlu);

    //printf("Nombre de la materia: ");
    puts("Nombre de la materia: ");
    //scanf("%s", materia);
    gets(materia);

    /*Comparar cadenas
    0 - si son iguales
    >0 - si la primer cadena es más larga
    <0 - si la segunda cadena es más larga */
    if(strcmp(nomAlu, materia)==0){
        puts("Las variables son iguales \n");
    }
    else{
        puts("Las variables son diferentes \n");
    }

    //Obtener la longitud de ambas cadenas
    longitud=strlen(materia);
    printf("Longitud de %s es %d \n", materia, longitud);

    longitud=0;
    longitud=strlen(nomAlu);
    printf("Longitud de la variable %s es %d \n", nomAlu, longitud);

    
    //Copiar cadenas significa asignar un valor a una cadena, ejemplo: cadAux=nomAlu;
    //cadAux guarda el valor de la variable nomAlu
    //strcpy(cadenaDestino, cadenaOrigen);
    strcpy(cadAux, nomAlu);
    puts("Contenido de la cadena auxiliar:");
    puts(cadAux);
    //Unir cadenas romano = romano + 'I';
    //strcat(cadenaDestino, cadenaOrigen);
    strcat(cadAux, " ");
    strcat(cadAux, materia);
    puts(cadAux);
    return 0;
}

