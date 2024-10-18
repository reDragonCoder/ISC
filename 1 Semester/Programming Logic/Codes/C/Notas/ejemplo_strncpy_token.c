// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <string.h>
 
 //MAIN
int main(){
    char texto1[40], texto2[40], texto3[10];
 
    printf("Introduce un frase: ");
    gets(texto1);

    //strtok() puede utilizarse para dividir una cadena en tokens. Sirve para extraer palabras de una oracion
    char*token = strtok(texto1, "\n");

    strcpy(texto2, token);
    printf("Una copia de tu texto es %s \n", texto2);
    //strncpy es para copiar n cantidad de bits de una cadena, en este caso 4
    strncpy(texto3, token, 4);
    printf("Y sus 4 primeras letras son %s \n", texto3);
 
    return 0;
}