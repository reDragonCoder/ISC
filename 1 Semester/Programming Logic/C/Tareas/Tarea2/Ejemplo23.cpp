// Author: reDragonCoder
//Construye un diagrama de flujo tal que dado como dato la calificacion de un alumno en un examn, escriba "aprobado" en
//caso de que esa calificacion sea mayor o igual a 8 y "reprobado" en caso contrario

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float grade = 0;
    printf("Please indicate your grade on the exam: ");
    //get grade
    scanf("%f", &grade);
    //evaluate grade
    if (grade>=8) {
        printf("Approved!\n");
    }//if
    else {
        printf("Failed \n");
    }//else
    return 0;
}//main
