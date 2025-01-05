// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <time.h> //time
#include <stdlib.h> //srand, rand

//CONSTANTES GLOBALES
#define TOTAL 15

//MAIN
int main(){
    /*1. Activar srand / solo se hace una vez y de preferencia al iniciar el main*/
    srand(time(NULL));
    int num=0;
    for(int i=1; i<=TOTAL; i++){
        //generar valores entre 0 y 50
        num=rand()%51;
        printf("%d \t", num);
    } //i
    return 0;
}