// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

//FUNCTIONS
void gotoxy(int x, int y){
    printf("%c[%d;%df", 0x1B, y, x);
}

void hideCursor(){
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize=100;
    cursorInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setcolor(int color){
    printf("\033[1;%dm", color);
}

//MAIN
int main(){
    int height, i, j, aux_height, remaining=0, last_line=0;
    printf("Introduce the tree height: ");
    scanf("%d", &height);

    aux_height=height;  

    height++;

    int x=40;
    int y=5;
    int stars=1;
    int starX, starY; 
    for(i=0; i<height; i++){
        gotoxy(x, y);
        for(j=0; j<stars; j++){
            if(i==0){
                starX=x; 
                starY=y; 
                printf("*");
            }
            if(i!=0){
                printf("o");
                if(i==height-1){
                    last_line=y;
                }
            }
        }
        printf("\n");
        x--;
        y++;
        stars+=2;
    }
    printf("%d \n", last_line);
    printf("%d", starY);

    gotoxy(39, y);
    printf("|||\n");
    
    height-=1;
    
    hideCursor();
    int colors[]={31, 32, 33, 34, 35, 36, 37}; 
    for(i=0; i<10; i++){
        gotoxy(starX, starY);
        setcolor(colors[i % 7]); 
        printf("*");
        Sleep(500);
        gotoxy(starX, starY);
        setcolor(colors[i % 7]); 
        printf("*");
        Sleep(500);
    }

    gotoxy(0, y+2);
    printf("\033[0m"); 

    return 0;
}


