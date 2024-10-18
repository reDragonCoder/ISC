// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int total, highest, num;
    printf("Indique el numero de valores enteros que ingresara: ");
    scanf("%d", &total);
    highest=0;
    for(int i=1; i<=total; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if(num>highest){
            highest=num;
        }
    }
    printf("El numero mayor que ingresaste es: %d", highest);
    return 0;
}