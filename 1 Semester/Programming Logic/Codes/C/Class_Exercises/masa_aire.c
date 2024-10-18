// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float masa, presion, volumen, temperatura;
    printf("Ingrese el valor de la presion: ");
    scanf("%f", &presion);
    printf("Ingrese el valor del volumen: ");
    scanf("%f", &volumen);
    printf("Ingrese el valor de la temperatura: ");
    scanf("%f", &temperatura);
    masa = (presion * volumen) / (0.37 * (temperatura + 460));
    printf("La masa es: %f", masa);
    return 0;
}