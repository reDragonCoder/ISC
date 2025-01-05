// Author: reDragonCoder
//Un programa que captura un vector de caracteres e indique que longitud tiene y cuantas 
//vocales contiene. (que pueda contener espacios el vector)

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
    char vector[40];
    int vocales=0, longitud1=0, longitud2=0;
    printf("Ingrese un texto: ");
    gets(vector);
    longitud1=strlen(vector);
    longitud2=longitud1;
    for(int i=0; i<longitud1; i++){
        if(vector[i]==' '){
            longitud2-=1;
        }
        else{
            continue;
        }
    }
    for(int i=0; i<longitud1; i++){
        if(vector[i]==' '){
            continue;
        }
        else{
            if(vector[i]=='a' || vector[i]=='e' || vector[i]=='i' || vector[i]=='o' || vector[i]=='u'){
                vocales+=1;
            }
        }
    }
    printf("El texto '%s' tiene una longitud con espacios de %d, una longitud sin espacios de %d y tiene %d vocales", vector, longitud1, longitud2, vocales);
    return 0;
}