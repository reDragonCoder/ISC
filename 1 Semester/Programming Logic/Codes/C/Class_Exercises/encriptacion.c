// Author: reDragonCoder
//Encriptar un arreglo de caracteres
//aA-4 | eE-3 | iI-1 | oO-0 | uU-# | 1..9-$

//LIBRERIAS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//MAIN
int main(){
    char cadena[]={"Hoy es miercoles 15 de noviembre de 2023"};
    char auxiliar[20]={""}, texto[15]={""};
    int tam=0;

    //capturar una cadena
    //forma 1. como un flujo de caracteres
    printf("Introduce la cadena: ");
    gets(auxiliar); // si almacena espacios


    //forma 2. como un arreglo de caracteres
    printf("Introduce la cadena caracter por caracter: \n");
    for(int i=0; i<5; i++){
        printf("Caracter: ");
        fflush(stdin);
        scanf("%c", &texto[i]);
    }

    printf("Contenido de las variables \n");
    printf("%s \n", texto); // se muestra como una cadena aunque se capturó como un vector

    tam=strlen(auxiliar); //obtener el tamaño de auxiliar
    for(int i=0; i<tam; i++){ //mostrar auxiliar caracter por caracter
        printf("%c ", auxiliar[i]);
    }
    printf("\n\n");

    //recorrer la variable cadena y encriptarla
    tam=0; //limpiar la variable para reutilizar
    tam=strlen(cadena);
    for(int i=0; i<tam; i++){ //recorrer toda la cadena
        cadena[i]=tolower(cadena[i]);
        if(isdigit(cadena[i])){
            cadena[i]='$';
        }
        switch(cadena[i]){
            case 'a': cadena[i]='4'; break;
            case 'e': cadena[i]='3'; break;
            case 'o': cadena[i]='0'; break;
            case 'u': cadena[i]='#'; break;
        }
    }
    puts(cadena);

    return 0;
}

//NOTAS:
//captura de una cadena como un flujo de datos
//printf("Introduce la cadena: ");
    //scanf("%s", auxiliar); //no almacena espacios
    //gets(auxiliar); // si almacena espacios

//y para xCode --> #include <iostream>
//                  using namespace std;
//                  cin >> auxiliar;
//                  cin.getLine(auxiliar,20);