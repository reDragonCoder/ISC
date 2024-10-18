// Author: reDragonCoder
//EJERCICIO 3: Las raíces reales de la expresión ax2 +bx+c=0 se obtienen a través de la fórmula general.
//Calcular las raíces reales, de ser posible, de una ecuación de segundo grado. Datos: A, B, C con A != 0

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    //Declarar las variables
    float a, b, c, dis=0, x1=0, x2=0;
    //Pedir datos al usuario
    printf("Ingrese el valor de a: ");
    scanf("%f", &a);
    printf("Ingrese el valor de b: ");
    scanf("%f", &b);
    printf("Ingrese el valor de c: ");
    scanf("%f", &c);
    //Realizar el calulo del discriminante de la ecuacion
    dis=pow(b,2)-4*a*c;
    //Evaluar dis>0
    if(dis>0){
        //Calcular las raices reales y mostrarlas
        x1=((-b)+pow(dis,0.5))/(2*a);
        x2=((-b)-pow(dis,0.5))/(2*a);
        printf("Las raíces reales son: %.2f, %.2f", x1, x2);
    }
    else{
        printf("Las raices reales no existen");
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes
//Se agregó un else para avisar que las raices reales con los valores ingresados no existen