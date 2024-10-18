// Author: reDragonCoder

//Funciones con formato y sin formato

//Las -funciones con formato- son aquellas que indican al compilador el tipo de dato que se va a capturar
//y/o que se va a mostrar.
//printf
//scanf
//Los formatos aplican para %d (enteros), %f (reales), %c (caracter), %s (cadenas) y todos los formatos que se indican
//en sus apuntes.

//Las -funciones sin formato- son aquellas que no requieren indicar al compilador el tipo de dato que van a capturar 
//o mostrar.
//!!! Solo aplican para %c (caracteres) y %s (cadenas)

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define TAM 25

//MAIN
int main(){
    char letra, grupo;  //almacena 1 caracter
    char cadena [TAM], nombre [15]; //almacena tantos caracteres como lo indica su tamaño

    //Funciones con formato
    printf("ISC 1C los mejores!!! \n");
    printf("Dame tu nombre: ");
    scanf("%s", nombre);
    fflush(stdin); //Para borrar el ENTER antes de pedir un caracter (stdin - estandar input / teclado)
    printf("Dame una letra: ");
    scanf("%c", &letra);
    printf("El nombre que me diste es: %s \n", nombre);
    printf("Y tu letra es: %c \n", letra);

    //Funciones sin formato
    puts("Seremos excelentes programadores \n");
    puts("Dame una cadena: ");
    fflush(stdin);
    gets(cadena);
    puts("Dame tu grupo: ");
    fflush(stdin);
    grupo=getchar();
    puts("La cadena que me diste es: ");
    puts(cadena);
    puts("Y tu grupo es: ");
    putchar(grupo);
}
