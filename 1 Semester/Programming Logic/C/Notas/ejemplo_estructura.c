// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//CONSTANTES GLOBALES
#define TAM 10
const float PI=3.1416;

//VARIABLES GLOBALES
int cantidad = 5; //variable con valor inicial
char turno; //variable sin valor inicial

//MAIN
int main(){
    //Variable local
    int edad = 8, total=0;
    float calif;
    char turno;
    char nombre[15];

    //funciones de entrada Leer
    //Lectura de un valor int
    scanf("d", &total);
    //Lectura de un valor float
    scanf("%f", &calif);
    //Lectura de un valor caracter
    scanf("%c", &turno);
    //Lectura de un valor cadena
    scanf("%s", nombre); //OJO! Las cadenas no llevan &
    
    //Funciones de salida Escribir - Mostar
    //Mostrar solo un mensaje
    printf("Mensaje a enviar a pantalla");

    //Mostrar el valor de una variable/constante
    printf("%f", PI);
    printf("%d", cantidad);

    //Mostrar texto y valores de variables/constantes
    printf("Tu edad es: %d", edad);
    return 0;
}