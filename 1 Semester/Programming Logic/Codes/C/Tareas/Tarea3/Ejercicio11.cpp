// Author: reDragonCoder
//Ejercicio 11 – Contraseña
//Escribir un programa que almacene la cadena de caracteres contraseña en una variable, pregunte 
//al usuario por la contraseña hasta que introduzca la contraseña correcta.

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
  //declarar las variables
  char contrasenia[] = "contrasenia", intento_contrasenia[100];
  int contador=0;
  //repetir para tres intentos de ingresar correctamente la contraseña
  for (int i=0; i<3; i++) {
    //pedir al usuario que ingrese la contraseña
    printf("Ingrese la contrasenia: ");
    scanf("%s", intento_contrasenia);
    //si las cadenas son iguales, la contraseña es correcta
    if (strcmp(intento_contrasenia, contrasenia)==0) {
      printf("Contrasenia correcta");
      break;
    }
    //si no son iguales, se suma un intento
    else{
      contador++;
      printf("Usted lleva %d intentos \n", contador);
      //si el contador llega a 3 intentos, el usuario ha agotado sus intentos
      if(contador==3){
        printf("Atencion! Todos sus intentos se han agotado");
      }
    }
  }
  return 0;
}
