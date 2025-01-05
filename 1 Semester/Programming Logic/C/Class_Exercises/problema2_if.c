// Author: reDragonCoder
//PROBLEMA 2: Solicite al usuario el valor de la hora actual, en horas, minutos y segundos; así como, si es antes meridiano
//(am) o después del meridiano (pm). Luego, mostrarle la hora que sería después de transcurrir 5 segundos exactamente.

//LIBRERIAS
#include <stdio.h>

//MAIN
int main(){
    //Variables
    int hora, min, seg, meridiano;

    //Pedir datos al usuario
    printf("Ingrese la hora en formato de 12 hrs: ");
    scanf("%d", &hora);
    printf("Ingrese los minutos: ");
    scanf("%d", &min);
    printf("Ingrese los segundos: ");
    scanf("%d", &seg);
    printf("Ingrese 1 si es am o 2 si es pm: ");
    scanf("%d", &meridiano);

    //Condiciones a evaluar
    if(hora>=1 && hora <=12){
        if(min>=0 && min<=59){
            if(seg>=0 && seg<=59){
                if(meridiano==1 || meridiano==2){
                    if(meridiano==1){
                        seg+=5;
                        if(seg>59){
                            min+=1;
                            seg-=60;
                            if(min>59){
                                hora+=1;
                                min-=60;
                                if(hora>12){
                                    hora=1;
                                    printf("%d am.: %d min.: %d seg", hora, min, seg);
                                } //If hora>12
                                else{
                                    printf("%d am.: %d min.: %d seg", hora, min, seg);      
                                } //Else hora>12
                            } //If min>59
                            else{
                                printf("%d am.: %d min.: %d seg", hora, min, seg);
                            } //Else min>59
                        } //If seg>59
                        else{
                            printf("%d am.: %d min.: %d seg", hora, min, seg);
                        } //Else seg>59
                    } //If meridiano==1
                    else{
                        seg+=5;
                        if(seg>59){
                            min+=1;
                            seg=00;
                            if(min>59){
                                hora+=1;
                                min=00;
                                if(hora>12){
                                    hora=1;
                                    printf("%d am.: %d min.: %d seg", hora, min, seg);
                                } //If hora>12
                                else{
                                    printf("%d am.: %d min.: %d seg", hora, min, seg);      
                                } //Else hora>12
                            } //If min>59
                            else{
                                printf("%d am.: %d min.: %d seg", hora, min, seg);
                            } //Else min>59
                        } //If seg>59
                        else{
                            printf("%d am.: %d min.: %d seg", hora, min, seg);
                        } //Else seg>59
                    } //Else meridiano==2
                } //If meridiano 1 o 2
                else{
                    printf("Ingrese un valor del meridiano valido");
                } //Else meridiano 1 o 2
            } //If seg 1-59
            else{
                printf("Ingrese segundos validos");
            } //Else seg 1-59
        } //If min 1-59
        else{
            printf("Ingrese minutos validos");
        } //Else min 1-59
    } //If hora 1-12
    else{
        printf("Ingrese una hora valida");
    } // Else hora 1-12

    return 0;
}
