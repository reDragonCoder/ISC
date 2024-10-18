// Author: reDragonCoder
/*Escribir un programa que calcule el factorial de un número entero positivo. Si el número introducido no está en el rango 1…20, el programa deberá indicarlo y volver a pedir otro número hasta que sea válido para realizar el cálculo.*/

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int factorial=1, num=0;
    
    //ask for number
    printf("What number in between 1 and 20 would you like to know the factorial function of: ");
    scanf("%d", &num);
    
    //evaluate if it is in the correct range
    if (num>=1 && num<=20) {
        //ok so a factorial function is fufilled when the number is multiplied by every number before
        for (int f=1; f<=num; f++) {
            factorial*=f;//the 'factorial' variable starts at 1, it gets multiplied by the ascending value of 'f'
        }
        printf("%d! is equal to %d\n", num, factorial);//'!' is the math symbol of the factorial function
    }
    if (num>20) {//this way the message won't print twice
        printf("Please insert a number that is within the range needed \n");
    }
    return 0;
}//main
