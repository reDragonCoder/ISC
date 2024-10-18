// Author: reDragonCoder
//Suma y resta de n/i

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int num, totalSerie;
    float suma=0;
    printf("Tamaño de la serie: ");
    scanf("%d", &totalSerie);
    printf("Numero a dividir: ");
    scanf("%d", &num);
    for(int i=1; i<=totalSerie; i++){
        if(i%2==0){ //par +
            suma+=(num/i);
        }
        else{
            suma-=(num/i);
        }
    }//i
    printf("Suma = %f ", suma);
    return 0;
}