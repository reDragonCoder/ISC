 // Author: reDragonCoder
 //EJERCICIO 8. Obtener el área y el perímetro de las siguientes figuras: cuadrado, rectángulo y un triángulo. 
 
 //LIBRERIAS
 #include <stdio.h>

 //MAIN
 int main(){
    //Variable
    float lado_cuadrado, area_cuadrado=0, perimetro_cuadrado=0;
    float base_rectangulo, altura_rectangulo, area_rectangulo=0, perimetro_rectangulo=0;
    float base_triangulo, altura_triangulo=0, area_triangulo=0, perimetro_triangulo, lado2, lado3;

    //Pedir datos al usuario del cuadrado
    printf("Ingrese el lado del cuadrado: ");
    scanf("%f", &lado_cuadrado);
    //Pedir datos al usuario del rectangulo
    printf("Ingrese la base del rectangulo: ");
    scanf("%f", &base_rectangulo);
    printf("Ingrese la altura del rectangulo: ");
    scanf("%f", &altura_rectangulo);
    //Pedir datos al usuario del triangulo
    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base_triangulo);
    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura_triangulo);
    printf("Ingrese el valor del lado 2 (diferente a la base): ");
    scanf("%f", &lado2);
    printf("Ingrese el valor del lado 3 (diferente a la base y al lado 2): ");
    scanf("%f", &lado3);
    
    //Calculos cuadrado
    area_cuadrado=lado_cuadrado*lado_cuadrado;
    perimetro_cuadrado=4*lado_cuadrado;
    //Calculos rectangulo
    area_rectangulo=base_rectangulo*altura_rectangulo;
    perimetro_rectangulo=2*(base_rectangulo+altura_rectangulo);
    //Calculos triangulo
    area_triangulo=(base_triangulo*altura_triangulo)/2;
    perimetro_triangulo=base_triangulo+lado2+lado3;

    //Mostrar resultados
    printf("El area del cuadrado es: %.2f y el perimetro del cuadrado es: %.2f \n", area_cuadrado, perimetro_cuadrado);
    printf("El area del rectangulo es: %.2f y el perimetro del cuadrado es: %.2f \n", area_rectangulo, perimetro_rectangulo);
    printf("El area del triangulo es: %.2f y el perimetro del triangulo es: %.2f \n", area_triangulo, perimetro_triangulo);

    return 0;
 }