// Author: reDragonCoder
//Ejemplo 2.8
//Construya un diagrama de flujo tal que dado como datos la categoría y el sueldo de un trabajador, calcule el aumento correspondiente teniendo en cuenta la si­ guiente tabla. Imprima la categoría del trabajador y su nuevo sueldo.
//1 -------15%
//2 -------10%
//3 -------8%
//4 -------7%

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int ctg=0;
    float salary=0,newSalary=0;
    printf("Please indicate the category assigned to you: ");
    scanf("%d", &ctg);
    printf("Please indicate your current salary: ");
    scanf("%f",&salary);
    switch (ctg) {
        case 1:
            newSalary=salary*1.15;
            break;
        case 2:
            newSalary=salary*1.10;
            break;
        case 3:
            newSalary=salary*1.08;
            break;
        case 4:
            newSalary=salary*1.07;
            break;
        default:
            break;
    }
    printf("Congratulations! Your new salary is: $%0.2f \n", newSalary);
}//main
