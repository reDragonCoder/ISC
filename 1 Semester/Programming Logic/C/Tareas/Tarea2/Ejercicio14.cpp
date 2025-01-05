// Author: reDragonCoder
//Problema 2.14
//En un hospital se ha hecho un estudio sobre los pacientes registrados durante los ultimos 10 años, con el objeto de hacer una aproximacion de los costos de internacion por paciente.
//Se obtuvo un costo promedio diario segun el tipo de enfermedad que aqueja al paciente. Ademas se pudo determinar que en promedio todos los pacientes con edad entre 14 y 22 años
//implican un costo adicional del 10%. La siguiente tabla expresa los costos diarios, segun el tipo de enfermedad.
//Tipo de enfermedad
//1-------------->25
//2-------------->16
//3-------------->20
//4-------------->32

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int typeSick=0,age=0,days=0;
    float sumTotal=0;
    printf("Please introduce the type of illness the paciet suffered: ");
    scanf("%d",&typeSick);
    printf("Please introduce the age of the pacient: ");
    scanf("%d", &age);
    printf("Please introduce the days the pacient stayed in the hospital: ");
    scanf("%d", &days);
    //I am assuming that the user, probably a doctor, knows the options
    switch (typeSick) {
        case 1:
            sumTotal=days*25;
            break;
        case 2:
            sumTotal=days*16;
            break;
        case 3:
            sumTotal=days*20;
            break;
        case 4:
            sumTotal=days*32;
            break;
    }//switch
    if (age>=14&&age<=22) {
        sumTotal=sumTotal*1.10;
    }//if
    printf("Your total due is $%0.2f \n", sumTotal);
    return 0;
}//main
