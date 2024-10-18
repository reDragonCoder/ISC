// Author: reDragonCoder
//Ejercicio 6 - “Un elefante se balanceaba…”
//Escribe un programa que inicie mostrando en pantalla la letra de “Un elefante se balanceaba” 
//iniciando con el número 1, después pregunta al usuario cuantos elefantes más se balancearán 
//y debe responder un número más al mostrado. En caso de ingresar un número diferente pedirle 
//que intente de nuevo y repetir el ciclo hasta tener 10 elefantes.
//Tomar en cuenta cuando el texto muestra un solo elefante y varios elefantes.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //declarar variables
    int num_elefantes, contador=1;
    printf("%d elefante se balanceaba... \n", contador);
    //repetir mientras el contador sea menor a 10
    do{
        //preguntar el numero de elefantes
        printf("Cuantos elefantes mas se balancearan?: ");
        scanf("%d", &num_elefantes);
        //si el numero de elefantes ingresado coincide con el contador+1, seguir
        if(num_elefantes==(contador+1)){
            printf("%d elefantes se balanceaban... \n", num_elefantes);
            contador++;
        }
        //si no, intentar de nuevo
        else{
            printf("Intente de nuevo \n");
        }
    }while(contador<10);
    return 0;
}