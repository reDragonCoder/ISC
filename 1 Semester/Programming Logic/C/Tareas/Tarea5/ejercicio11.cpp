// Author: reDragonCoder
/*Escribir un programa que muestre la tabla de multiplicar de cualquier numero de dos dígitos. */

//LIBRERIAS
#include <stdio.h>
#include <math.h>

//MAIN
int main(){
    int num=0, digits=0, auxNum=0;
    
    //ask fo the number
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
        for (int i=1; i<=10; i++) {//do the table
            auxNum=num*i;//mult num by increasion i
            printf("%d  ", auxNum);//show num
            printf("\n");
        }
        
    }//if
    else{//if the number cannot be reversed (a.k.a it lit only has ONE digit)
        if (digits<=1) {
            printf("Sorry! Please indicate a with more than one (1) digit.\n");
        }//if one
    }//else too small
    return 0;
}//main
