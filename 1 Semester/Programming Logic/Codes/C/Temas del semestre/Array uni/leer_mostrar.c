// Author: reDragonCoder
// Leer y mostrar un array de números

//LIBRERIAS
#include <stdio.h>

//MAIN
int main() {
  int numeros[10];
  for (int i = 0; i < 10; i++) {
    printf("Introduce un numero: ");
    scanf("%d", &numeros[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", numeros[i]);
  }
  return 0;
}