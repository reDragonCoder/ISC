// Author: reDragonCoder
//PROBLEMA 4:
//Cree un programa que lee los tres lados de un triángulo, para que luego evalué a que tipo pertenece, según estas normas:
//Si los tres lados son iguales, se trata de un triángulo equilátero 
//Si los tres lados no son iguales entre sí, es un triángulo escaleno 
//Si dos de sus lados son iguales es un triángulo isósceles

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    int lado1, lado2, lado3;

    //Pedir datos al usuario
    printf("Ingrese el lado 1: ");
    scanf("%d", &lado1);
    printf("Ingrese el lado 2: ");
    scanf("%d", &lado2);
    printf("Ingrese el lado 3: ");
    scanf("%d", &lado3);

    //Condiciones a evaluar
    if(lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1){
        if(lado1==lado2 && lado2==lado3 && lado3==lado1){
            printf("Es un triangulo equilatero");
        }
        else{
            if(lado1!=lado2 && lado2!=lado3 && lado3!=lado1){
                printf("Es un triangulo escaleno");
            }
            else{
                if(lado1==lado2 || lado2==lado3 || lado3==lado1){
                    printf("El triangulo es isocsceles");
                }  
            }
        }
    }
    else{
        printf("El triangulo no existe");
    }
    return 0;
}