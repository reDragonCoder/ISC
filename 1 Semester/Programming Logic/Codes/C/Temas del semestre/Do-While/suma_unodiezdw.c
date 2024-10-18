// Author: reDragonCoder
//Calcular la suma de los números del 1 al 10

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int i=1, suma=0;
    do{
        suma+=i;
        i++;
    } while(i<=10);
    printf("%d", suma);
    return 0;
}