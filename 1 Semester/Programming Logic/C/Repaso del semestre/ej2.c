// Author: reDragonCoder
//Mostrar del 1 al 300 pero solamente mostrara los múltiplos del 3 (3,6,9,….)

//LIBRERIAS
#include <stdio.h>

//CONSTANTES GLOBALES
#define N 300

//MAIN
int main(){
    for(int i=1; i<=N; i++){
        if(i%3==0){
            printf("%d ", i);
            printf("\n");
        }
        else{
            continue;
        }
    }
    return 0;
}