// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float celsius, fahrenheit;
    printf("Ingrese la temperatura en grados celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("La temperatura en grados fahrenheit es: %f °", fahrenheit);
    return 0;
}