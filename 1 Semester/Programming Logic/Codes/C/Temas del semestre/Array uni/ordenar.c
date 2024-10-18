// Author: reDragonCoder
//Calcular la media de los números pares de un array de números

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int arreglo[10], suma_pares=0, media=0, j=0;
    for(int i=0; i<10; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &arreglo[i]);
        if(arreglo[i]%2==0){
            j++;
            suma_pares+=arreglo[i];
            media=suma_pares/j;
        }
    }
    printf("La media de los numeros pares es: %d", media);
    return 0;
}