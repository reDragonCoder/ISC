// Author: reDragonCoder
#include <stdio.h>

//MAIN
int main(){
    int num, c=0;
    printf("Ingrese el numero a evaluar: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        if(num%i==0){
            c++;
        }
    }
    if(c==2){
        printf("El numero es primo");
    }
    else{
        printf("El numero NO es primo");
    }
    return 0;
}