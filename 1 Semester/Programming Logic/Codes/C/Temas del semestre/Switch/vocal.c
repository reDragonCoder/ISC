// Author: reDragonCoder
//Que pida una letra y detecte si es una vocal

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    char letra;
    printf("Ingrese una letra en minuscula: ");
    scanf("%c", &letra);
    switch(letra){
        case 'a': 
            printf("Es una vocal");
            break;
        case 'e': 
            printf("Es una vocal");
            break;
        case 'i': 
            printf("Es una vocal");
            break;
        case 'o': 
            printf("Es una vocal");
            break;
        case 'u': 
            printf("Es una vocal");
            break;
        default:
            printf("Es una consonante");
            break;
    }
    return 0;
}