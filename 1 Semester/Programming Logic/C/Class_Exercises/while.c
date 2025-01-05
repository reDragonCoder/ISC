// Author: reDragonCoder

//LIBRERIAS
#include <time.h>
#include <stdlib.h>

//MAIN
int main(){
    //activar la generacion de aleatorios
    srand(time(NULL));
    int num, i;
    i=1; //inicilizar el valor de i
    while(i<=10){ //condicion
        num=rand()%51;
        printf("Numeros: %d \n", num);
        i++; //incremento de i
    }
    return 0;
}