// Author: reDragonCoder
//Creacion de la funcion gotoxy

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//MAIN
int main(){
    gotoxy(30,4);
    printf("*");
    return 0;
}

//FUNCIONES
void gotoxy(int x, int y){
    HANDLE Manipulador;
    COORD Coordenadas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenadas.X=x;
    Coordenadas.Y=y;
    SetConsoleCursorPosition(Manipulador,Coordenadas);
}