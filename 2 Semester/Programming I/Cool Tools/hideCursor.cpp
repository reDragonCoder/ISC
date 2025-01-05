// Author: reDragonCoder
//Creacion de la funcion gotoxy

//LIBRARIES
#include <stdio.h>
#include <windows.h>

//PROTOTYPES
void hideCursor();

//MAIN
int main(){
    hideCursor();
    return 0;
}

//IMPLEMENTATIONS
void hideCursor(){ //Para que no se vea el cursor durante el programa
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE; //False para que no se muestre
    SetConsoleCursorInfo(hcon,&cci);
}