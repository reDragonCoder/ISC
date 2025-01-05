// Author: reDragonCoder
//Convierta un numero en formato decimal a romano (el número debe tener 3 dígitos)

//LIBRERIAS
#include <stdio.h>
#include <string.h>

//MAIN
int main(){
    int num, cen, dec, uni;
    char romano[15];

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if(num>=100 && num<=999){
        cen=num/100;
        num=num%100;
        dec=num/10;
        uni=num%10;
        switch(cen){
            case 1:
                strcpy(romano, "C");
            break;
            case 2:
                strcpy(romano, "CC");
            break;
            case 3:
                strcpy(romano, "CCC");
            break;
            case 4:
                strcpy(romano, "CD");
            break;
            case 5:
                strcpy(romano, "D");
            break;
            case 6:
                strcpy(romano, "DC");
            break;
            case 7:
                strcpy(romano, "DCC");
            break;
            case 8:
                strcpy(romano, "DCCC");
            break;
            case 9:
                strcpy(romano, "CM");
            break;
        }
        switch(dec){
            case 1:
                strcat(romano, "X");
            break;
            case 2:
                strcat(romano, "XX");
            break;
            case 3:
                strcat(romano, "XXX");
            break;
            case 4:
                strcat(romano, "XL");
            break;
            case 5:
                strcat(romano, "L");
            break;
            case 6:
                strcat(romano, "LX");
            break;
            case 7:
                strcat(romano, "LXX");
            break;
            case 8:
                strcat(romano, "LXXX");
            break;
            case 9:
                strcat(romano, "XC");
            break;
        }
        switch(uni){
            case 1:
                strcat(romano, "I");
            break;
            case 2:
                strcat(romano, "II");
            break;
            case 3:
                strcat(romano, "III");
            break;
            case 4:
                strcat(romano, "IV");
            break;
            case 5:
                strcat(romano, "V");
            break;
            case 6:
                strcat(romano, "VI");
            break;
            case 7:
                strcat(romano, "VII");
            break;
            case 8:
                strcat(romano, "VIII");
            break;
            case 9:
                strcat(romano, "IX");
            break;
        }
        printf("El numero romano es: %s", romano);
    }
    else{
        printf("Numero no valido");
    }
    return 0;
}