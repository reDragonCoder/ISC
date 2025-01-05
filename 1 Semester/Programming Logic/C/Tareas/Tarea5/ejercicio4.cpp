// Author: reDragonCoder
//4. Escribir un programa que muestre la primera letra de una cadena de texto. Por ejemplo
//   si la cadena es “Aguascalientes” la primer letra es una ‘A’.

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
  //declarar variables
  char texto[20];
  char primera_letra;
  //pedir una palabra al usuario
  printf("Ingrese una palabra: ");
  scanf("%s", texto);
  //guardar en la variable primera_letra lo que se guardó en la posicion 0 de lo que ingresó el usuario
  primera_letra=texto[0];
  //mostrar la primera letra de la palabra ingresada
  printf("La primera letra de la palabra es: %c", primera_letra);
  return 0;
}
