// Author: reDragonCoder
//Ejemplo 2.4
//Dado como dato el sueldo de un trabajador, apliquele un aumento del 15% si su sueldo es inferior a $1000 y 12% en caso contrario.
//  Imprima el nuevo sueldo del trabajador.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float salary = 0;
    printf("Please indicate your current salary: ");
    scanf("%f", &salary);
    //evaluate salary
    if (salary<1000) {
        salary=salary*1.15;
        printf("Congrats! Your new salary is: $%0.2f\n", salary);
    }//if
    else{
        salary=salary*1.12;
        printf("Congrats! Your new salary is: $%0.2f\n", salary);
    }//else
    return 0;
}//main
