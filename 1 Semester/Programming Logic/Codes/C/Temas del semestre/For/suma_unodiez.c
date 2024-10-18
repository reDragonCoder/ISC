// Author: reDragonCoder
// Calcular la suma de los números del 1 al 10

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int suma=0;
    for(int i=1; i<=10; i++){
        suma+= i;
    }
    printf("%d", suma);
    return 0;
}