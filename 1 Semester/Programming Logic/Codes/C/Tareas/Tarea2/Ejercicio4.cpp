// Author: reDragonCoder
//EJERCICIO 4: dado como datos la matrícula y 5 calificaciones de un alumno; imprima 
//la matrícula, el promedio y la palabra “aprobado” si el alumno tiene un promedio mayor 
//o igual que 6, y la palabra “no aprobado” en caso contrario.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Definir las variables
    int mat;
    float cal1, cal2, cal3, cal4, cal5, prom;
    //Pedir datos al usuario
    printf("Ingrese su matricula: ");
    scanf("%d", &mat);
    printf("Ingrese la calificacion 1: ");
    scanf("%f", &cal1);
    printf("Ingrese la calificacion 2: ");
    scanf("%f", &cal2);
    printf("Ingrese la calificacion 3: ");
    scanf("%f", &cal3);
    printf("Ingrese la calificacion 4: ");
    scanf("%f", &cal4);
    printf("Ingrese la calificacion 5: ");
    scanf("%f", &cal5);
    //Calcular el promedio
    prom=(cal1+cal2+cal3+cal4+cal5)/5;
    //Evaluar si es un promedio aprobatorio o reprobatorio
    if(prom>6){
        printf("El alumno con matricula: %d y promedio: %.2f esta aprobado", mat, prom);
    }
    else{
        printf("El alumno con matricula: %d y promedio %.2f NO esta aprobado", mat, prom);
    }
    return 0;
}

//Se cambiaron las variables de mayusculas a minusculas porque no son constantes