// Author: reDragonCoder
//Encontrar el valor mayor de una serie de numeros

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
const int TOTAL=10;

//MAIN
int main(){
    int num, mayor=0;
    bool ban=false;
    for(int i=1; i<=TOTAL; i++){
        printf("Dame un numero: ");
        scanf("%d", &num);
        if(num>mayor){
            mayor=num;
        } 
        if(num==3)
            ban=true;
        //si un if solo tiene una instruccion, se puede no poner llaves
    }//i
    printf("El mayor es: %d ", mayor);
    if(ban==true){
        printf("El valor 3 si existe!");
    }
    return 0;
}

//en valores booleanos, para evaluar si es false se escribe if!(ban)