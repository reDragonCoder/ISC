// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>

//MAIN
int main(){
    float employeeSalary, newBalance;

    printf("Ingrese el sueldo: ");
    scanf("%f", &employeeSalary);
    if(employeeSalary<1450){
        newBalance=employeeSalary*1.15;
        printf("Your new balance is: $%.2f", newBalance);
    }
    else{
        printf("It has no increase");
    }
    
    return 0;
}