// Author: reDragonCoder
//Ejemplo 2.1
//Construye un diagrama de flujo tal que dado como dato la calificacion de un alumno en un examn, escriba "aprobado" en
//caso de que esa calificacion sea mayor a 8

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    float grade = 0;
    printf("Please indicate your grade on the exam: ");
    //read grade
    scanf("%f", &grade);
    if (grade>8) {
        printf("Approved!\n");
    }//if
    return 0;
}//main
