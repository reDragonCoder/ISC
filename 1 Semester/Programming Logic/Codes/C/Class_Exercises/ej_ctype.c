// Author: reDragonCoder
//manejo de las funciones ctype.h
//capturar un arreglo de caracteres y trabajar con ls funciones

//LIBRERIAS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//CONSTANTES GLOBALES
#define TAM 15

//MAIN
int main(){
    char letras [TAM];
    //capturar contenido del arreglo
    for (int i=0; i<TAM; i++) {
        printf("Letra: ");
        fflush(stdin);
        scanf("%c", &letras[i]);
    }
    //mostrar el contenido como si fuera un cadena
    //Osea reunimos todos los caracteres recolectados
    printf("%s", letras);
    
    //mostrar el contenido como un vector
    for (int i=0; i<TAM; i++) {
        printf("%c ",letras[i]);
    }
    
}//main


