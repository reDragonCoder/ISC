// Author: reDragonCoder

//Mostrar de 1 hasta n donde debemos preguntar por el valor de n 

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int n;
    printf("Ingrese un valor: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printf("%d ", i);
    }
    return 0;
}
