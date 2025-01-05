// Author: reDragonCoder
//Calcular la suma y el promedio de un array de números

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
  int numeros[10], suma = 0;
  float promedio;
  for (int i = 0; i < 10; i++) {
    printf("Introduce un número: ");
    scanf("%d", &numeros[i]);
    suma += numeros[i];
  }
  promedio = suma / 10;
  printf("La suma es %d\n", suma);
  printf("El promedio es %.2f\n", promedio);
  return 0;
}