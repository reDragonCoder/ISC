// Author: reDragonCoder
//PROBLEMA 3:
//Permita recibir del usuario a los 3 componentes numéricos que definen a una fecha (día, mes y año), para
//que finalmente le muestre en pantalla, pero bajo el siguiente formato: (día) de (nombre de mes) del (año)
//Tome en cuenta las siguientes aclaraciones:
//Limitar el año valido solamente al rango entre 1900 a 2050
//Ignorar la regla de los años bisiestos.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Pedir datos al usuario
    int dd, mm, aa;
    printf("Ingrese el dia: ");
    scanf("%d", &dd);
    printf("Ingrese el mes: ");
    scanf("%d", &mm);
    printf("Ingrese el anio: ");
    scanf("%d", &aa);

    //Evaluar el año
    if(aa>=1900 && aa<=2050){
        if(mm>=1 && mm<=12){
            if(mm==1){ //enero
                if(dd>=1 && dd<=31){
                    printf("%d de enero de %d \n", dd, aa);
                }   
                else{
                    printf("Ingrese un dia valido");
                } 
            }
            else{
                if(mm==2){ //febrero
                    if(dd>=1 && dd<=28){
                        printf("%d de febrero de %d \n", dd, aa);
                    }
                    else{
                        printf("Ingrese un dia valido");
                    }
                } 
                else{
                    if(mm==3){ //marzo
                        if(dd>=1 && dd<=31){
                            printf("%d de marzo de %d \n", dd, aa);
                        }
                        else{
                            printf("Ingrese un dia valido");
                        }
                    }
                    else{
                        if(mm==4){ //abril
                            if(dd>=1 && dd<=30){
                                printf("%d de abril de %d \n", dd, aa);
                            }
                            else{
                                printf("Ingrese un dia valido");
                            }
                        }
                        else{
                            if(mm==5){ //mayo
                                if(dd>=1 && dd<=31){
                                    printf("%d de mayo de %d \n", dd, aa);
                                }
                                else{
                                    printf("Ingrese un dia valido");
                                }
                            }
                            else{ 
                                if(mm==6){ //junio
                                    if(dd>=1 && dd<=30){
                                        printf("%d de junio de %d \n", dd, aa);
                                    }
                                    else{
                                        printf("Ingrese un dia valido");
                                    }
                                }
                                else{
                                    if(mm==7){ //julio
                                        if(dd>=1 && dd<=31){
                                            printf("%d de junio de %d \n", dd, aa);
                                        }
                                        else{
                                            printf("Ingrese un dia valido");
                                        }
                                    }
                                    else{
                                        if(mm==8){ //agosto
                                            if(dd>=1 && dd<=31){
                                                printf("%d de agosto de %d \n", dd, aa);
                                            }
                                            else{
                                                printf("Ingrese un dia valido");
                                            }
                                        }
                                        else{
                                            if(mm==9){ //septiembre
                                                if(dd>=1 && dd<=30){
                                                    printf("%d de septiembre de %d \n", dd, aa);
                                                }
                                                else{
                                                    printf("Ingrese un dia valido");
                                                }
                                            }
                                            else{
                                                if(mm==10){ //octubre
                                                    if(dd>=1 && dd<=31){
                                                        printf("%d de octubre de %d \n", dd, aa);
                                                    }
                                                    else{
                                                        printf("Ingrese un dia valido");
                                                    }
                                                }
                                                else{
                                                    if(mm==11){ //noviembre
                                                        if(dd>=1 && dd<=30){
                                                            printf("%d de noviembre de %d \n", dd, aa);
                                                        }
                                                        else{
                                                            printf("Ingrese un dia valido");
                                                        }
                                                    }
                                                    else{
                                                        if(mm==12){ //diciembre
                                                            if(dd>=1 && dd<=31){
                                                                printf("%d de diciembre de %d \n", dd, aa);
                                                            }
                                                            else{
                                                                printf("Ingrese un dia valido");
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } 
            } 
        }
        else{
            printf("Ingrese un mes valido");
        }
    }
    else{
        printf("Ingrese el anio valido");
    }
}