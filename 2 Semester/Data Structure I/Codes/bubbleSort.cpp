// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//GLOBAL CONSTANTS
#define MAX 10

//COLORS
#define RESET "\e[0m"
#define BHBLU "\e[1;94m"
#define BHCYN "\e[1;96m"
#define MAG "\e[0;35m"
#define BHMAG "\e[1;95m"
#define BHWHT "\e[1;97m"

//PROTOTYPES
void initMenu();
void bubbleSort();
void showArray(int[], int, int);
void gotoxy(int,int);
void hideCursor();

//MAIN
int main(){
    //VARIABLES
    initMenu();
    bubbleSort();
    return 0;
}

void initMenu(){
    hideCursor();
    //bubbles
    gotoxy(5,13);
    printf(BHBLU "O" RESET);
    gotoxy(16,15);
    printf(BHBLU "o" RESET);
    gotoxy(23,11);
    printf(BHBLU "O" RESET);
    gotoxy(50,3);
    printf(BHBLU "o" RESET);
    gotoxy(70,6);
    printf(BHBLU "O" RESET);
    gotoxy(17,4);
    printf(BHBLU "o" RESET);
    gotoxy(32,17);
    printf(BHBLU "O" RESET);
    gotoxy(63,11);
    printf(BHBLU "o" RESET);
    gotoxy(40,13);
    printf(BHBLU "O" RESET);
    gotoxy(34,6);
    printf(BHBLU "o" RESET);
    gotoxy(55,16);
    printf(BHBLU "O" RESET);
    gotoxy(51,8);
    printf(BHBLU "o" RESET);
    gotoxy(9,8);
    printf(BHBLU "O" RESET);
    gotoxy(2,3);
    printf(BHBLU "o" RESET);
    gotoxy(1,17);
    printf(BHBLU "O" RESET);
    gotoxy(68,18);
    printf(BHBLU "o" RESET);
    Sleep(500);
    //burst
    gotoxy(5,13);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(16,15);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(23,11);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(50,3);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(70,6);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(17,4);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(32,17);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(63,11);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(40,13);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(34,6);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(55,16);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(51,8);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(9,8);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(2,3);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(1,17);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(68,18);
    printf(BHWHT "x" RESET);
    Sleep(200);
    Sleep(1500);
    system("cls");
    gotoxy(30,8);
    //title
    printf(BHBLU "( BUBBLE SORT )" RESET);
    Sleep(2000);
    //bubbles
    gotoxy(5,13);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(16,15);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(23,11);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(50,3);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(70,6);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(17,4);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(32,17);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(63,11);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(40,13);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(34,6);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(55,16);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(51,8);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(9,8);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(2,3);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(1,17);
    printf(BHBLU "O" RESET);
    Sleep(200);
    gotoxy(68,18);
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(30,2); 
    printf(BHBLU "o" RESET);
    Sleep(200);
    gotoxy(40,1); 
    printf(BHBLU "O" RESET);
    Sleep(200);
    //burst
    gotoxy(5,13);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(16,15);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(23,11);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(50,3);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(70,6);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(17,4);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(32,17);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(63,11);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(40,13);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(34,6);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(55,16);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(51,8);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(9,8);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(2,3);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(1,17);
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(68,18);
    printf(BHWHT "x" RESET);
    Sleep(200);
    gotoxy(30,2); 
    printf(BHWHT "+" RESET);
    Sleep(200);
    gotoxy(40,1); 
    printf(BHWHT "x" RESET);
    Sleep(200);
    system("cls");
    gotoxy(30,8);
    //title
    printf(BHBLU "( BUBBLE SORT )" RESET);
    Sleep(3500);
    system("cls");
}

void bubbleSort(){
    int array[MAX];
    int temp, m;
    srand(time(NULL));
    //the initial array is filled and displayed
    printf(MAG "Initial array: ");
    printf(RESET);
    for(int i=0; i<MAX; i++){
        array[i]=rand()%11;
        printf(BHMAG "%d", array[i]);
        printf(RESET);
        printf(" ");
    }
    printf("\n\n");
    //bubble sort
    for(int i=0; i<MAX-1; i++){ 
        for(int j=0; j<MAX-i-1; j++){
            if(array[j]>array[j+1]){
                m=j+1;
                temp=array[j];
                array[j]=array[m];
                array[m]=temp;
                showArray(array, j, m);
                printf("\n");
            }
        }
    }
    printf("\n");
    //the sorted array is shown
    printf(MAG "Sorted array: ");
    printf(RESET);
    for(int i=0; i<MAX; i++){
        printf(BHMAG "%d", array[i]);
        printf(RESET);
        printf(" ");
    }
}

void showArray(int array[], int j, int m){
    for(int g=0; g<MAX; g++){
        if(g==j){
            printf(BHBLU "%d", array[g]);
            printf(RESET);
            printf(" ");
        }else if(g==m){
            printf(BHCYN "%d", array[g]);
            printf(RESET);
            printf(" ");
        }else{
            printf("%d", array[g]);
            printf(" ");
        }
    }
}

void gotoxy(int x, int y){
    HANDLE Manipulador;
    COORD Coordenadas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenadas.X=x;
    Coordenadas.Y=y;
    SetConsoleCursorPosition(Manipulador,Coordenadas);
}

void hideCursor(){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE; 
    SetConsoleCursorInfo(hcon,&cci);
}
