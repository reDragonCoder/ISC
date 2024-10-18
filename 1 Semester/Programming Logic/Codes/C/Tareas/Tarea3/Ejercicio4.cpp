// Author: reDragonCoder
//Ejercicio 4 - Lista de invitados
//Estás organizando un banquete al que quieres invitar a tus amigos. Crea un programa que 
//pida el nombre de uno de tus amigos, al hacerlo aumenta en uno una variable contadora, 
//después pregunta si quieres invitar a alguien más: si la respuesta es afirmativa entonces 
//pregunta por una persona más; en caso contrario cierra el ciclo y muestra en pantalla cuantos invitados son.

//LIBRERIAS
#include <stdio.h>
#include <string.h> 

//MAIN
int main(){
    //declarar variables
    int tamStr, contador=0;
    char invitado[50], resp='s';
    //repetir mientras la respuesta sea no
    while(resp!='n'){
        //pedir el nombre del invitado
        printf("Ingrese el nombre de su amigo: ");
        scanf("%s", invitado);
        tamStr=strlen(invitado);
        //sumar 1 al contador si la cadena invitado tiene un valor mayor a 0
        if(tamStr>0){
            contador++;
        }
        fflush(stdin);
        //preguntar si se va a agregar a alguien mas
        printf("Desea invitar a alguien mas? (s/n): ");
        scanf("%c", &resp);
    }
    //mostrar el numero de invitados
    printf("El numero de invitados es: %d", contador);
    return 0;
}
