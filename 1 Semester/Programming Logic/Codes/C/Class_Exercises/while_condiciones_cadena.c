// Author: reDragonCoder
//Ejercicio de while y condiciones con cadenas
//Obtener la sumatoria de una serie de numeros, el valor 7 no lo debe sumar y debe preguntar si desea continuar

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
    int num, suma=0;
    char resp[]="si"; //ponerle [] si se inicializa la cadena con un valor, el programa sabe cuanto vale la cadena
    while (strcmp(resp,"no")!=0){
        printf("Ingrese un numero a sumar: ");
        scanf("%d", &num);
        if(num!=7){
            suma+=num;
        }
        printf("Continuar s/n: ");
        fflush(stdin);
        scanf("%s", resp);
    }
    printf("La suma de los numeros es: %d", suma);
    return 0;
}