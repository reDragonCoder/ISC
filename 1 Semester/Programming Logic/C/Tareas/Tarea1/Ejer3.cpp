// Author: reDragonCoder
//EJERCICIO 3. La presión, el volumen y la temperatura de una masa de aire se relacionan por la fórmula: 
//masa = (presión * volumen)/(0.37 * (temperatura + 460))  

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    float masa=0, presion, volumen, temperatura;

    //Pedir datos al usuario
    printf("Ingrese el valor de la presion: ");
    scanf("%f", &presion);
    printf("Ingrese el valor del volumen: ");
    scanf("%f", &volumen);
    printf("Ingrese el valor de la temperatura: ");
    scanf("%f", &temperatura);

    //Calcular la masa
    masa = (presion * volumen)/(0.37 * (temperatura + 460));

    //Mostrar valor de la masa
    printf("Masa = %.3f", masa);
} //Main

