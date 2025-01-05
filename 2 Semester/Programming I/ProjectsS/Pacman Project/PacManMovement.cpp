// Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <windows.h>
#include <conio.h> 
#include <ctype.h>
#include <time.h>
#include <dos.h> 

//PROTOTYPES
void showTable(); //Only walls table
void pacmanTable(); //Only pacman table
void pacman(); 
void gotoxy(int,int);
void hideCursor(); 
void iDontKnowWhatItDoesButItWorks(int[]);
void clearLine(int []);
void pacmanMov(int, int[]);

const int PACMANSTART_X=21;
const int PACMASTART_Y=16;
const int LINEJUMPS=30;

//MAIN
int main(){
    pacman();
}

//IMPLEMENTATIONS
void showTable(){
    char upper_left_corner=201; 
    char horizontal_wall=205; 
    char upper_right_corner=187; 
    char vertical_wall=186; 
    char lower_right_corner=188; 
    char lower_left_corner=200; 
    char power_points=248; 
    char food_points=250;
    char space=' '; 
    char alcove=196; 
    char ghost=190;

    char table[29][44]={ 
     "AxxxxxxxxxxxxxxxxxxxB AxxxxxxxxxxxxxxxxxxxB",
     "I________+__________I I__________+________I",
     "I_AxxxxxB_AxxxxxxxB_I I_AxxxxxxxB_AxxxxxB_I",
     "I_I     I_I       I_I I_I       I_I     I_I",
     "I_DxxxxxC_DxxxxxxxC_DxC_DxxxxxxxC_DxxxxxC_I",
     "I_________________________________________I",
     "I_AxxxxxB_AxB_AxxxxxxxxxxxxxB_AxB_AxxxxxB_I",
     "I_DxxxxxC_I I_DxxxxB   AxxxxC_I I_DxxxxxC_I",
     "I_________I I______I   I______I I_________I",
     "DxxxxxxxB_I DxxxxB I   I AxxxxC I_AxxxxxxxC",
     "        I_I AxxxxC DxxxC DxxxxB I_I        ",
     "        I_I I                 I I_I        ",
     "xxxxxxxxC_DxC Axxxxx***xxxxxB DxC_Dxxxxxxxx",
     "         _    I F  F  F  F  I    _         ",
     "xxxxxxxxB_AxB DxxxxxxxxxxxxxC AxB_Axxxxxxxx",
     "        I_I I                 I I_I        ",
     "        I_I I AxxxxxxxxxxxxxB I I_I        ",
     "AxxxxxxxC_DxC DxxxxB   AxxxxC DxC_DxxxxxxxB",
     "I__________________I   I__________________I",
     "I_AxxxxxB_AxxxxxxB_I   I_AxxxxxxB_AxxxxxB_I",
     "I_DxxxB I_DxxxxxxC_DxxxC_DxxxxxxC_I AxxxC_I",
     "I_____I I_________________________I I_____I",
     "DxxxB_I I_AxB_AxxxxxxxxxxxxxB_AxB_I I_AxxxC",
     "AxxxC_DxC_I I_DxxxxB   AxxxxC_I I_DxC_DxxxB",
     "I_________I I______I   I______I I_________I",
     "I_AxxxxxxxC DxxxxB_I   I_AxxxxC DxxxxxxxB_I",
     "I_DxxxxxxxxxxxxxxC_DxxxC_DxxxxxxxxxxxxxxC_I",
     "I_________________+_____+_________________I",
     "DxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxC",
    };

    for(int i=0; i<29; i++){
        for (int j=0; j<44; j++){
        	switch(table[i][j]){
        		case 'x':
        			printf("%c", horizontal_wall, table[i][j]);
        			break;
        		case 'A':
        			printf("%c", upper_left_corner, table[i][j]);
        			break;
        		case 'B':
                    printf("%c", upper_right_corner, table[i][j]);
                    break;
                case 'C':
                    printf("%c", lower_right_corner, table[i][j]);
                    break;
                case 'D':
                    printf("%c", lower_left_corner, table[i][j]);
                    break;
                case 'I':
                    printf("%c", vertical_wall, table[i][j]);
                    break;
                case '_':
                    printf("%c", power_points, table[i][j]);
                    break;
                case '+':
                    printf("%c", food_points, table[i][j]);
                    break;
                case '*':
                    printf("%c", alcove, table[i][j]);
                    break;
                case 'F':
                    printf("%c", ghost, table[i][j]);
                    break;               
        		default:
        			printf("%c", space, table[i][j]);
        			break;
			}
        }
        printf("\n");
    }
}

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void hideCursor(){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE;	//EL FALSE hace que no se vea, con TRUE se vera con el tamano que indique dwSize
    SetConsoleCursorInfo(hcon,&cci);
}

void pacman(){
    int lives=1;
    int dude[2]={PACMANSTART_X, PACMASTART_Y};
    gotoxy(dude[0], dude[1]); 
    printf("c");
    for(int i=0; i<LINEJUMPS; i++){
        printf("\n");
    }
    pacmanMov(lives, dude);
}

void pacmanMov(int lives, int dude[]){
    char key;
    iDontKnowWhatItDoesButItWorks(dude);
    hideCursor();
    while(lives!=0){
        if(kbhit){
            key=getch();
            key=tolower(key);
            switch(key){
                case 'w': 
                    clearLine(dude);
                    dude[1]--;
                    gotoxy(dude[0], dude[1]);
                    printf("<");
                    break;
                case 'a': 
                    clearLine(dude);
                    dude[0]--;
                    gotoxy(dude[0], dude[1]);
                    printf(">");
                    break;
                case 's': 
                    clearLine(dude);
                    dude[1]++;
                    gotoxy(dude[0], dude[1]);
                    printf("<");
                    break;
                case 'd': 
                    clearLine(dude);
                    dude[0]++;
                    gotoxy(dude[0], dude[1]);
                    printf("<");
                    break;
                case 27:
                    lives=0;
                    break;
            }
        }
    }
}

void iDontKnowWhatItDoesButItWorks(int dude[]){ //Maestra Liz, no nos funes, ¡gracias, thanks, arigato!
    system("cls");
    showTable();
    dude[1]--;
    gotoxy(dude[0], dude[1]);
    printf("<");
}

void clearLine(int dude[]){
   gotoxy(dude[0], dude[1]);
   printf(" "); 
}



//REGLAS IMPORTANTISIMAS
//1) Culo el que le cambie los nombres a las variables, constantes y funciones
//2) NO se vale cambiar la lógica del movimiento del pacman (ese ya está, funciona, NO LE MUEVAS)
//3) NO se borran los comentarios ÚTILES (ESTOS)
//4) NO se cambian los colores
//5) EN INGLESSSSSSSSSSS (los comentarios son la excepción)
//6) Darely y Alegría hacen los fantasmas y el no parpadeo del pacman...
//7) NO DESINFLARSE
//8) Fer y César hacen los sonidos, son expertos BOB, expertos

/*if(dude[1]==17 && (dude[0]<=tal && dude[0]=>tal)){
    NO MOVIMIENTO (CODIGO DE COLISIÓN)
}*/