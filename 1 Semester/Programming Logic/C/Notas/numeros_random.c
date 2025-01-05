// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <time.h> //time
#include <stdlib.h> //srand, rand

//MAIN
int main(){
    int num, limSup; //solo puede ser con numeros enteros
    srand(time(NULL)); //funciona con el reloj de la computadora
    num=rand() % limSup; //guarda el numero aqui 
    num=rand()%51; //numeros random entre 0 a 50
    num=rand()%50+1; //permite que sean numeros del 1 al 50
    return 0;
}
