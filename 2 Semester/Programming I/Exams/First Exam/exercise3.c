// Author: reDragonCoder
//Write a function that takes as a parameter an integer between 0 and 10,000. The function displays the result on 
//the screen, which is a string of characters with the number in letters.

//LIBRARIES
#include <stdio.h>
#include <string.h>

//PROTOTYPES
void numToletter(int);

//MAIN
int main(){
    //VARIABLES
    int num=0;

    printf("Enter your number: ");
    scanf("%d", &num);
    numToletter(num);

    return 0;
}

//IMPLEMENTATIONS
void numToletter(int num){
    char *unidades[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    char *diez_a_veinte[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
    char *decenas[] = {"", "", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    char *centenas[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

    // Variables para almacenar las partes del número
    int unidad, decena, centena;

    // Extraemos las unidades, decenas y centenas
    unidad=num%10;
    decena=(num/10)%10;
    centena=(num/100)%10;

    // Construimos la representación en letras
    char resultado[100]=""; // Inicializamos el resultado como cadena vacía

    if(centena>0) {
        strcat(resultado, centenas[centena]);
        strcat(resultado," ");
    }

    if(decena==1) {
        strcat(resultado, diez_a_veinte[unidad]);
    }else {
        strcat(resultado, decenas[decena]);
        strcat(resultado, " ");
        strcat(resultado, unidades[unidad]);
    }

    // Imprimimos la cadena resultante
    printf("The number %d in letters is: %s", num, resultado);
}