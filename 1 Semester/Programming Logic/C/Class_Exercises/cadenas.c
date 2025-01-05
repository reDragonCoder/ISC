// Author: reDragonCoder
//Manejo de cadenas con funciones de string.h
//copiar | comparar | longitud | invertir | unir
//strcpy | strcmp | strlen | strrev | strcat

//LIBRERIAS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANTES GLOBALES
#define TAM 25

//MAIN
int main(){
    char nombre[TAM], carrera[TAM], materia[TAM], cad[TAM];
    char frase[]="buenos dias", uni[]={"SISTEMAS"};
    int opc, numeros[5], tam;
    double calif;
    do{
        system("cls"); //borra la pantalla
        printf("MANEJO DE CADENAS \n");
        printf("Copiar........1 \n");
        printf("Comparar......2 \n");
        printf("Longitud......3 \n");
        printf("Invertir......4 \n");
        printf("Unir..........5 \n");
        printf("Salir.........6 \n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opc);
        switch(opc){
            case 1: //copiar cadenas 
                strcpy(nombre, "pregunten pregunten");
                printf("Nombre: %s \n");
                break;
            case 2: //comparar cadenas
                printf("Carrera: ");
                flush(stdin);
                gets(carrera);
                printf("Materia: ");
                flush(stdin);
                gets(materia);
                if(strcmp(carrera, materia)==0){
                    printf("Cadenas iguales \n");
                }else{
                    printf("Cadenas distintas \n");
                }
                break;
            case 3: //longitud de cadenas             
                printf("Ingrese una cadena: ");
                fflush(stdin);
                gets(cad);
                tam=strlen(cad);
                printf("Tamaño de la cadena: %d \n", tam);
                break;
            case 4: //invertir cadenas
                strrev(uni);
                printf("Cadena invertida: %s \n", uni);
                break;
            case 5: //unir cadenas
                strcpy(cad, ""); //limpiar una variable char
                strcat(cad, nombre); //pegar el nombre en cad
                strcat(cad, "-"); //pegar un guion
                strcat(cad, materia); //pegar la materia
                printf("Union de cadenas: %s", cad);
                break;
        }
    }while(opc!=6);
    return 0;
}

//char ocupa un byte por caracter (un espacio para cada caracter)
//int ocupa 4 bytes (solo un espacio por valor)
//float ocupa 4 bytes (solo un espacio por valor)
//double ocupa 6 bytes (solo un espacio por valor)
//NOTA: internamente, \0 marca el fin de linea o fin de la cadena
//para una cadena con espacios se usa gets

//libreria <iostream> -> es de C++
//using namespace std; -> antes del int main()
//char variable[25]; -> dentro del main
//getline(cin, variable); -> dentro del main
