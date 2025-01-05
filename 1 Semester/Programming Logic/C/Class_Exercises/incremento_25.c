// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float salario_anterior, incremento, salario_nuevo;
    printf("ingrese su salario anterior: ");
    scanf("%f", &salario_anterior);
    incremento = salario_anterior * 0.25;
    salario_nuevo = salario_anterior + incremento;
    printf("Su nuevo salario es $%f", salario_nuevo);
    return 0;
}