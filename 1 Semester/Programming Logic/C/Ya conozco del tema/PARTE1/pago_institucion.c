// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float total = 0;
    for (int i = 1; i <= 15; i++)
    {
        float salario;
        printf("Ingrese el salario del profesor %d: ", i);
        scanf("%f", &salario);
        total += salario;
    }
    printf("El total que debe pagar la institucion es $%.2f", total);
    return 0;
}