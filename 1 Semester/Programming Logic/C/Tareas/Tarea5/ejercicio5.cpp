// Author: reDragonCoder
/*Escribir un programa que reciba una letra y un número, y muestre en pantalla un “triángulo” formado por esa letra, que tenga como anchura inicial la que se ha indicado.*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    char letter;
    int num=0;
    
    //ask user for the letter for the triangle
    printf("Please insert the letter you would like to show: ");
    scanf("%c", &letter);
    
    //ask for the starting row of the triangle
    printf("What should be the with of the starting row of the triangle: ");
    scanf("%d", &num);
    
    //cycle s(start) does the rows
    for (int s=0; s<num; s++) {
        //the actual triangle LMAO
        //cycle i(inside) does the columbs
        for (int i=num; i>s; i--) {
            printf("%c  ", letter);
        }//i
        printf("\n");//jump the line
    }//s
    
}//main

