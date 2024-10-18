// Author: reDragonCoder
//Obtener un reporte de resultados a partir de un grupo de N empleados

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    int codigo, total=0, cantEmp=0, cantEmpC=0, codigoMas=0; 
    float sueldo, sumaSueldos=0, mayor; 
    char categoria;
    printf("Dame el total de personas: ");
    scanf("%d", &total);
    for(int i=1; i<=total; i++){
        printf("Codigo: ");
        scanf("%d", &codigo);
        if(codigo>=1000 && codigo<=9999){
            printf("Sueldo: ");
            scanf("%f", &sueldo);
            printf("Categoria: ");
            fflush(stdin);
            scanf("%c", &categoria);
            sumaSueldos+=sueldo;
            if(sueldo>20000){
                cantEmp++;

            }
            if(sueldo<5000 && categoria=='C'){
                cantEmpC++;
            }
            if(sueldo>mayor){
                mayor=sueldo;
                codigoMas=codigo;
            }
        }
        else{
            return 1;
        }
    }
    printf("REPORTE \n");
    printf("Suma de sueldos: $%.2f \n", sumaSueldos);
    printf("Cantidad > 20000: %d \n", cantEmp);
    printf("Cantidad < 5000 y categoria C: %d \n", cantEmpC);
    printf("El empleado %d tiene el sueldo mas alto: $%.2f", codigoMas, mayor);
    return 0;
}
