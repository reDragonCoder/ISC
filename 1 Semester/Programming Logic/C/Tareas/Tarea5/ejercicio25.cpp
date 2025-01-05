// Author: reDragonCoder
/*Escribir un programa que valide la captura de un dato. */

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    char dato;
    int num=0;
    
    //ask for the data we're evaluating
    printf("Please give us a number without decimal, smaller than a 100: ");//interger
    scanf("%d", &num);
    printf("Please give us a lowercase vowel: ");//char
    fflush(stdin);//clear the in
    scanf("%c", &dato);
    
    //evaluate if the data given is actually the data asked
    if (num>0 && num<100) {
        if (dato=='a'||dato=='e'||dato=='i'||dato=='o'||dato=='u') {
            printf("Congrats you can read!! Thank you for capturing the right data \n");
        }
    }
    printf("Please Learn to read!! Try again \n");

}//main
