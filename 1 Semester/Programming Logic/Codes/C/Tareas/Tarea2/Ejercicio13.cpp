// Author: reDragonCoder
//Problema2.13
//Construya un diagrama de flujo tal que dado como datos la matricula de un alumno, la carrera en la que está inscrito, su semestre y su promedio; determine si el mismo es apto para pertenecer a alguna de las facultades menores que tiene la universidad. Si el alumno es aceptado teniendo en cuanta las especificaciones que se listan abajo, se debe imprimir su matricula, carrera y la palabra aceptado.
//Economia: Semestre>= 6 y promedio >=8.8
//Computacion: Semestre> 6 y promedio >8.5
//Administracion: Semestre> 5 y promedio >8.5
//Contabilidad: Semestre> 5 y promedio >8.5

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int studentID=0, semester=0;
    float gpa=0;
    char carr;
    printf("Please indicate your student ID: ");
    scanf("%d", &studentID);
    printf("Please indicate your career: \n");
    printf("Economia.............E\n");
    printf("Computacion..........C\n");
    printf("Administracion.......A\n");
    printf("Contabilidad.........O\n");
    scanf("%s", &carr);
    printf("Please indicate your semester: ");
    scanf("%d", &semester);
    printf("Please indicate your current gpa: ");
    scanf("%f", &gpa);
    switch (carr) {
        case 'E':
        case 'e':
            if (semester>=6 && gpa>=8.8) {
                printf("%d, Economia, Accepted! \n", studentID);
            }//if E
            break;
        case 'C':
        case 'c':
            if (semester>6 && gpa>8.5) {
                printf("%d, Computacion, Accepted! \n", studentID);
            }//if C
            break;
        case 'A':
        case 'a':
            if (semester>5 && gpa>8.5) {
                printf("%d, Administracion, Accepted! \n", studentID);
            }//if E
            break;
        case 'O':
        case 'o':
            if (semester>5 && gpa>8.5) {
                printf("%d, Administracion, Accepted! \n", studentID);
            }//if E
            break;
    }//switch
    return 0;
}//main
