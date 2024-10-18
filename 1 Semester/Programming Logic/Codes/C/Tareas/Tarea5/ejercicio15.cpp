// Author: reDragonCoder
/*Escribir un programa que dado un número entero lo descomponga dígito a dígito, lo
 vuelva a componer al revés y lo muestre. */

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    int num=0, digits=0, auxNum=0, rev=0;
    
    //ask for the number
    printf("Indicate a number: ");
    scanf("%d", &num);
    
    auxNum=num;
    
    //determine how many digits it has
    while(num>0){
        num=num/10;
        digits++;//countesr==amount of digits the number has
    }
    
    num=auxNum;

    if (digits>1){//evaluate the size...
        auxNum=0;//clear the variable
        while (num!=0) {
            auxNum=num%10;//grabs last digit
            rev= rev*10+auxNum;//adds it to the right position in the correct variable
            num=num/10;//lessens the number
        }
        printf("Your number when reversed is: %d", rev);//show rev
        printf("\n");
        
    }//if
    else{//if the number cannot be reversed (a.k.a it lit only has ONE digit)
        if (digits<=1) {
            printf("\n");
            printf("Sorry! Please indicate a with more than one (1) digit.\n");
        }//if one
    }//else too small
    return 0;
}//main
