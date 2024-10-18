// Author: reDragonCoder
//Ejercicio 5 - Adivina el número secreto
//Crea un programa donde tendrás la variable numero_secreto, la cual toma un valor aleatorio entre 1 y 100. 
//Después pide a tu usuario que indique un número para intentar adivinarlo: en caso de acertar indícale cual 
//era el número secreto y cuantos intentos le tomó; en caso contrario indícale si el número ingresado es mayor 
//o menor al número secreto.

//LIBRERIAS
#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

//MAIN
int main(){
    //declarar variables
    int num_secreto=0, num_usuario, intentos=0;
    //generar numero secreto y asignarlo a la variable
    srand(time(NULL)); 
    num_secreto=rand()%100+1;
    //repetir el ciclo mientras el numero que ingresa el usuario sea diferente al numero secreto
    do{
        //pedir que adivine el numero secreto
        printf("Intente adivinar el numero secreto: ");
        scanf("%d", &num_usuario);
        //mostrar si el numero ingresado es mayor o menor y agregar un intento al contador
        if(num_usuario>num_secreto){
            printf("El numero que ingreso es mayor al numero secreto \n");
            intentos++;
        }
        else{
            printf("El numero que ingreso es menor al numero secreto \n");
            intentos++;
        }
    }while(num_usuario!=num_secreto);
    //mostrar el numero secreto y el numero de intentos realizados
    printf("Adivino el numero, el cual era %d \n", num_secreto);
    printf("Esto le tomo: %d intentos", intentos);
    return 0;
}
