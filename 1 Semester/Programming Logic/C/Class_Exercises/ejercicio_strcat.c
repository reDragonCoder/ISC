// Author: reDragonCoder
//Ejercicio 2.
//Te pido escribir un programa que capture un nombre, un apellido y crear una 
//nueva cadena de texto que contenga los dos valores capturados, separados por un espacio.

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
    char nombre[25], apellido[25], nombre_completo[50];

    printf("Ingrese su nombre: ");
    gets(nombre);
    printf("Ingrese su apellido: ");
    gets(apellido);

    strcpy(nombre_completo, nombre);
    strcat(nombre_completo, " ");
    strcat(nombre_completo, apellido);

    printf("Su nombre completo es: %s", nombre_completo);
    return 0;
}