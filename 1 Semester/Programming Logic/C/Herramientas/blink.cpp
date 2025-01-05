// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>

//FUNCIONES
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

//MAIN
int main(){
    ShowConsoleCursor(false);
    bool estado=true;
    int contar=0;

    do{
        if(contar=5){
            system("cls");
            system("color 01");
            printf("texto");
            Sleep(500);
            if(contar=10){
                system("cls");
                system("color 04");
                printf("texto");
                Sleep(500); 
                if(contar=15){
                    system("cls");
                    system("color 06");
                    printf("texto");
                    Sleep(500);
                    if(contar=20){
                        system("cls");
                        system("color 05");
                        printf("texto");
                        contar=0;
                        Sleep(500);
                    }
                }
            }
        }
    contar++;
    }while(estado=true);
    return 0;
}
