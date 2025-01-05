// Author: reDragonCoder
//Dividir un  numero de N cifras en dígitos y mostrarlo en pantalla de forma inversa
// 345 --> 5 4 3

//LIBRERIAS
#include <stdio.h>

//MAIN
int main()
{
    int num, digito=0;
    printf("Ingrese el numero: ");
    scanf("%d", &num);
    while(num!=0){
        digito=num%10;
        printf("%d ", digito);
        num/=10; // num=num/10;
    }
    return 0;
}